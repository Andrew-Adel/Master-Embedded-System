/*
 * LCD.c
 *
 * Created: 9/12/2023 1:03:56 PM
 *  Author: andre
 */

#include "LCD.h"
//#define F_CPU 1000000UL
//#include <stdio.h>

void delay(int x)
{
	int i,j;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < 1000; ++j);
	}
}

GPIO_PinConfig_t PinConfig;

//
void LCD_8PINS_Config(uint32_t MODE, uint32_t SPEED)
{
	PinConfig.GPIO_PIN = GPIO_PIN_0;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_1;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_2;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_3;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_4;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_5;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_6;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = GPIO_PIN_7;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
}

void LCD_INIT(void)
{


	// The 3 CTRL bits are output
	delay(20);
	// The CTRL is send xxxx000x which mean WriteOnLCD- WriteCommand- disable
	//	LCD_CTRL &=  (~(1<<EN_SWITCH | 1<<RW_SWITCH | 1<<RS_SWITCH));
	// ================= LCD_CTRL =================
	PinConfig.GPIO_PIN = EN_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PIN = RW_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PIN = RS_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	// The 8 bits of port are output
	//	DataDir_LCD_PORT = 0xff;
	delay(15);


	LCD_8PINS_Config(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_10M);

	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	delay(20);

	LCD_CLear_Screen();
	LCD_Write_Command(LCD_FUNCTION_8BIT_2LINES);
	LCD_Write_Command(LCD_ENTRY_MODE);
	LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Write_Command(LCD_DISP_ON_CURSOR_BLINK);
	// ============================== Select 4 or 8 bit for port ==============================
	//#ifdef EIGHT_BIT_MODE
	//	LCD_Write_Command(LCD_FUNCTION_8BIT_2LINES);
	//#endif
	//
	//#ifdef FOUR_BIT_MODE
	//	//		LCD_PORT = FUNCTION_SET_4BIT;
	//	LCD_Write_Command(0x02);
	//	//delay(50);
	//	LCD_Write_Command(LCD_FUNCTION_4BIT_2LINES);
	//#endif

	// ============================== Cursor ==============================

	//	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	//	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	//	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	//
	//	delay(20);
	//
	//	LCD_CLear_Screen();
	//	LCD_Write_Command(LCD_FUNCTION_8BIT_2LINES);
	//	LCD_Write_Command(LCD_ENTRY_MODE);
	//	LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW);
	//	LCD_Write_Command(LCD_DISP_ON_CURSOR_BLINK);
	//

}

void LCD_IsBusy()
{
	//	DataDir_LCD_PORT &= (~(0xFF<<DATA_SHIFT));
	//	LCD_8PINS_Config(GPIO_MODE_INPUT_FLO, GPIO_SPEED_10M);
//	PinConfig.GPIO_PIN = GPIO_PIN_0;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_1;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_2;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_3;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_4;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_5;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_6;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = GPIO_PIN_7;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(LCD_PORT, &PinConfig);
	LCD_8PINS_Config(GPIO_MODE_INPUT_FLO, GPIO_SPEED_10M);



	// EN = 0, RW=1 for read from LCD, RS=0 for command not data

	//	LCD_CTRL |=  (1<<RW_SWITCH);
	//	LCD_CTRL &=  (~(1<<EN_SWITCH | 1<<RS_SWITCH));

	//	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	//	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	//	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	LCD_Kick();
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	// wait as it busy (busy as bit7 = 1 which mean port has value 0x80 or more)
	//	while(LCD_PORT >= 0x80)
	//{
	//	LCD_Kick();

	//}
	//#ifdef EIGHT_BIT_MODE
	//	DataDir_LCD_PORT |= 0xFF;
	//#endif
	//
	//#ifdef FOUR_BIT_MODE
	//	LCD_Kick();
	//	DataDir_LCD_PORT |= 0xF0;
	//#endif

	//	LCD_CTRL &=  (~(1<<RW_SWITCH));
	//	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

}

void LCD_Kick(void)
{
	//	LCD_CTRL |=  (1<<EN_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	//	asm volatile ("nop");
	//	asm volatile ("nop");
	delay(50);

	//	LCD_CTRL &=  (~(1<<EN_SWITCH));
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);

}

void LCD_CLear_Screen(void)
{
	LCD_Write_Command(LCD_CLEAR_SCREEN_CODE);
}

void LCD_GotoXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position >=0 && position < 16)
		{
			LCD_Write_Command(LCD_LINE0_BASE_ADDRESS + position);
		}
	}
	else if (line == 1)
	{
		if (position >=0 && position < 16)
		{
			LCD_Write_Command(LCD_LINE1_BASE_ADDRESS + position);
		}
	}
}

void LCD_Write_Command(unsigned char command)
{
	//	LCD_IsBusy();

	//#ifdef EIGHT_BIT_MODE
	//	LCD_PORT = command;
	//	LCD_8PINS_Config(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_10M);

	MCAL_GPIO_WritePort(LCD_CTRL, command);

	// RW=0 for write LCD, RS=0 for command not data

	//	LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	delay(1);
	LCD_Kick();
	//#endif

	//#ifdef FOUR_BIT_MODE
	//
	//	// ============================== Send MSBs ==============================
	//	LCD_PORT = (LCD_PORT&0x0F)|(command & 0xF0);
	//	// RW=0 for write LCD, RS=0 for command not data
	//	LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
	//	LCD_Kick();
	//	// ============================== Send LSBs ==============================
	//	LCD_PORT = (LCD_PORT&0x0F)| (command<<DATA_SHIFT);
	//	// RW=0 for write LCD, RS=0 for command not data
	//	LCD_CTRL &=  (~((1<<RW_SWITCH) | (1<<RS_SWITCH)));
	//	LCD_Kick();
	//#endif

}

void LCD_Write_Char(unsigned char character) {
//	LCD_check_lcd_isbusy();
//	LCD_CTRL->CRL = character;
//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ character) & 0x00ff;
	MCAL_GPIO_WritePort(LCD_CTRL, character);
//	LCD_CTRL ^= (LCD_CTRL ^ character) & 0x00ff;
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
//	LCD_CTRL &= ~(1 << RW_SWITCH);
//	LCD_CTRL |= (1 << RS_SWITCH);
	delay(1);
	LCD_Kick();
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

/*
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
*/

