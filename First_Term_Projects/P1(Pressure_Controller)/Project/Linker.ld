/*
	Linker file for STM32F103C6
	Eng. Andrew Adel Hosny Goued
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :	{
		_S_TEXT = .;
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT = .;
	}> flash
	
	.data : {
		_S_DATA = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_E_DATA = .;
	}>sram AT> flash

	.bss : {
		_S_BSS = .;
		*(.bss*)
		_E_BSS = .;
		. = ALIGN(4);
		. = . + 0x1000;
		_stack_top = .;

	}> sram
}