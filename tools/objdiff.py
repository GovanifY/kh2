#!/usr/bin/env python3
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import shlex
import subprocess
import zlib
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Sequence

from common import (
    CTORS_FOFF,
    CTORS_SIZE,
    CTORS_VADDR,
    DTORS_FOFF,
    DTORS_SIZE,
    DTORS_VADDR,
    GENERATED_DIR,
    MAIN_FOFF,
    MAIN_SIZE,
    MAIN_VADDR,
    PS2_DOCKER_IMAGE,
    PS2_DOCKER_PREPARE,
    REGISTRY_TSV,
    ROOT,
    SLPM_PATH,
    TARGET_PATH,
    addr_to_file_offset,
    load_boundaries,
    load_elf_image,
    parse_hex_addr,
    read_elf_vaddr,
    resolve_symbol_name,
    src_to_obj,
)

OBJDIFF_DIR = ROOT / "out" / "objdiff"
BASE_BIN_DIR = OBJDIFF_DIR / "base_bin"
TARGET_BIN_DIR = OBJDIFF_DIR / "target_bin"
BASE_ASM_DIR = OBJDIFF_DIR / "base_asm"
TARGET_ASM_DIR = OBJDIFF_DIR / "target_asm"
BASE_OBJ_DIR = OBJDIFF_DIR / "base_obj"
TARGET_OBJ_DIR = OBJDIFF_DIR / "target_obj"
SCRATCH_CTX_DIR = OBJDIFF_DIR / "ctx"
CONFIG_PATH = ROOT / "objdiff.json"
REPORT_PATH = OBJDIFF_DIR / "report.json"
TEXT_LAYOUT_CACHE_PATH = OBJDIFF_DIR / "text_layout_cache.json"
UNITS_CACHE_PATH = OBJDIFF_DIR / "units_cache.json"
DEFAULT_IMAGE = "kh2-local/ps2-compiler:3.2-ee-040921-objdiff"
SCRATCH_PLATFORM = "ps2"
SCRATCH_COMPILER = "ee-gcc3.2-040921"
SCRATCH_CFLAGS = "-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections"
SCRATCH_PREPROCESS_FLAGS = "-E -P -dD -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections"
UNITS_CACHE_VERSION = 3
@dataclass(frozen=True)
class LayoutRow:
    addr: int
    mode: str
    source: str


@dataclass(frozen=True)
class UnitSpec:
    name: str
    source_path: str
    complete: bool
    categories: List[str]
    funcs: List[tuple[int, str, int]]


@dataclass(frozen=True)
class TextSection:
    name: str
    size: int


@dataclass(frozen=True)
class TextSymbol:
    section_name: str
    offset: int
    size: int
    name: str



def run_in_ps2(cmd: str) -> None:
    subprocess.run([str(PS2_DOCKER_PREPARE)], check=True)
    full = [
        "docker", "run", "--rm",
        "--platform", "linux/amd64",
        "-u", f"{os.getuid()}:{os.getgid()}",
        "-v", f"{ROOT}:/work",
        "-v", "/tmp:/tmp",
        "-w", "/work",
        os.environ.get("KH2_PS2_IMAGE", DEFAULT_IMAGE),
        "bash", "-lc", cmd,
    ]
    subprocess.run(full, check=True)


def run_in_ps2_capture(cmd: str) -> str:
    subprocess.run([str(PS2_DOCKER_PREPARE)], check=True)
    full = [
        "docker", "run", "--rm",
        "--platform", "linux/amd64",
        "-u", f"{os.getuid()}:{os.getgid()}",
        "-v", f"{ROOT}:/work",
        "-v", "/tmp:/tmp",
        "-w", "/work",
        os.environ.get("KH2_PS2_IMAGE", DEFAULT_IMAGE),
        "bash", "-lc", cmd,
    ]
    return subprocess.run(full, check=True, capture_output=True, text=True).stdout



def load_layout_status_rows() -> List[LayoutRow]:
    path = GENERATED_DIR / "layout_status.tsv"
    if not path.exists():
        return []
    rows: List[LayoutRow] = []
    with path.open(newline="") as f:
        reader = csv.DictReader(f, delimiter="\t")
        for row in reader:
            addr_text = (row.get("addr") or "").strip()
            if not addr_text:
                continue
            rows.append(
                LayoutRow(
                    addr=parse_hex_addr(addr_text),
                    mode=(row.get("mode") or "").strip().lower(),
                    source=(row.get("source") or "").strip(),
                )
            )
    rows.sort(key=lambda r: r.addr)
    return rows



def load_layout_status_cxx_sources() -> Dict[int, str]:
    return {r.addr: r.source for r in load_layout_status_rows() if r.mode == "cxx"}



def load_layout_status_cxx_addrs() -> set[int]:
    return {r.addr for r in load_layout_status_rows() if r.mode == "cxx"}



def load_registry_symbols_quick() -> dict[int, str]:
    out: dict[int, str] = {}
    if not REGISTRY_TSV.exists():
        return out
    for line in REGISTRY_TSV.read_text().splitlines():
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        parts = s.split("\t")
        if len(parts) != 2:
            continue
        sym = parts[0].strip()
        addr_text = parts[1].strip()
        if not sym or not addr_text:
            continue
        try:
            out[parse_hex_addr(addr_text)] = resolve_symbol_name(sym)
        except ValueError:
            continue
    return out



def sanitize_unit_name(source: str) -> str:
    s = source.replace("src/", "", 1)
    return s.replace("/", "__")


def _write_bytes_if_changed(path: Path, data: bytes) -> bool:
    if path.exists() and path.read_bytes() == data:
        return False
    path.write_bytes(data)
    return True


def _write_text_if_changed(path: Path, data: str) -> bool:
    if path.exists() and path.read_text() == data:
        return False
    path.write_text(data)
    return True


def _obj_stamp(path: Path) -> list[int] | None:
    if not path.exists():
        return None
    st = path.stat()
    return [st.st_mtime_ns, st.st_size]


def _load_text_layout_cache() -> dict:
    if not TEXT_LAYOUT_CACHE_PATH.exists():
        return {}
    try:
        return json.loads(TEXT_LAYOUT_CACHE_PATH.read_text())
    except Exception:
        return {}


def _save_text_layout_cache(data: dict) -> None:
    TEXT_LAYOUT_CACHE_PATH.parent.mkdir(parents=True, exist_ok=True)
    TEXT_LAYOUT_CACHE_PATH.write_text(json.dumps(data, sort_keys=True))


def _store_text_layout_cache_entry(
    cache: dict,
    rel: str,
    obj_path: Path,
    sections: list[TextSection],
    symbols: list[TextSymbol],
) -> None:
    cache[rel] = {
        "stamp": _obj_stamp(obj_path),
        "sections": [{"name": section.name, "size": section.size} for section in sections],
        "symbols": [
            {
                "section_name": symbol.section_name,
                "offset": symbol.offset,
                "size": symbol.size,
                "name": symbol.name,
            }
            for symbol in symbols
        ],
    }


def _load_units_cache() -> dict:
    if not UNITS_CACHE_PATH.exists():
        return {}
    try:
        return json.loads(UNITS_CACHE_PATH.read_text())
    except Exception:
        return {}


def _save_units_cache(data: dict) -> None:
    UNITS_CACHE_PATH.parent.mkdir(parents=True, exist_ok=True)
    UNITS_CACHE_PATH.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")


def _config_cache_state() -> dict[str, list[int] | None]:
    return {
        "layout_status": _obj_stamp(GENERATED_DIR / "layout_status.tsv"),
        "registry": _obj_stamp(REGISTRY_TSV),
    }


def scratch_ctx_path_for_source(source: str) -> Path:
    return SCRATCH_CTX_DIR / f"{source}.ctx"


def source_from_scratch_ctx_path(path_text: str) -> str | None:
    rel = path_text.replace("\\", "/")
    prefix = SCRATCH_CTX_DIR.relative_to(ROOT).as_posix() + "/"
    if not rel.startswith(prefix) or not rel.endswith(".ctx"):
        return None
    return rel[len(prefix):-4]


def build_scratch_context(source: str) -> int:
    src_path = ROOT / source
    if not src_path.exists():
        raise FileNotFoundError(f"missing source file for scratch context: {source}")
    ctx_path = scratch_ctx_path_for_source(source)
    ctx_path.parent.mkdir(parents=True, exist_ok=True)
    ctx_rel = ctx_path.relative_to(ROOT).as_posix()
    src_rel = src_path.relative_to(ROOT).as_posix()
    cmd = (
        f"/opt/ps2/gcc/bin/ee-g++ {SCRATCH_PREPROCESS_FLAGS} "
        f"{shlex.quote(src_rel)} > {shlex.quote(ctx_rel)}"
    )
    run_in_ps2(cmd)
    print(f"Wrote {ctx_path}")
    return 0


def render_group_asm(bin_path: Path, entries: List[tuple[str, int]], split_sections: bool = False) -> str:
    lines = [] if split_sections else [".text\n"]
    offset = 0
    rel_bin = bin_path.relative_to(ROOT).as_posix()
    for sym, size in entries:
        if split_sections:
            lines.append(f'.section .text.{sym}, "ax", @progbits\n')
            lines.append(".align 3\n")
        lines.append(f".globl {sym}\n")
        lines.append(f".type {sym}, @function\n")
        lines.append(f".ent {sym}\n")
        lines.append(f"{sym}:\n")
        lines.append(f'.incbin "{rel_bin}", {offset}, {size}\n')
        lines.append(f".end {sym}\n")
        offset += size
    return "".join(lines)


OBJDUMP_FUNC_SYMBOL_RE = re.compile(
    r"^\s*([0-9a-fA-F]+)\s+g\s+F\s+(\S+)\s+([0-9a-fA-F]+)\s+(\S+)\s*$"
)
FUNC_LABEL_RE = re.compile(r"^func_[0-9a-fA-F]{8}$")


def _parse_objdump_sections(text: str) -> list[TextSection]:
    sections: list[TextSection] = []
    for line in text.splitlines():
        parts = line.split()
        if len(parts) < 7 or not parts[0].isdigit():
            continue
        name = parts[1]
        if not name.startswith(".text"):
            continue
        try:
            size = int(parts[2], 16)
        except ValueError:
            continue
        if size <= 0:
            continue
        sections.append(TextSection(name=name, size=size))
    return sections


def _parse_objdump_symbols(text: str) -> list[TextSymbol]:
    symbols: list[TextSymbol] = []
    for line in text.splitlines():
        m = OBJDUMP_FUNC_SYMBOL_RE.match(line)
        if m is None:
            continue
        section_name = m.group(2)
        if not section_name.startswith(".text"):
            continue
        symbols.append(
            TextSymbol(
                section_name=section_name,
                offset=int(m.group(1), 16),
                size=int(m.group(3), 16),
                name=m.group(4),
            )
        )
    return symbols


def load_text_layouts(obj_paths: Sequence[Path]) -> dict[str, tuple[list[TextSection], list[TextSymbol]]]:
    rel_paths: list[str] = []
    path_by_rel: dict[str, Path] = {}
    for obj_path in obj_paths:
        if not obj_path.exists():
            continue
        try:
            rel = obj_path.relative_to(ROOT).as_posix()
        except ValueError:
            rel = obj_path.as_posix()
        rel_paths.append(rel)
        path_by_rel[rel] = obj_path
    rel_paths = sorted(set(rel_paths))
    if not rel_paths:
        return {}

    cache = _load_text_layout_cache()
    out_layouts: dict[str, tuple[list[TextSection], list[TextSymbol]]] = {}
    missing: list[str] = []
    cache_changed = False
    for rel in rel_paths:
        stamp = _obj_stamp(path_by_rel[rel])
        entry = cache.get(rel)
        if (
            entry is not None
            and entry.get("stamp") == stamp
            and isinstance(entry.get("sections"), list)
            and isinstance(entry.get("symbols"), list)
        ):
            out_layouts[rel] = (
                [TextSection(**section) for section in entry["sections"]],
                [TextSymbol(**symbol) for symbol in entry["symbols"]],
            )
        else:
            missing.append(rel)

    if not missing:
        return out_layouts

    input_path = OBJDIFF_DIR / "text_layout_paths.json"
    input_path.write_text(json.dumps(missing))
    input_rel = input_path.relative_to(ROOT).as_posix()
    cmd = f"""python3 - <<'PY'
import json
import subprocess
from pathlib import Path

paths = json.loads(Path("/work/{input_rel}").read_text())
for rel in paths:
    print(f"===OBJ {{rel}}")
    proc = subprocess.run(
        ["/opt/ps2/gcc/bin/ee-objdump", "-h", rel],
        check=True,
        capture_output=True,
        text=True,
    )
    print(proc.stdout, end="")
    print(f"===SYM {{rel}}")
    proc = subprocess.run(
        ["/opt/ps2/gcc/bin/ee-objdump", "-t", rel],
        check=True,
        capture_output=True,
        text=True,
    )
    print(proc.stdout, end="")
    print(f"===END {{rel}}")
PY"""
    out = run_in_ps2_capture(cmd)

    by_path: dict[str, dict[str, list[str]]] = {}
    current_mode: str | None = None
    current_path: str | None = None
    for line in out.splitlines():
        if line.startswith("===OBJ "):
            current_mode = "obj"
            current_path = line[7:]
            by_path.setdefault(current_path, {"obj": [], "sym": []})
            continue
        if line.startswith("===SYM "):
            current_mode = "sym"
            current_path = line[7:]
            by_path.setdefault(current_path, {"obj": [], "sym": []})
            continue
        if line.startswith("===END "):
            current_mode = None
            current_path = None
            continue
        if current_mode is not None and current_path is not None:
            by_path[current_path][current_mode].append(line)

    for rel in missing:
        parts = by_path.get(rel)
        if not parts:
            out_layouts[rel] = ([], [])
            cache[rel] = {"stamp": _obj_stamp(path_by_rel[rel]), "sections": [], "symbols": []}
            cache_changed = True
            continue
        sections = _parse_objdump_sections("\n".join(parts["obj"]))
        symbols = _parse_objdump_symbols("\n".join(parts["sym"]))
        out_layouts[rel] = (sections, symbols)
        _store_text_layout_cache_entry(cache, rel, path_by_rel[rel], sections, symbols)
        cache_changed = True
    if cache_changed:
        _save_text_layout_cache(cache)
    return out_layouts


def render_layout_asm(
    bin_path: Path,
    funcs: List[tuple[int, str, int]],
    layout: tuple[list[TextSection], list[TextSymbol]] | None,
) -> str | None:
    if layout is None:
        return None
    sections, symbols = layout
    if not sections or not symbols:
        return None

    by_section: dict[str, dict[int, list[TextSymbol]]] = defaultdict(lambda: defaultdict(list))
    for sym in symbols:
        by_section[sym.section_name][sym.offset].append(sym)

    sized_groups: list[tuple[tuple[str, int], list[TextSymbol]]] = []
    for section in sections:
        offsets = by_section.get(section.name)
        if not offsets:
            continue
        for offset in sorted(offsets):
            vals = offsets[offset]
            if max(sym.size for sym in vals) <= 0:
                continue
            sized_groups.append(((section.name, offset), vals))
    if len(sized_groups) != len(funcs):
        return None

    rel_bin = bin_path.relative_to(ROOT).as_posix()
    lines: list[str] = []
    bin_off = 0
    by_section: dict[str, list[tuple[int, int, int, list[TextSymbol]]]] = defaultdict(list)
    for ((section_name, offset), vals), (_addr, _sym, expected_size) in zip(sized_groups, funcs):
        layout_size = max(sym.size for sym in vals)
        if expected_size > layout_size:
            return None
        by_section[section_name].append((offset, layout_size, expected_size, vals))

    for section in sections:
        lines.append(".text\n" if section.name == ".text" else f'.section {section.name}, "ax", @progbits\n')
        cursor = 0
        for offset, layout_size, data_size, vals in by_section.get(section.name, []):
            if offset > cursor:
                lines.append(f".space {offset - cursor}\n")
                cursor = offset
            primary = next((sym.name for sym in vals if FUNC_LABEL_RE.fullmatch(sym.name)), vals[0].name)
            for sym in vals:
                lines.append(f".globl {sym.name}\n")
                lines.append(f".type {sym.name}, @function\n")
            lines.append(f".ent {primary}\n")
            for sym in vals:
                lines.append(f"{sym.name}:\n")
            lines.append(f'.incbin "{rel_bin}", {bin_off}, {data_size}\n')
            if layout_size > data_size:
                lines.append(f".space {layout_size - data_size}\n")
            lines.append(f".end {primary}\n")
            bin_off += data_size
            cursor += layout_size
        if section.size > cursor:
            lines.append(f".space {section.size - cursor}\n")
    if bin_off != sum(size for _addr, _sym, size in funcs):
        return None
    return "".join(lines)


def choose_group_entry_symbols(
    funcs: List[tuple[int, str, int]],
    layout: tuple[list[TextSection], list[TextSymbol]] | None,
) -> List[tuple[str, int]]:
    entries = [(sym, size) for _addr, sym, size in funcs]
    if layout is None:
        return entries
    _sections, symbols = layout
    if not symbols:
        return entries

    out: List[tuple[str, int]] = []
    by_section: dict[str, dict[int, list[TextSymbol]]] = defaultdict(lambda: defaultdict(list))
    for sym in symbols:
        by_section[sym.section_name][sym.offset].append(sym)
    sized_groups: list[list[TextSymbol]] = []
    for section in _sections:
        offsets = by_section.get(section.name)
        if not offsets:
            continue
        for offset in sorted(offsets):
            vals = offsets[offset]
            if max(sym.size for sym in vals) <= 0:
                continue
            sized_groups.append(vals)

    for addr, spec_sym, size in funcs:
        token = f"func_{addr:08x}"
        match: list[TextSymbol] | None = None
        for vals in sized_groups:
            if max(sym.size for sym in vals) != size:
                continue
            names = {sym.name for sym in vals}
            if spec_sym in names:
                match = vals
                break
        if match is None:
            for vals in sized_groups:
                if max(sym.size for sym in vals) != size:
                    continue
                if any(token in sym.name for sym in vals):
                    match = vals
                    break
        if match is None:
            out.append((spec_sym, size))
            continue
        out_sym = next((sym.name for sym in match if not FUNC_LABEL_RE.fullmatch(sym.name)), match[0].name)
        out.append((out_sym, size))
    return out



def make_unit_specs() -> List[UnitSpec]:
    boundaries = {b.addr: b for b in load_boundaries()}
    rows = load_layout_status_rows()
    symbol_map = load_registry_symbols_quick()
    specs: List[UnitSpec] = []
    by_source: Dict[str, List[tuple[int, str, int]]] = defaultdict(list)
    asm_run: List[tuple[int, str, int]] = []
    asm_run_start: Optional[int] = None

    def flush_asm_run() -> None:
        nonlocal asm_run, asm_run_start
        if not asm_run:
            return
        start = asm_run_start if asm_run_start is not None else asm_run[0][0]
        name = f"unmatched/asm_segment_{start:08x}.s"
        specs.append(
            UnitSpec(
                name=name,
                source_path=name,
                complete=False,
                categories=["all", "undecompiled", "asm"],
                funcs=list(asm_run),
            )
        )
        asm_run = []
        asm_run_start = None

    for row in rows:
        b = boundaries.get(row.addr)
        if b is None:
            continue
        sym = symbol_map.get(row.addr, f"func_{row.addr:08x}")
        entry = (row.addr, sym, b.size)
        if row.source:
            flush_asm_run()
            by_source[row.source].append(entry)
        else:
            if asm_run_start is None:
                asm_run_start = row.addr
            asm_run.append(entry)
    flush_asm_run()

    for source, funcs in sorted(by_source.items()):
        categories = ["all", "decompiled", "anon" if "/anon/" in source else "named"]
        specs.append(UnitSpec(source, source, True, categories, funcs))

    specs.sort(key=lambda s: s.funcs[0][0] if s.funcs else 0)
    return specs


def unit_artifacts_exist(unit: dict) -> bool:
    target_path = ROOT / unit["target_path"]
    base_path = ROOT / unit["base_path"]
    return target_path.exists() and base_path.exists()


def unit_cache_key(target_blob: bytes, selected_count: int, obj_stamp: list[int] | None) -> dict:
    return {
        "version": UNITS_CACHE_VERSION,
        "target_size": len(target_blob),
        "target_crc32": zlib.crc32(target_blob),
        "selected_count": selected_count,
        "obj_stamp": obj_stamp,
    }



def build_units(
    elf_path: Path = TARGET_PATH,
    requested_obj: Optional[str] = None,
    materialize: bool = True,
) -> dict:
    elf_image = load_elf_image(elf_path)
    if elf_image is None:
        raise FileNotFoundError(f"missing or invalid ELF: {elf_path}")
    if not SLPM_PATH.exists():
        raise FileNotFoundError(f"missing original binary: {SLPM_PATH}")
    orig = SLPM_PATH.read_bytes()
    requested_obj = requested_obj.replace("\\", "/") if requested_obj else None

    if materialize:
        for p in [BASE_BIN_DIR, TARGET_BIN_DIR, BASE_ASM_DIR, TARGET_ASM_DIR, BASE_OBJ_DIR, TARGET_OBJ_DIR]:
            p.mkdir(parents=True, exist_ok=True)

    units = []
    assemble_cmds: List[str] = []
    matched_requested = requested_obj is None
    specs = make_unit_specs()
    if requested_obj:
        filtered_specs: List[UnitSpec] = []
        for spec in specs:
            unit_name = sanitize_unit_name(spec.name)
            base_obj_rel = (BASE_OBJ_DIR / f"{unit_name}.o").relative_to(ROOT).as_posix()
            current_obj_rel = (TARGET_OBJ_DIR / f"{unit_name}.o").relative_to(ROOT).as_posix()
            if requested_obj in (base_obj_rel, current_obj_rel):
                filtered_specs.append(spec)
        specs = filtered_specs
    prev_units_by_name: Dict[str, dict] = {}
    cached_unit_keys: Dict[str, dict] = {}
    new_unit_keys: Dict[str, dict] = {}
    if materialize and requested_obj is None:
        units_cache = _load_units_cache()
        if units_cache.get("state") == _config_cache_state() and CONFIG_PATH.exists():
            try:
                config = json.loads(CONFIG_PATH.read_text())
                prev_units_by_name = {
                    unit["name"]: unit
                    for unit in config.get("units", [])
                    if isinstance(unit, dict) and isinstance(unit.get("name"), str)
                }
            except Exception:
                prev_units_by_name = {}
            cached_unit_keys = {
                str(name): key
                for name, key in units_cache.get("unit_keys", {}).items()
            }
    obj_layouts = {}
    if materialize:
        obj_layouts = load_text_layouts(
            ROOT / src_to_obj(spec.source_path)
            for spec in specs
            if not spec.source_path.startswith("unmatched/")
        )
    for spec in specs:
        is_unmatched = spec.source_path.startswith("unmatched/")
        unit_name = sanitize_unit_name(spec.name)
        base_bin = BASE_BIN_DIR / f"{unit_name}.bin"
        target_bin = TARGET_BIN_DIR / f"{unit_name}.bin"
        base_asm = BASE_ASM_DIR / f"{unit_name}.s"
        target_asm = TARGET_ASM_DIR / f"{unit_name}.s"
        base_obj = BASE_OBJ_DIR / f"{unit_name}.o"
        target_obj = TARGET_OBJ_DIR / f"{unit_name}.o"
        base_obj_rel = base_obj.relative_to(ROOT).as_posix()
        target_obj_rel = target_obj.relative_to(ROOT).as_posix()
        layout_obj_rel = None if is_unmatched else src_to_obj(spec.source_path)
        current_obj_rel = target_obj_rel
        if requested_obj and requested_obj not in (base_obj_rel, current_obj_rel):
            continue
        matched_requested = True
        obj_layout = obj_layouts.get(layout_obj_rel) if layout_obj_rel else None

        base_blob = bytearray()
        target_blob = bytearray()
        selected_funcs: List[tuple[int, str, int]] = []
        asm_entries: List[tuple[str, int]] = []
        for addr, sym, size in spec.funcs:
            off = addr_to_file_offset(addr)
            base_bytes = orig[off:off + size]
            target_bytes = read_elf_vaddr(elf_image, addr, size)
            if target_bytes is None or len(target_bytes) != size:
                continue
            base_blob.extend(base_bytes)
            target_blob.extend(target_bytes)
            selected_funcs.append((addr, sym, size))
            asm_entries.append((sym, size))
        if not asm_entries:
            continue
        base_blob_bytes = bytes(base_blob)
        target_blob_bytes = bytes(target_blob)
        obj_stamp = None
        if layout_obj_rel is not None:
            st = _obj_stamp(ROOT / layout_obj_rel)
            if st is not None:
                obj_stamp = [st[0], st[1]]
        unit_key = unit_cache_key(target_blob_bytes, len(selected_funcs), obj_stamp)
        prev_unit = prev_units_by_name.get(spec.name)
        if (
            materialize
            and requested_obj is None
            and cached_unit_keys.get(spec.name) == unit_key
            and prev_unit is not None
            and unit_artifacts_exist(prev_unit)
        ):
            units.append(prev_unit)
            new_unit_keys[spec.name] = unit_key
            continue

        if materialize:
            base_changed = _write_bytes_if_changed(base_bin, base_blob_bytes)
            base_entries = asm_entries
            if not is_unmatched:
                base_entries = choose_group_entry_symbols(selected_funcs, obj_layout)
            base_asm_text = None if is_unmatched else render_layout_asm(base_bin, selected_funcs, obj_layout)
            if base_asm_text is None:
                base_asm_text = render_group_asm(base_bin, base_entries, split_sections=not is_unmatched)
            base_asm_changed = _write_text_if_changed(base_asm, base_asm_text)

            base_asm_rel = base_asm.relative_to(ROOT).as_posix()
            if base_changed or base_asm_changed or not base_obj.exists():
                assemble_cmds.extend([
                    f"/opt/ps2/gcc/bin/ee-as -G0 {shlex.quote(base_asm_rel)} -o {shlex.quote(base_obj_rel)}",
                    f"/opt/ps2/gcc/bin/ee-objcopy -R .mdebug -R .pdr {shlex.quote(base_obj_rel)}",
                ])

            target_changed = _write_bytes_if_changed(target_bin, target_blob_bytes)
            target_asm_text = None if is_unmatched else render_layout_asm(target_bin, selected_funcs, obj_layout)
            if target_asm_text is None:
                target_asm_text = render_group_asm(target_bin, base_entries if not is_unmatched else asm_entries, split_sections=not is_unmatched)
            target_asm_changed = _write_text_if_changed(target_asm, target_asm_text)
            target_asm_rel = target_asm.relative_to(ROOT).as_posix()
            if target_changed or target_asm_changed or not target_obj.exists():
                assemble_cmds.extend([
                    f"/opt/ps2/gcc/bin/ee-as -G0 {shlex.quote(target_asm_rel)} -o {shlex.quote(target_obj_rel)}",
                    f"/opt/ps2/gcc/bin/ee-objcopy -R .mdebug -R .pdr {shlex.quote(target_obj_rel)}",
                ])
        unit_complete = (
            spec.complete
            and len(selected_funcs) == len(spec.funcs)
            and base_blob_bytes == target_blob_bytes
        )
        unit = {
            "name": spec.name,
            "target_path": base_obj_rel,
            "base_path": current_obj_rel,
            "metadata": {
                "source_path": spec.source_path,
                "complete": unit_complete,
                "reverse_fn_order": False,
                "progress_categories": spec.categories,
                "auto_generated": is_unmatched,
            },
        }
        if not is_unmatched and Path(spec.source_path).suffix in {".c", ".cc", ".cp", ".cpp", ".cxx"}:
            scratch_ctx_rel = scratch_ctx_path_for_source(spec.source_path).relative_to(ROOT).as_posix()
            unit["scratch"] = {
                "platform": SCRATCH_PLATFORM,
                "compiler": SCRATCH_COMPILER,
                "c_flags": SCRATCH_CFLAGS,
                "ctx_path": scratch_ctx_rel,
                "build_ctx": True,
            }
        units.append(unit)
        new_unit_keys[spec.name] = unit_key

    if materialize and assemble_cmds:
        script_path = OBJDIFF_DIR / "build_units.sh"
        script_path.write_text("set -e\n" + "\n".join(assemble_cmds) + "\n")
        run_in_ps2(f"bash {shlex.quote(script_path.relative_to(ROOT).as_posix())}")
    if not matched_requested and requested_obj:
        raise FileNotFoundError(f"unknown objdiff object path: {requested_obj}")
    if materialize and requested_obj is None:
        _save_units_cache({
            "state": _config_cache_state(),
            "unit_keys": new_unit_keys,
        })
    return {"units": units}



def write_config(data: dict) -> None:
    config = {
        "min_version": "2.0.0-beta.5",
        "custom_make": "python3",
        "custom_args": ["tools/objdiff.py", "build-unit", "--elf", TARGET_PATH.relative_to(ROOT).as_posix()],
        "build_target": False,
        "options": {
            "combineTextSections": True,
        },
        "watch_patterns": ["*.c", "*.cc", "*.cp", "*.cpp", "*.cxx", "*.h", "*.hpp", "*.s", "*.S", "*.py", "*.json", "*.txt"],
        "ignore_patterns": ["out/**/*"],
        "units": data["units"],
        "progress_categories": [
            {"id": "all", "name": "All Code"},
            {"id": "decompiled", "name": "Decompiled"},
            {"id": "undecompiled", "name": "Undecompiled"},
            {"id": "named", "name": "Named Sources"},
            {"id": "anon", "name": "Anon Sources"},
            {"id": "asm", "name": "Assembly Segments"},
        ],
    }
    tmp_path = CONFIG_PATH.with_suffix(".json.tmp")
    tmp_path.write_text(json.dumps(config, indent=2) + "\n")
    tmp_path.replace(CONFIG_PATH)



def generate_report(elf_path: Path = TARGET_PATH) -> None:
    data = build_units(elf_path)
    write_config(data)
    run_in_ps2(f"objdiff-cli report generate -o {shlex.quote(REPORT_PATH.relative_to(ROOT).as_posix())}")



def _to_int(v: object) -> int:
    if isinstance(v, str) and v.isdigit():
        return int(v)
    return int(v or 0)



def _to_float(v: object) -> float:
    return float(v or 0)



def read_report() -> dict:
    if not REPORT_PATH.exists():
        raise FileNotFoundError(f"missing objdiff report: {REPORT_PATH}")
    return json.loads(REPORT_PATH.read_text())



def print_objdiff_progress() -> None:
    data = read_report()
    meas = data.get("measures", {})
    print("Objdiff Report:")
    print(
        f"  All: {_to_float(meas.get('matched_code_percent')):.2f}% matched, "
        f"{_to_float(meas.get('complete_code_percent')):.2f}% linked "
        f"({_to_int(meas.get('complete_units'))} / {_to_int(meas.get('total_units'))} files)"
    )
    print(
        f"    Code: {_to_int(meas.get('matched_code'))} / {_to_int(meas.get('total_code'))} bytes "
        f"({_to_int(meas.get('matched_functions'))} / {_to_int(meas.get('total_functions'))} functions)"
    )
    print(
        f"    Data: {_to_int(meas.get('matched_data'))} / {_to_int(meas.get('total_data'))} bytes "
        f"({_to_float(meas.get('matched_data_percent')):.2f}%)"
    )
    for category in data.get("categories", []):
        m = category.get("measures", {})
        print(
            f"  {category['name']}: {_to_float(m.get('matched_code_percent')):.2f}% matched, "
            f"{_to_float(m.get('complete_code_percent')):.2f}% linked "
            f"({_to_int(m.get('complete_units'))} / {_to_int(m.get('total_units'))} files)"
        )



def read_bytes(path: str | Path, foff: int, size: int) -> bytes:
    with Path(path).open("rb") as f:
        f.seek(foff)
        return f.read(size)



def get_elf_file_offset_for_vaddr(data: bytes, vaddr: int) -> int | None:
    from common import parse_elf_load_segments
    for seg in parse_elf_load_segments(data):
        if seg.vaddr <= vaddr < seg.vaddr + seg.filesz:
            return seg.offset + (vaddr - seg.vaddr)
    return None



def compare_region(name: str, base_vaddr: int, orig: bytes, comp: bytes, boundaries):
    n = min(len(orig), len(comp))
    if n == 0:
        return len(orig) == len(comp), {}
    orig_n = orig[:n]
    comp_n = comp[:n]
    if len(orig) == len(comp) and orig_n == comp_n:
        return True, {}
    total_diff = 0
    by_func = defaultdict(lambda: {"count": 0})
    b_idx = 0
    b_len = len(boundaries) if boundaries else 0
    for i in range(n):
        if orig_n[i] == comp_n[i]:
            continue
        total_diff += 1
        if boundaries is None:
            continue
        vaddr = base_vaddr + i
        while b_idx < b_len and vaddr >= boundaries[b_idx].end:
            b_idx += 1
        if b_idx >= b_len:
            continue
        b_cur = boundaries[b_idx]
        if vaddr < b_cur.addr:
            continue
        by_func[b_cur.addr]["count"] += 1
    matching = n - total_diff
    pct = (100.0 * matching / n) if n else 0.0
    print(f"{name}: {pct:.4f}% ({matching}/{n})")
    if len(orig) != len(comp):
        print(f"  size mismatch: orig={len(orig):#x} comp={len(comp):#x}")
    print(f"  total differing bytes: {total_diff}")
    return False, {addr: info["count"] for addr, info in by_func.items()}


def run_verify(original_elf: str, compiled_elf: str) -> int:
    boundaries = load_boundaries()
    comp_data = Path(compiled_elf).read_bytes()
    comp_main_foff = get_elf_file_offset_for_vaddr(comp_data, MAIN_VADDR)
    comp_ctors_foff = get_elf_file_offset_for_vaddr(comp_data, CTORS_VADDR)
    comp_dtors_foff = get_elf_file_offset_for_vaddr(comp_data, DTORS_VADDR)
    if comp_main_foff is None or comp_ctors_foff is None or comp_dtors_foff is None:
        print("error: compiled ELF required segments not found")
        return 1
    orig_main = read_bytes(original_elf, MAIN_FOFF, MAIN_SIZE)
    comp_main = read_bytes(compiled_elf, comp_main_foff, MAIN_SIZE)
    ok_main, _ = compare_region("main", MAIN_VADDR, orig_main, comp_main, boundaries)
    orig_ctors = read_bytes(original_elf, CTORS_FOFF, CTORS_SIZE)
    comp_ctors = read_bytes(compiled_elf, comp_ctors_foff, CTORS_SIZE)
    ok_ctors, _ = compare_region(".ctors", CTORS_VADDR, orig_ctors, comp_ctors, None)
    orig_dtors = read_bytes(original_elf, DTORS_FOFF, DTORS_SIZE)
    comp_dtors = read_bytes(compiled_elf, comp_dtors_foff, DTORS_SIZE)
    ok_dtors, _ = compare_region(".dtors", DTORS_VADDR, orig_dtors, comp_dtors, None)
    ok = ok_main and ok_ctors and ok_dtors
    if ok:
        print("MATCHED!")
        return 0
    return 1



def print_kh2_progress(elf_path: str | Path = TARGET_PATH) -> None:
    boundaries = load_boundaries()
    by_addr = {b.addr: b for b in boundaries}
    total = len(boundaries)
    cxx_addrs = load_layout_status_cxx_addrs()
    if not SLPM_PATH.exists():
        raise FileNotFoundError(f"missing {SLPM_PATH}")
    orig = SLPM_PATH.read_bytes()
    elf_image = load_elf_image(Path(elf_path))
    if elf_image is None:
        raise FileNotFoundError(f"missing or invalid linked ELF image: {elf_path}")
    matching = 0
    nonmatching = 0
    unknown = 0
    defined = 0
    for addr in sorted(cxx_addrs):
        b = by_addr.get(addr)
        if b is None:
            unknown += 1
            continue
        defined += 1
        text = read_elf_vaddr(elf_image, addr, b.size)
        if text is None:
            unknown += 1
            continue
        foff = addr_to_file_offset(addr)
        exp = orig[foff:foff + b.size]
        if len(text) == b.size and text == exp:
            matching += 1
        else:
            nonmatching += 1
    print(f"Functions total: {total}")
    print(f"Decompiled:      {defined}")
    print(f"Matching:        {matching}")
    print(f"Nonmatching:     {nonmatching}")
    if total:
        pct = (100.0 * defined) / total
        print(f"Progress:        {pct:.2f}%")
    else:
        print("Progress:        0.00%")



def cmd_progress(elf_path: Path, skip_report: bool) -> int:
    print_kh2_progress(elf_path)
    if not skip_report:
        generate_report(elf_path)
        print_objdiff_progress()
    return 0


def cmd_build_unit(elf_path: Path, obj_path: str) -> int:
    obj_path = obj_path.replace("\\", "/")
    scratch_source = source_from_scratch_ctx_path(obj_path)
    if scratch_source is not None:
        return build_scratch_context(scratch_source)
    if obj_path.startswith("out/build/"):
        run_in_ps2(f"/usr/bin/make --no-print-directory {shlex.quote(obj_path)}")
        return 0
    if CONFIG_PATH.exists():
        try:
            config = json.loads(CONFIG_PATH.read_text())
        except Exception:
            config = {}
        for unit in config.get("units", []):
            if not isinstance(unit, dict):
                continue
            if obj_path not in {unit.get("target_path"), unit.get("base_path")}:
                continue
            metadata = unit.get("metadata")
            if (
                isinstance(metadata, dict)
                and str(metadata.get("source_path", "")).startswith("src/")
                and obj_path == unit.get("base_path")
            ):
                source_path = str(metadata["source_path"])
                source_obj = src_to_obj(source_path)
                compile_cmd = (
                    f"mkdir -p {shlex.quote(str(Path(source_obj).parent))}"
                    f" && /opt/ps2/gcc/bin/ee-g++ {SCRATCH_CFLAGS}"
                    f" -c -o {shlex.quote(source_obj)} {shlex.quote(source_path)}"
                )
                refresh_cmd = (
                    f"{compile_cmd}"
                    " && if ! python3 tools/build_elf.py fast-link"
                    " --linked-elf out/linked.fast.tmp.elf"
                    f" --out-elf {shlex.quote(elf_path.as_posix())}"
                    " --full-linked-elf out/linked.tmp.elf; then"
                    " python3 tools/build_elf.py inputs-stamp --out out/generated/build_inputs.stamp"
                    " && /usr/bin/make --no-print-directory inner-all;"
                    " fi"
                    f" && echo '===OBJ {source_obj}'"
                    f" && /opt/ps2/gcc/bin/ee-objdump -h {shlex.quote(source_obj)}"
                    f" && echo '===SYM {source_obj}'"
                    f" && /opt/ps2/gcc/bin/ee-objdump -t {shlex.quote(source_obj)}"
                    f" && echo '===END {source_obj}'"
                )
                out = run_in_ps2_capture(refresh_cmd)
                obj_lines: list[str] = []
                sym_lines: list[str] = []
                mode: str | None = None
                for line in out.splitlines():
                    if line == f"===OBJ {source_obj}":
                        mode = "obj"
                        continue
                    if line == f"===SYM {source_obj}":
                        mode = "sym"
                        continue
                    if line == f"===END {source_obj}":
                        break
                    if mode == "obj":
                        obj_lines.append(line)
                    elif mode == "sym":
                        sym_lines.append(line)
                cache = _load_text_layout_cache()
                _store_text_layout_cache_entry(
                    cache,
                    source_obj,
                    ROOT / source_obj,
                    _parse_objdump_sections("\n".join(obj_lines)),
                    _parse_objdump_symbols("\n".join(sym_lines)),
                )
                _save_text_layout_cache(cache)
                break
    data = build_units(elf_path, obj_path)
    if not data["units"]:
        raise FileNotFoundError(f"no objdiff unit found for {obj_path}")
    return 0



def main() -> int:
    ap = argparse.ArgumentParser(description="KH2 objdiff + verification commands")
    sub = ap.add_subparsers(dest="cmd", required=True)

    p_cfg = sub.add_parser("config")
    p_cfg.add_argument("--elf", default=str(TARGET_PATH))

    p_rep = sub.add_parser("report")
    p_rep.add_argument("--elf", default=str(TARGET_PATH))

    p_prog = sub.add_parser("progress")
    p_prog.add_argument("--elf", default=str(TARGET_PATH))
    p_prog.add_argument("--skip-report", action="store_true")

    p_ver = sub.add_parser("verify")
    p_ver.add_argument("original_elf")
    p_ver.add_argument("compiled_elf")

    p_build = sub.add_parser("build-unit")
    p_build.add_argument("obj_path")
    p_build.add_argument("--elf", default=str(TARGET_PATH))

    args = ap.parse_args()
    if args.cmd == "config":
        data = build_units(Path(args.elf), materialize=False)
        write_config(data)
        return 0
    if args.cmd == "report":
        generate_report(Path(args.elf))
        return 0
    if args.cmd == "progress":
        return cmd_progress(Path(args.elf), args.skip_report)
    if args.cmd == "build-unit":
        return cmd_build_unit(Path(args.elf), args.obj_path)
    if args.cmd == "verify":
        return run_verify(args.original_elf, args.compiled_elf)
    raise AssertionError(f"unknown command: {args.cmd}")


if __name__ == "__main__":
    raise SystemExit(main())
