// @learn in depth
// Mastering embedded system course
// Written by Andrew Adel

#include "uart.h"
unsigned char* str = "to create rodata section"; 
unsigned char string_buffer[100] = "learn-in-depth:<Andrew Adel>";

void main(void){
	Uart_Send_string(string_buffer);
}