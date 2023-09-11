/*
 * GccApplication2.c
 *
 * Created: 9/11/2023 3:26:37 PM
 * Author : Andrew
 */ 

#include "MemFile.h"

#define ToggleBit(port,bin) (port ^= (1<<bin))

static unsigned int sevenSigmentNumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay(int x)
{
	volatile int i,j;
	for (i = 0; i < x; i++)
	{
		for(j = 0; j < 1000; j++);
	}
	
}

void PORTA_init()
{
	PA_DDRD->port = 0xff;
	PA_DR->port = 0x00;
}

void PORTB_init()
{
	PB_DDRD->port = 0xff;
	PB_DR->port = 0x00;
}

void PORTC_init()
{
	PC_DDRD->port = 0xff;
	PC_DR->port = 0xff;
}

void PORTD_init()
{
	PD_DDRD->pins.pin0 = 0;
	PD_DR->pins.pin0 = 0;
	
	PD_DDRD->pins.pin1 = 0;
	PD_DR->pins.pin1 = 0;
	
	PD_DDRD->pins.pin2 = 0;
	PD_DR->pins.pin2 = 0;
	
	PD_DDRD->pins.pin3 = 0;
	PD_DR->pins.pin3 = 0;

}

void Task1()
{
	int count = 0;
	for (count = 0; count<8; count++)
	{
		PA_DR->port ^= 1<<count;
		delay(10);
	}
	count--;
	for (; count >= 0; count--)
	{
		PA_DR->port ^= 1<<count;
		delay(10);
	}
}

void Task3(int n){
	if (n >= 0 && n < 10)
	{
		PC_DR->port = sevenSigmentNumber[n];		
	}else
		PC_DR->port = sevenSigmentNumber[8];
}

int main(void)
{
	PORTA_init();
	PORTB_init();
	PORTC_init();
	PORTD_init();
	
	signed char count = 0;
	char dir = 1;
	unsigned char D1flag = 0, D2flag = 0,D3flag=0;
	unsigned sevSegCount = 0;
    /* Replace with your application code */
    while (1) 
    {
		if (PD_PIN->pins.pin0 == 1)
		{
			Task1();
		}
		// =================== Task 2 ===================  
		if (PD_PIN->pins.pin1 == 1)
		{
			if (D1flag  == 0)
			{
				ToggleBit(PA_DR->port,count);
				count+= dir;
				if (count > 7)
				{
					count = 7;
					dir = -1;
				}
				else if (count < 0)
				{
					count = 0;
					dir = 1;
				}
				D1flag  = 1;
			}
		}else
		{
			D1flag  = 0;
		}
		
		if (PD_PIN->pins.pin2 == 1)
		{
			if (D2flag  == 0)
			{
				Task3(sevSegCount++);
				if (sevSegCount == 10)
				{
					sevSegCount = 0;
				}
				D2flag = 1;
			}
		}else
		{
			D2flag = 0;
		}
		
		if (PD_PIN->pins.pin3 == 1)
		{
			if (D3flag  == 0)
			{
				PB_DR->pins.pin0 = 1;
				delay(50);
				PB_DR->pins.pin0 = 0;
				D3flag = 1;
			}
		}else
		{
			D3flag = 0;
		}
		
    }
}

