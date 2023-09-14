/*
 * LCD.c
 *
 * Created: 9/12/2023 1:03:56 PM
 *  Author: andre
 */ 

#include "LCD.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#include <stdio.h>

void LCD_Init(void)
{
	
	// The 3 CTRL bits are output
	DataDir_LCD_CTRL |=  (1<<EN_SWITCH | 1<<RW_SWITCH | 1<<RS_SWITCH);
	
	_delay_ms(20);

	//LCD_IsBusy();

	// The CTRL is send xxxx000x which mean WriteOnLCD- WriteCommand- disable
	LCD_CTRL &=  (~(1<<EN_SWITCH | 1<<RW_SWITCH | 1<<RS_SWITCH));
	// The 8 bits of port are output
	DataDir_LCD_PORT = 0xff;
	_delay_ms(20);
	LCD_CLear_Screen();
	
	// ============================== Select 4 or 8 bit for port ==============================
	#ifdef EIGHT_BIT_MODE
		LCD_Write_Commend(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
//		LCD_PORT = FUNCTION_SET_4BIT;
		LCD_Write_Commend(0x02);
		//_delay_ms(50);
		LCD_Write_Commend(LCD_FUNCTION_4BIT_2LINES);
	#endif
	// ============================== Cursor ==============================

	LCD_Write_Commend(LCD_ENTRY_MODE);
	LCD_Write_Commend(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Write_Commend(LCD_DISP_ON_CURSOR_BLINK);


}

void LCD_IsBusy()
{
	DataDir_LCD_PORT &= (~(0xFF<<DATA_SHIFT));
	// EN = 0, RW=1 for read from LCD, RS=0 for command not data
	LCD_CTRL |=  (1<<RW_SWITCH);
	LCD_CTRL &=  (~(1<<EN_SWITCH | 1<<RS_SWITCH));
	// wait as it busy (busy as bit7 = 1 which mean port has value 0x80 or more)
//	while(LCD_PORT >= 0x80)
	//{
		LCD_Kick();

	//}
	#ifdef EIGHT_BIT_MODE
		DataDir_LCD_PORT |= 0xFF;
	#endif
		
	#ifdef FOUR_BIT_MODE
		LCD_Kick();
		DataDir_LCD_PORT |= 0xF0;
	#endif
	
	LCD_CTRL &=  (~(1<<RW_SWITCH));

}

void LCD_Kick(void)
{
	LCD_CTRL |=  (1<<EN_SWITCH);
//	asm volatile ("nop");
//	asm volatile ("nop");
	_delay_ms(20);
	LCD_CTRL &=  (~(1<<EN_SWITCH));
}

void LCD_CLear_Screen(void)
{
	LCD_Write_Commend(LCD_CLEAR_SCREEN_CODE);
}

void LCD_GotoXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position >=0 && position < 16)
		{
			LCD_Write_Commend(LCD_LINE0_BASE_ADDRESS + position);
		}
	}
	else if (line == 1)
	{
		if (position >=0 && position < 16)
		{
			LCD_Write_Commend(LCD_LINE1_BASE_ADDRESS + position);
		}
	}
}

void LCD_Write_Commend(unsigned char command)
{
	LCD_IsBusy();

	#ifdef EIGHT_BIT_MODE
		LCD_PORT = command;
		// RW=0 for write LCD, RS=0 for command not data
		LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
		LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE

	// ============================== Send MSBs ==============================
		LCD_PORT = (LCD_PORT&0x0F)|(command & 0xF0);
		// RW=0 for write LCD, RS=0 for command not data
		LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
		LCD_Kick();
	// ============================== Send LSBs ==============================		
		LCD_PORT = (LCD_PORT&0x0F)| (command<<DATA_SHIFT);
		// RW=0 for write LCD, RS=0 for command not data
		LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
		LCD_Kick();
	#endif
	
}

void LCD_Write_Char(unsigned char c)
{
	LCD_IsBusy();
	
	#ifdef EIGHT_BIT_MODE
		// RW=0 for write LCD, RS=1 for command not data
		LCD_CTRL |=  (1<<RS_SWITCH);
		LCD_PORT = c;
		LCD_CTRL &=  (~(1<<RW_SWITCH));
		LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE

	// RW=0 for write LCD, RS=1 for command not data
	LCD_CTRL |=  (1<<RS_SWITCH);
	// ============================== Send MSBs ==============================
		LCD_PORT = (LCD_PORT & 0x0F) | (c & 0xF0);
		LCD_CTRL &=  (~(1<<RW_SWITCH));
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_Kick();
	// ============================== Send LSBs ==============================
		LCD_PORT = (LCD_PORT & 0x0F) | (c << DATA_SHIFT);
		LCD_CTRL &=  (~(1<<RW_SWITCH));
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_Kick();
	#endif

}

void LCD_Write_String(char* str)
{
	unsigned char count=0;
	while (*str > 0)
	{
		count++;
		LCD_Write_Char(*str++);
		// check if line is full
		if (count == 16)
		{
			LCD_GotoXY(1,0);
		}
		else if (count >= 32)
		{
			LCD_CLear_Screen();
			LCD_GotoXY(0,0);
			count = 0;
		}
		
	}
}

void LCD_Write_Number(int Number)
{
	char str[15];
	sprintf(str,"%d",Number);
	LCD_Write_String(str);
}

void LCD_Write_Real_Number(double Number)
{
	char str[16];
	char* sign = Number<0?"-":"";
	
	float absNum = Number<0? -Number:Number;
	int intNum = (int)absNum;
	int floatNum = (absNum - intNum)*100;
	sprintf(str,"%s%d.%d",sign,intNum,floatNum);
	LCD_Write_String(str);
}

