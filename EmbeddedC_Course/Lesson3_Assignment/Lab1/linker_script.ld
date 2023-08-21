/*	learn-in-depth
	Unit2_Lesson2_Lab1
	Mastering Embedded System Diploma
	Eng. Andrew Adel
*/

ENTRY(reset)
MEMORY
{
	Mem (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text) *(.rodata)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(COMMON)
	}> Mem
	. = . + 0x1000; /* 4KB for Stack Memory */
	stack_top = .;
}