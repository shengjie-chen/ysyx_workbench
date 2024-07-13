
ENTRY(_start)

MEMORY {
  mrom (rx) : ORIGIN = 0x20000000, LENGTH = 4K
  sram (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
  flash (rx) : ORIGIN = 0x30000000, LENGTH = 4K
}

SECTIONS {
  . = ORIGIN(flash);
  .text : {
    *(entry)
    *(.text*)
  } > flash AT> flash
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    rodata_end = .;
  } > flash AT> flash
  .srodata : {
    *(.srodata*)
    srodata_end = .;
  } > flash AT> flash
  
  .data :
  {
	data_start = .;
    *(.data*)
	data_end = .;
  } > sram AT>flash
  .sdata :
  {
	*(.sdata*)
  } > sram AT>flash
  edata = .;
  _data = .;
  data_load_start = LOADADDR(.data);
  /* data_size = SIZEOF(.data); */
  data_load_end = LOADADDR(.bss);
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
	_bss_end = .;
  } > sram AT> flash
  _stack_top = ALIGN(0x10);
  . = _stack_top + 0x400;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = .;
  _heap_end = ORIGIN(sram) + LENGTH(sram);
}