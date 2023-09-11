/*
 * GccApplication1.c
 *
 * Created: 9/11/2023 9:36:22 PM
 * Author : Andrew
 */ 

#include "MemFile.h"
#define F_CPU 0
#include <util/delay.h>
void PORTC_init()
{
	PC_DDRD->port = 0xff;
	PC_DR->port = 0xff;
}

#define clearBit(Port,bit) (Port &= ~(1<<bit))
void delay(int x)
{
	volatile int i,j;
	for (i=0;i<x;i++)
	{
		for (j=0;j<1000;j++);
	}
	
}
int main(void)
{
	PORTC_init();
	unsigned char i,j,k;
    /* Replace with your application code */
    while (1) 
    {
		for (i=0; i<10; i++)
		{
			for (j=0; j<10; j++)
			{
				/*
				PC_DR->pins.pin2 = 0;
				PC_DR->pins.pin3 = 1;
				PC_DR->port |= (i<<4);
				_delay_ms(100);
				PC_DR->pins.pin2 = 1;
				PC_DR->pins.pin3 = 0;
				PC_DR->port |= (j<<4);
				_delay_ms(100);
				*/
				for (k=0;k<10;k++)
				{
					PC_DR->port = 0b1011 | (i<<4);
					delay(20);
					PC_DR->port = 0b0111 | (j<<4);
					delay(20);
				}
				
			}
		}
    }
}

