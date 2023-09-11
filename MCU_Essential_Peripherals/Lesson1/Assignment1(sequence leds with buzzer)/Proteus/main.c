/*
 * Unit7_Lesson1_Assignment.c
 *
 * Created: 9/10/2023 3:25:50 PM
 * Author : Andrew
 */ 

#include "MemFile.h"

void delay(int x)
{
	volatile int i,j;
	for (i = 0; i < x; i++)
	{
		for(j = 0; j < 1000; j++);
	}
		
}

// ===================== PORT_D_Init =====================
void IOD_init()
{
	// ===================== output Configuration =====================
	PD_DR->pins.pin4 = 1;
	PD_DDRD->pins.pin4 = 1;
	
	PD_DR->pins.pin5 = 1;
	PD_DDRD->pins.pin5 = 1;
	
	PD_DR->pins.pin6 = 1;
	PD_DDRD->pins.pin6 = 1;
	
	PD_DR->pins.pin7 = 1;
	PD_DDRD->pins.pin7 = 1;
	
	// ===================== input Configuration =====================
	PD_DR->pins.pin0 = 1; // high impedance
	PD_DDRD->pins.pin0 = 0; 
	
}

int main(void)
{
    IOD_init();
	
	PD_DR->pins.pin4 = 0;
	PD_DR->pins.pin5 = 0;
	PD_DR->pins.pin6 = 0;
	PD_DR->pins.pin7 = 0;
	
	char count = 5, prev = 1;
    while (1) 
    {
		if ( (PD_PIN->pins.pin0 == 1) )
		{
			if(prev == 0)
			{
				PD_DR->pins.pin4 = 0;
				PD_DR->pins.pin5 = 0;
				PD_DR->pins.pin6 = 0;
				PD_DR->pins.pin7 = 0;
				if (count <= 7)
				{
					PD_PIN->port |= (1<< count);
					count++;
				}
				else
				{
					count = 5;
					PD_DR->pins.pin4 = 1;
					delay(500);
					PD_DR->pins.pin4 = 0;
				}
				prev = 1;
			}
		}
		else
		{
			prev = 0;
		}
		delay(10);
		
    }
}

