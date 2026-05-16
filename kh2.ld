_start = 0x0010001C;
ENTRY(_start);
INCLUDE out/generated/symbols.ld

SECTIONS {
  /* @CXX_SECTIONS@ */

  . = 0x0037A4B4;
  .ctors : {
    KEEP(*(SORT(.ctors.*)))
    KEEP(*(.ctors))
  }

  . = 0x0037A6E8;
  .dtors : {
    KEEP(*(SORT(.dtors.*)))
    KEEP(*(.dtors))
  }

  . = 0x00400000;
  .cxx_text : {
    *(.text .text.* .gnu.linkonce.t*)
  }

  .cxx_rodata : {
    *(.rodata)
    *(.rodata.*)
    *(.gnu.linkonce.r*)
  }

  .cxx_data : {
    *(.data)
    *(.data.*)
    *(.gnu.linkonce.d*)
    *(.sdata)
    *(.sdata.*)
    *(.gnu.linkonce.s*)
  }

  .reginfo : { *(.reginfo) }

  _edata = .;

  .cxx_bss (NOLOAD) : {
    _fbss = .;
    *(.sbss)
    *(.sbss.*)
    *(.scommon)
    *(.bss)
    *(.bss.*)
    *(.gnu.linkonce.b*)
    *(COMMON)
    _end_bss = .;
  }

  /DISCARD/ : {
    *(.MIPS.abiflags)
    *(.comment)
    *(.pdr)
    *(.mdebug*)
    *(.gnu.attributes)
  }
}
