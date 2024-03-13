
ENTRY(_start)

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 32K
  sram : ORIGIN = 0x0f000000, LENGTH = 64K
}

SECTIONS {
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } > mrom AT> mrom
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    rodata_end = .;
  } > mrom AT> mrom

  .data :
  {
	data_start = .;
    *(.data)
	data_end = .;
  } > sram AT>mrom
  edata = .;
  _data = .;
  data_load_start = LOADADDR(.data);
  data_size = SIZEOF(.data);
  data_load_end = LOADADDR(.bss);
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram AT> mrom
  _stack_top = ALIGN(0x10);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = .;
  _heap_end = ORIGIN(sram) + LENGTH(sram);
}