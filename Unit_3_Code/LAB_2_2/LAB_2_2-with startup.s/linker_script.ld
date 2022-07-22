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
		*(.vectors*) *(.text*)
	}> flash

	.bss :
	{
		*(.bss*) 
	}> sram
}