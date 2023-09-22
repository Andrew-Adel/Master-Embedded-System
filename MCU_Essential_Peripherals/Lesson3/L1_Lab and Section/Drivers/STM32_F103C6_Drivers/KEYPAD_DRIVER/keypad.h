/*
 * keypad.h
 *
 * Created: 9/14/2023 2:29:19 AM
 *  Author: andre
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

#define F_CPU 1000000UL


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4

#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

//#define KEYPAD_PORT				*(PORTD_DR)
//#define DataDir_KEYPAD_PORT		*(PORTD_DDR)
#define KEYPAD_PORT			GPIOB

void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */
