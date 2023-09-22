/*
 * LCD.h
 *
 * Created: 9/12/2023 12:44:33 PM
 *  Author: andre
 */


#ifndef LCD_H_
#define LCD_H_

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

#define F_CPU 1000000UL


#define LCD_PORT			GPIOA
#define LCD_CTRL			GPIOA
#define RS_SWITCH			GPIO_PIN_10
#define RW_SWITCH			GPIO_PIN_9
#define EN_SWITCH			GPIO_PIN_8

//#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE
//
//#ifdef EIGHT_BIT_MODE
//	#define DATA_SHIFT 0
//#endif
//#ifdef FOUR_BIT_MODE
//	#define DATA_SHIFT 4
//#endif

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

void LCD_INIT(void);
void LCD_Write_Command(unsigned char command);
void LCD_Kick(void);
void LCD_Write_Char(unsigned char c);
void LCD_Write_String(char* str);
void LCD_IsBusy(void);
void LCD_CLear_Screen(void);
void LCD_GotoXY(unsigned char line, unsigned char position);
void LCD_Write_Number(int Number);
void LCD_Write_Real_Number(double Number);
void delay(int x);

#endif /* LCD_H_ */
//
///*
// * lcd.h
// *
// * Created: 4/22/2021 3:01:25 PM
// *  Author: Marco
// */
//
//
//#ifndef LCD_H_
//#define LCD_H_
//
//#define F_CPU 1000000UL
//#include "stm32f103x6.h"
//#include "Stm32_F103C6_gpio_driver.h"
//
//#define LCD_CTRL GPIOA
//#define RS_SWITCH GPIO_PIN_10
//#define RW_SWITCH GPIO_PIN_9
//#define EN_SWITCH GPIO_PIN_8
//#define DATA_shift 4 // in 8 bit mode 0 and in 4 bit mode 4
//
////#define EIGHT_BIT_MODE
////#define FOUR_BIT_MODE
//
//#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
//#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
//#define LCD_MOVE_DISP_RIGHT       					(0x1C)
//#define LCD_MOVE_DISP_LEFT   						(0x18)
//#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
//#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
//#define LCD_DISP_OFF   								(0x08)
//#define LCD_DISP_ON_CURSOR   						(0x0E)
//#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
//#define LCD_DISP_ON_BLINK   						(0x0D)
//#define LCD_DISP_ON   								(0x0C)
//#define LCD_ENTRY_DEC   							(0x04)
//#define LCD_ENTRY_DEC_SHIFT   						(0x05)
//#define LCD_ENTRY_INC_   							(0x06)
//#define LCD_ENTRY_INC_SHIFT   						(0x07)
//#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
//#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
//#define LCD_CLEAR_SCREEN							(0x01)
//#define LCD_ENTRY_MODE								(0x06)
//
//GPIO_PinConfig_t PinCfg ;
//
void LCD_INIT();
//void LCD_WRITE_COMMAND(unsigned char command);
//void LCD_WRITE_CHAR(unsigned char character);
//void LCD_WRITE_STRING(char* string);
//void LCD_check_lcd_isbusy(void);
//void LCD_lcd_kick(void);
//void LCD_clear_screen();
//void LCD_GOTO_XY(unsigned char line, unsigned char position);
//void delay_ms(uint32_t time);
//
//#endif /* LCD_H_ */
