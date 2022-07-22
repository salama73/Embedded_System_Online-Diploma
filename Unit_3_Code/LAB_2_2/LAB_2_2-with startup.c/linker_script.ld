/* 
learn-in-depth
unit_2-lesson_3
eng.salama
*/


MEMORY
{
	flash (RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram (RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*) 
		*(.text*)
		*(.rodata)
		_E_TEXT = .;
	}> flash

	.data :
	{
		_S_DATA = . ;
		*(.data)
		_E_DATA = . ;
		. = ALIGN(4);
	}> sram AT> flash

	.bss :
	{
		_S_BSS = . ;
		*(.bss*) 
		_E_BSS = . ;
		. = ALIGN(4);
		. = . + 0x1000 ;
		_stack_top = . ;
	}> sram
}