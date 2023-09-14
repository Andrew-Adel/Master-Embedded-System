/*
 * LCD_AND_KEYPAD.c
 *
 * Created: 9/12/2023 12:42:07 PM
 * Author : andrew
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Driver/LCD.h"
#include "KeyPad_Drive/keypad.h"
#include <stdlib.h>
#include <string.h>



int main(void)
{
	LCD_Init();
	Keypad_init();
	_delay_ms(50);
	LCD_Write_String("Hello, I'm Andrew Adel");
	LCD_CLear_Screen();
	LCD_Write_String("   Calculator   ");
	_delay_ms(200);
	LCD_CLear_Screen();
	LCD_Write_String("Enter");
	LCD_GotoXY(1,0);
	LCD_Write_String("Calculation:");
	_delay_ms(500);
	LCD_CLear_Screen();

	unsigned char count = 0;
	unsigned char key_pressed;
	int LHS=0, RHS=0;
	float res = 0;
	int p=0;
	int temp = 0;
	unsigned char operator=0;
	unsigned char END_FLAG=0;
    while (1) 
    {
		key_pressed = Keypad_getkey();
		if (count == 16)
		{
			LCD_GotoXY(1,0);
		}
		if (count >31)
		{
			LCD_CLear_Screen();
			count = 0;
			operator = 0;
			p = 0;
		}
		switch(key_pressed){
			case 'N':
				break;
			case 'o':
				LCD_CLear_Screen();
				count = 0;
				p = 0;
				LHS = RHS = 0;
				temp = 0;
				break;
			case '=':
				if ( (p > 0) )
				{
					if ((operator != 0))
					{
						RHS = temp;
						temp = 0;
						p = 0;
						LCD_Write_Char(key_pressed);
						count++;

						switch(operator){
							case '+':
							LCD_Write_Number(LHS+RHS);
							break;
							case '-':
							LCD_Write_Number(LHS-RHS);
							break;
							case '*':
							LCD_Write_Number(LHS*RHS);
							break;
							case '/':
							res = ((float)LHS)/((float)RHS);
							LCD_Write_Real_Number(res);
							break;
						}
						END_FLAG = 1;
						count++;
						operator = 0;
						_delay_ms(150);
					}
				}
				break;
			default:
				if(key_pressed >= '0' && key_pressed<= '9')
				{
					if(END_FLAG ==1){
						END_FLAG = 0;
						LCD_CLear_Screen();
						count = 0;
					}
					if (p<16)
					{
						LCD_Write_Char(key_pressed);
						if (p == 0)
						{
							temp = key_pressed-'0';
						}
						else
						{
							temp = (temp*10) + (key_pressed-'0');
						}
						p++;
						count++;
						_delay_ms(250);
						break;
					}
				}
				else if(p>0)
				{
					if (operator != 0)
					{
						LCD_GotoXY(count/16, count%16);
					}
					operator = key_pressed;
					LHS = temp;
					temp = 0;
					p = 0;
					LCD_Write_Char(key_pressed);
					count++;
				}
		}
		
    }
}

