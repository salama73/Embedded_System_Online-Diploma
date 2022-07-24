/* 
learn-in-depth
unit_2-lesson_3
eng.salama
*/


MEMORY
{
	flash (RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram (RWX) : ORIGIN = 0x20000000, LENGTH = 512M
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
	}> sram
}