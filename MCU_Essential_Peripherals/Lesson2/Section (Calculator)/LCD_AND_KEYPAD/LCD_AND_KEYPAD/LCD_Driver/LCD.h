/*
 * LCD.h
 *
 * Created: 9/12/2023 12:44:33 PM
 *  Author: andre
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL
#include "../ATMega32.h"
#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORT			*(PORTA_DR)
#define DataDir_LCD_PORT	*(PORTA_DDR)

#define LCD_CTRL			*(PORTB_DR)
//PORTB
#define DataDir_LCD_CTRL	*(PORTB_DDR)

#define RS_SWITCH			1
#define RW_SWITCH			2
#define EN_SWITCH			3

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#ifdef EIGHT_BIT_MODE
	#define DATA_SHIFT 0
#endif
#ifdef FOUR_BIT_MODE
	#define DATA_SHIFT 4
#endif

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN_CODE						(0x01)
#define FUNCTION_SET_4BIT							(0X20)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_LINE0_BASE_ADDRESS						(0x80)
#define LCD_LINE1_BASE_ADDRESS						(0xC0)

void LCD_Init(void);
void LCD_Write_Commend(unsigned char command);
void LCD_Kick(void);
void LCD_Write_Char(unsigned char c);
void LCD_Write_String(char* str);
void LCD_IsBusy(void);
void LCD_CLear_Screen(void);
void LCD_GotoXY(unsigned char line, unsigned char position);
void LCD_Write_Number(int Number);
void LCD_Write_Real_Number(double Number);


#endif /* LCD_H_ */