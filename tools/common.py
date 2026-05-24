from __future__ import annotations

import csv
import os
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterator, List, Optional, Sequence, Tuple

ROOT = Path(__file__).resolve().parents[1]

# Local required assets
SLPM_PATH = Path(os.environ.get("KH2_ORIG", ROOT / "SLPM_666.75"))

# Output files
OUT_DIR = ROOT / "out"
GENERATED_DIR = OUT_DIR / "generated"
BOUNDARIES_TSV = ROOT / "layout.tsv"
REGISTRY_TSV = ROOT / "functions.tsv"
TARGET_PATH = ROOT / "kh2.elf"
PS2_DOCKER_PREPARE = ROOT / "docker" / "ps2" / "prepare.sh"
PS2_DOCKER_IMAGE = os.environ.get(
    "KH2_PS2_IMAGE", "kh2-local/ps2-compiler:3.2-ee-040921-objdiff"
)

# ELF layout constants
MAIN_VADDR = 0x00100000
MAIN_FOFF = 0x001000
MAIN_SIZE = 0x27A4B4
MAIN_END = MAIN_VADDR + MAIN_SIZE

CTORS_VADDR = 0x0037A4B4
CTORS_FOFF = 0x27B4B4
CTORS_SIZE = 0x234

DTORS_VADDR = 0x0037A6E8
DTORS_FOFF = 0x27B6E8
DTORS_SIZE = 0x118

HEX_RE = re.compile(r"^(?:0x)?([0-9a-fA-F]{1,8})$")
SYM_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
CPP_IDENT_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


@dataclass(frozen=True)
class FuncRange:
    addr: int
    end: int
    size: int
    name: str


@dataclass(frozen=True)
class RegistryEntry:
    addr: int
    mode: str
    source: str
    symbol: str = ""


@dataclass(frozen=True)
class ElfLoadSegment:
    vaddr: int
    offset: int
    filesz: int


@dataclass(frozen=True)
class SymbolAlias:
    name: str
    addr: int


def _iter_noncomment_lines(path: Path) -> Iterator[str]:
    with path.open(newline="") as f:
        for line in f:
            if line.strip() and not line.lstrip().startswith("#"):
                yield line


def _iter_registry_parts(path: Path) -> Iterator[Tuple[int, List[str]]]:
    for lineno, line in enumerate(path.read_text().splitlines(), start=1):
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        yield lineno, s.split("\t")


def parse_hex_addr(text: str) -> int:
    m = HEX_RE.match(text.strip())
    if not m:
        raise ValueError(f"invalid address: {text}")
    return int(m.group(1), 16)


def run_ee_objdump(args: Sequence[str], *, cwd: Path = ROOT) -> subprocess.CompletedProcess[str]:
    if not PS2_DOCKER_PREPARE.exists():
        raise FileNotFoundError(f"missing PS2 prepare script: {PS2_DOCKER_PREPARE}")
    subprocess.run([str(PS2_DOCKER_PREPARE)], check=True)
    cmd = [
        "docker",
        "run",
        "--rm",
        "--platform",
        "linux/amd64",
        "-u",
        f"{os.getuid()}:{os.getgid()}",
        "-v",
        f"{ROOT}:/work",
        "-v",
        "/tmp:/tmp",
        "-w",
        "/work",
        PS2_DOCKER_IMAGE,
        "/opt/ps2/gcc/bin/ee-objdump",
        *args,
    ]
    return subprocess.run(cmd, check=True, capture_output=True, text=True, cwd=str(cwd))


def _parse_cpp_type(type_text: str) -> str:
    t = " ".join(type_text.strip().split())
    if not t:
        raise ValueError("empty type")
    if t == "...":
        return "z"

    is_const = False
    if t.startswith("const "):
        is_const = True
        t = t[6:].strip()

    ptrs = 0
    refs = 0
    while t.endswith("*"):
        ptrs += 1
        t = t[:-1].strip()
    while t.endswith("&"):
        refs += 1
        t = t[:-1].strip()

    base_codes = {
        "void": "v",
        "bool": "b",
        "char": "c",
        "signed char": "a",
        "unsigned char": "h",
        "short": "s",
        "unsigned short": "t",
        "int": "i",
        "unsigned int": "j",
        "long": "l",
        "unsigned long": "m",
        "long long": "x",
        "unsigned long long": "y",
        "float": "f",
        "double": "d",
    }
    base = base_codes.get(t)
    if base is None:
        parts = [p.strip() for p in t.split("::")]
        if any(not p or not CPP_IDENT_RE.match(p) for p in parts):
            raise ValueError(f"unsupported type in C++ symbol: {type_text}")
        if len(parts) == 1:
            base = f"{len(parts[0])}{parts[0]}"
        else:
            base = "N" + "".join(f"{len(p)}{p}" for p in parts) + "E"

    if is_const:
        base = "K" + base
    for _ in range(ptrs):
        base = "P" + base
    for _ in range(refs):
        base = "R" + base
    return base


def mangle_cpp_signature(sig: str) -> str:
    s = " ".join(sig.strip().split())
    if not s.endswith(")") or "(" not in s:
        raise ValueError(f"invalid C++ signature: {sig}")

    lpar = s.index("(")
    qual = s[:lpar].strip()
    args_text = s[lpar + 1 : -1].strip()
    if not qual:
        raise ValueError(f"invalid C++ signature: {sig}")

    parts = [p.strip() for p in qual.split("::")]
    if any(not p or not CPP_IDENT_RE.match(p) for p in parts):
        raise ValueError(f"invalid qualified C++ name: {qual}")

    if not args_text or args_text == "void":
        arg_codes = "v"
    else:
        arg_codes = "".join(_parse_cpp_type(a) for a in args_text.split(","))

    if len(parts) == 1:
        enc_name = f"{len(parts[0])}{parts[0]}"
        return f"_Z{enc_name}{arg_codes}"

    enc_qual = "".join(f"{len(p)}{p}" for p in parts)
    return f"_ZN{enc_qual}E{arg_codes}"


def resolve_symbol_name(name_text: str) -> str:
    s = " ".join(name_text.strip().split())
    if "(" in s and ")" in s:
        return mangle_cpp_signature(s)
    if not SYM_RE.match(s):
        raise ValueError(
            f"invalid symbol name: {name_text} "
            "(use plain C symbol or C++ signature like NS::Class::Func(int))"
        )
    return s


def load_boundaries(path: Path = BOUNDARIES_TSV) -> List[FuncRange]:
    if not path.exists():
        raise FileNotFoundError(f"missing boundaries file: {path}")
    rows: List[FuncRange] = []
    reader = csv.DictReader(_iter_noncomment_lines(path), delimiter="\t")
    for row in reader:
        addr = parse_hex_addr(row["addr"])
        end = parse_hex_addr(row["end"])
        size = int(row["size"])
        name = row.get("name", f"func_{addr:08x}").strip() or f"func_{addr:08x}"
        rows.append(FuncRange(addr=addr, end=end, size=size, name=name))
    rows.sort(key=lambda r: r.addr)

    last_end = MAIN_VADDR
    for r in rows:
        if r.addr < MAIN_VADDR or r.end > MAIN_END:
            raise ValueError(f"boundary outside main range: {r}")
        if r.size <= 0 or r.end != r.addr + r.size:
            raise ValueError(f"invalid size/end pair: {r}")
        if r.addr < last_end:
            raise ValueError(f"overlapping boundaries: {r.addr:08x}")
        last_end = r.end

    return rows


def _symbol_to_qualified_name(symbol: str) -> Optional[str]:
    if symbol.startswith("_ZN"):
        i = 3
        while i < len(symbol) and symbol[i] in "KVRr":
            i += 1
        parts: List[str] = []
        while i < len(symbol):
            if symbol[i] == "E":
                break
            if (
                symbol[i] in {"C", "D"}
                and i + 1 < len(symbol)
                and symbol[i + 1].isdigit()
            ):
                if not parts:
                    return None
                parts.append(parts[-1])
                i += 2
                continue
            j = i
            while j < len(symbol) and symbol[j].isdigit():
                j += 1
            if j == i:
                return None
            n = int(symbol[i:j])
            k = j + n
            if k > len(symbol):
                return None
            parts.append(symbol[j:k])
            i = k
        if parts:
            return "::".join(parts)
        return None

    if symbol.startswith("_Z"):
        i = 2
        j = i
        while j < len(symbol) and symbol[j].isdigit():
            j += 1
        if j > i:
            n = int(symbol[i:j])
            k = j + n
            if k <= len(symbol):
                return symbol[j:k]

    if SYM_RE.match(symbol):
        return symbol
    return None


def _iter_src_files() -> List[Path]:
    src_root = ROOT / "src"
    if not src_root.exists():
        return []
    out: List[Path] = []
    for pat in ("*.cpp", "*.c", "*.s", "*.S"):
        out.extend(src_root.rglob(pat))
    # Keep deterministic ordering and drop duplicates from overlapping globs.
    return sorted(set(out))


def _build_addr_source_fallback_map(
    src_files: List[Path], texts: Dict[Path, str]
) -> Dict[int, str]:
    # Fallback for auto-generated files where registry symbol resolution from source
    # names is ambiguous or unavailable. Supports both C/C++ definitions and asm labels.
    def_re = re.compile(
        r"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*\s+)?"
        r"func_([0-9a-fA-F]{8})\s*\([^;{}]*\)\s*"
        r"(?:const\s*)?(?:__attribute__\s*\(\([^{}]*\)\)\s*)?\{",
        re.M,
    )
    asm_re = re.compile(r"^\s*func_([0-9a-fA-F]{8})\s*:\s*(?:[#;].*)?$", re.M)
    hits: Dict[int, List[Path]] = {}
    for p in src_files:
        text = texts[p]
        if p.suffix in {".s", ".S"}:
            for m in asm_re.finditer(text):
                addr = int(m.group(1), 16)
                hits.setdefault(addr, []).append(p)
        else:
            for m in def_re.finditer(text):
                addr = int(m.group(1), 16)
                hits.setdefault(addr, []).append(p)

    out: Dict[int, str] = {}
    for addr, files in hits.items():
        uniq = sorted({f.relative_to(ROOT).as_posix() for f in files})
        if len(uniq) == 1:
            out[addr] = uniq[0]
    return out


def _build_func_name_source_map(
    src_files: List[Path], texts: Dict[Path, str]
) -> Dict[str, List[Path]]:
    def_re = re.compile(
        r"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*\s+)?"
        r"([A-Za-z_~][A-Za-z0-9_:~]*)\s*\([^;{}]*\)\s*"
        r"(?:const\s*)?(?:__attribute__\s*\(\([^{}]*\)\)\s*)?\{",
        re.M,
    )
    skip = {"if", "for", "while", "switch", "return", "sizeof"}
    hits: Dict[str, List[Path]] = {}
    for p in src_files:
        if p.suffix in {".s", ".S"}:
            continue
        for m in def_re.finditer(texts[p]):
            name = m.group(1).split("::")[-1].lstrip("~")
            if name and name not in skip:
                hits.setdefault(name, []).append(p)
    return hits


def _build_asm_alias_source_map(
    src_files: List[Path], texts: Dict[Path, str]
) -> Dict[str, List[Path]]:
    alias_re = re.compile(
        r"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*?[\s*&]+)?"
        r"([A-Za-z_][A-Za-z0-9_]*)\s*\([^;{}]*\)\s*"
        r"asm\s*\(\s*\"([^\"]+)\"\s*\)\s*;",
        re.M,
    )
    hits: Dict[str, List[Path]] = {}
    for p in src_files:
        if p.suffix in {".s", ".S"}:
            continue
        text = texts[p]
        for m in alias_re.finditer(text):
            name = m.group(1)
            symbol = m.group(2)
            body_re = re.compile(
                rf"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*?[\s*&]+)?"
                rf"{re.escape(name)}\s*\([^;{{}}]*\)\s*"
                rf"(?:const\s*)?(?:__attribute__\s*\(\([^{{}}]*\)\)\s*)?\{{",
                re.M,
            )
            if body_re.search(text, m.end()):
                hits.setdefault(symbol, []).append(p)
    return hits


_TYPE_ALIASES = {
    "u8": "unsigned char",
    "s8": "signed char",
    "u16": "unsigned short",
    "s16": "short",
    "u32": "unsigned int",
    "s32": "int",
    "u64": "unsigned long long",
    "s64": "long long",
    "f32": "float",
    "f64": "double",
}


def _canonical_param_type(param: str) -> str:
    p = " ".join(param.strip().split())
    if not p or p == "void":
        return ""
    if "=" in p:
        p = p.split("=", 1)[0].strip()
    m = re.match(r"^(.*(?:\*|&|\s))([A-Za-z_][A-Za-z0-9_]*)$", p)
    if m and "(*" not in p:
        p = m.group(1).strip()
    for src, dst in _TYPE_ALIASES.items():
        p = re.sub(rf"\b{re.escape(src)}\b", dst, p)
    return p


def _definition_matches_symbol(text: str, func_name: str, symbol: str) -> bool:
    def_re = re.compile(
        rf"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*\s+)?"
        rf"{re.escape(func_name)}\s*\(([^;{{}}]*)\)\s*"
        rf"(?:const\s*)?(?:__attribute__\s*\(\([^{{}}]*\)\)\s*)?\{{",
        re.M,
    )
    for m in def_re.finditer(text):
        params = [_canonical_param_type(p) for p in m.group(1).split(",")]
        params = [p for p in params if p]
        sig = f"{func_name}({', '.join(params)})" if params else f"{func_name}()"
        try:
            if mangle_cpp_signature(sig) == symbol:
                return True
        except ValueError:
            continue
    return False


def _resolve_source_for_symbol(
    symbol: str,
    addr: int,
    src_files: List[Path],
    texts: Dict[Path, str],
    defs_by_name: Optional[Dict[str, List[Path]]] = None,
) -> Tuple[Optional[str], str]:
    qual = _symbol_to_qualified_name(symbol)
    if not qual:
        return None, f"cannot derive source lookup key from symbol '{symbol}'"

    func_name = qual.split("::")[-1]
    if not func_name:
        return None, f"cannot derive function name from symbol '{symbol}'"

    candidates = sorted(set((defs_by_name or {}).get(func_name, [])))
    if defs_by_name is not None and not candidates:
        return None, f"no source defines '{func_name}'"
    if not candidates:
        # Match likely function definitions, not just arbitrary call sites.
        def_re = re.compile(
            rf"^\s*(?:[A-Za-z_][A-Za-z0-9_:<>,~*&\s]*\s+)?"
            rf"{re.escape(func_name)}\s*\([^;{{}}]*\)\s*"
            rf"(?:const\s*)?(?:__attribute__\s*\(\([^{{}}]*\)\)\s*)?\{{",
            re.M,
        )
        candidates = [p for p in src_files if def_re.search(texts[p])]
    if not candidates:
        return None, f"no source defines '{func_name}'"
    exact_sig = [
        p for p in candidates if _definition_matches_symbol(texts[p], func_name, symbol)
    ]
    if len(exact_sig) == 1:
        return exact_sig[0].relative_to(ROOT).as_posix(), ""
    if exact_sig:
        candidates = exact_sig

    quals = qual.split("::")[:-1]
    if quals:
        narrowed: List[Path] = []
        for p in candidates:
            t = texts[p]
            ok = True
            for q in quals:
                if (
                    f"namespace {q}" not in t
                    and f"class {q}" not in t
                    and f"struct {q}" not in t
                    and f"{q}::" not in t
                ):
                    ok = False
                    break
            if ok:
                narrowed.append(p)
        if len(narrowed) == 1:
            return narrowed[0].relative_to(ROOT).as_posix(), ""
        if narrowed:
            candidates = narrowed
        else:
            shown = ", ".join(p.relative_to(ROOT).as_posix() for p in candidates[:5])
            if len(candidates) > 5:
                shown += ", ..."
            return None, f"no qualified source candidate for '{qual}': {shown}"

    if len(candidates) == 1:
        return candidates[0].relative_to(ROOT).as_posix(), ""

    token = f"func_{addr:08x}"
    token_hits = [p for p in candidates if token in texts[p]]
    if len(token_hits) == 1:
        return token_hits[0].relative_to(ROOT).as_posix(), ""

    shown = ", ".join(p.relative_to(ROOT).as_posix() for p in candidates[:5])
    if len(candidates) > 5:
        shown += ", ..."
    return None, f"ambiguous source candidates for '{func_name}': {shown}"


def load_registry(path: Path = REGISTRY_TSV) -> Dict[int, RegistryEntry]:
    entries: Dict[int, RegistryEntry] = {}
    symbols_by_addr: Dict[int, str] = {}
    symbol_line_by_addr: Dict[int, Tuple[int, str]] = {}
    symbol_to_addr: Dict[str, int] = {}
    if not path.exists():
        return entries

    for lineno, parts in _iter_registry_parts(path):
        if len(parts) != 2:
            raise ValueError(
                f"{path}:{lineno}: invalid row format; expected symbol<TAB>addr"
            )

        symbol = resolve_symbol_name(parts[0].strip())
        addr = parse_hex_addr(parts[1])
        prev = symbol_line_by_addr.get(addr)
        if prev is not None:
            prev_line, prev_sym = prev
            raise ValueError(
                f"{path}:{lineno}: duplicate symbol for 0x{addr:08x} "
                f"(already {prev_sym} at line {prev_line}); one symbol per address"
            )
        prev_addr = symbol_to_addr.get(symbol)
        if prev_addr is not None and prev_addr != addr:
            raise ValueError(
                f"{path}:{lineno}: symbol {symbol} already mapped to 0x{prev_addr:08x}, "
                "cannot remap"
            )
        symbol_line_by_addr[addr] = (lineno, symbol)
        symbol_to_addr[symbol] = addr
        symbols_by_addr[addr] = symbol

    src_files = _iter_src_files()
    if symbols_by_addr and not src_files:
        raise ValueError(f"{path}: no source files found under src/ for symbol-based cxx detection")
    texts = {p: p.read_text(errors="ignore") for p in src_files}
    addr_fallback = _build_addr_source_fallback_map(src_files, texts)
    defs_by_name = _build_func_name_source_map(src_files, texts)
    asm_alias_sources = _build_asm_alias_source_map(src_files, texts)

    for addr, symbol in sorted(symbols_by_addr.items()):
        alias_candidates = sorted(set(asm_alias_sources.get(symbol, [])))
        if len(alias_candidates) == 1:
            entries[addr] = RegistryEntry(
                addr=addr,
                mode="cxx",
                source=alias_candidates[0].relative_to(ROOT).as_posix(),
                symbol=symbol,
            )
            continue
        source, _reason = _resolve_source_for_symbol(
            symbol, addr, src_files, texts, defs_by_name
        )
        if source:
            entries[addr] = RegistryEntry(addr=addr, mode="cxx", source=source, symbol=symbol)
            continue
        fallback = addr_fallback.get(addr)
        if fallback:
            entries[addr] = RegistryEntry(addr=addr, mode="cxx", source=fallback, symbol=symbol)

    return entries


def load_symbol_aliases(path: Path = REGISTRY_TSV) -> List[SymbolAlias]:
    aliases: Dict[str, int] = {}
    addr_to_name_line: Dict[int, Tuple[str, int]] = {}
    if not path.exists():
        return []

    for lineno, parts in _iter_registry_parts(path):
        if len(parts) != 2:
            raise ValueError(
                f"{path}:{lineno}: invalid row format; expected symbol<TAB>addr"
            )
        name = resolve_symbol_name(parts[0].strip())
        addr = parse_hex_addr(parts[1])

        prev = aliases.get(name)
        if prev is not None and prev != addr:
            raise ValueError(
                f"{path}:{lineno}: symbol {name} already mapped to 0x{prev:08x}, cannot remap"
            )
        prev_addr = addr_to_name_line.get(addr)
        if prev_addr is not None:
            prev_name, prev_line = prev_addr
            raise ValueError(
                f"{path}:{lineno}: duplicate symbol for 0x{addr:08x} "
                f"(already {prev_name} at line {prev_line}); one symbol per address"
            )
        addr_to_name_line[addr] = (name, lineno)
        aliases[name] = addr

    out = [SymbolAlias(name=n, addr=a) for n, a in aliases.items()]
    out.sort(key=lambda x: (x.addr, x.name))
    return out


def src_to_obj(source: str) -> str:
    src = Path(source)
    if src.suffix not in {".cpp", ".c", ".s", ".S"}:
        raise ValueError(f"source must end in .cpp, .c, .s or .S: {source}")
    return str(Path("out") / "build" / src.with_suffix(".o"))


def addr_to_file_offset(addr: int) -> int:
    return MAIN_FOFF + (addr - MAIN_VADDR)


def _elf_endian(data: bytes) -> Optional[str]:
    if len(data) < 0x34 or data[0:4] != b"\x7fELF":
        return None
    if data[4] != 1:
        return None
    if data[5] == 1:
        return "little"
    if data[5] == 2:
        return "big"
    return None


def parse_elf_load_segments(data: bytes) -> List[ElfLoadSegment]:
    endian = _elf_endian(data)
    if endian is None:
        return []

    e_phoff = int.from_bytes(data[0x1C:0x20], endian)
    e_phentsize = int.from_bytes(data[0x2A:0x2C], endian)
    e_phnum = int.from_bytes(data[0x2C:0x2E], endian)

    if not e_phoff or not e_phentsize or not e_phnum:
        return []

    out: List[ElfLoadSegment] = []
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        if off + 0x20 > len(data):
            continue
        p_type = int.from_bytes(data[off + 0x00 : off + 0x04], endian)
        if p_type != 1:  # PT_LOAD
            continue
        p_offset = int.from_bytes(data[off + 0x04 : off + 0x08], endian)
        p_vaddr = int.from_bytes(data[off + 0x08 : off + 0x0C], endian)
        p_filesz = int.from_bytes(data[off + 0x10 : off + 0x14], endian)
        if p_offset + p_filesz > len(data):
            continue
        out.append(ElfLoadSegment(vaddr=p_vaddr, offset=p_offset, filesz=p_filesz))
    out.sort(key=lambda s: s.vaddr)
    return out


def load_elf_image(path: Path) -> Optional[Tuple[bytes, List[ElfLoadSegment]]]:
    if not path.exists():
        return None
    data = path.read_bytes()
    segs = parse_elf_load_segments(data)
    if not segs:
        return None
    return data, segs


def read_elf_vaddr(
    image: Tuple[bytes, List[ElfLoadSegment]], vaddr: int, size: int
) -> Optional[bytes]:
    if size < 0:
        return None
    if size == 0:
        return b""
    data, segs = image
    for seg in segs:
        start = seg.vaddr
        end = seg.vaddr + seg.filesz
        if not (start <= vaddr and vaddr + size <= end):
            continue
        off = seg.offset + (vaddr - start)
        return data[off : off + size]
    return None
