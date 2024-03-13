

ENTRY(_start)

SECTIONS {
  /* _mrom_start and _entry_offset are defined in LDFLAGS */
  . = _mrom_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  }
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  }

  _data_bss_start = 0x0f000000;
  . = _data_bss_start;
  .data : {
	data_start = .
    *(.data)
  }
  edata = .;
  _data = .;
  data_load_start = LOADADDR(.data);
  data_size = SIZEOF(.data);
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x3000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);
}

ENTRY(_start)

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  }
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
	rodata_end = .;
  }

  .data : AT (rodata_end)
  {
	data_start = .
    *(.data)
  } > sram
  edata = .;
  _data = .;
  data_load_start = LOADADDR(.data);
  data_size = SIZEOF(.data);
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram
  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x3000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);
}