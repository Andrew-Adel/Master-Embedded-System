/*
 * keypad.h
 *
 * Created: 9/14/2023 2:29:19 AM
 *  Author: andre
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include<util/delay.h>
#include "../ATMega32.h"

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT				*(PORTD_DR)
#define DataDir_KEYPAD_PORT		*(PORTD_DDR)
#define keypadPIN				*(PORTD_PIN)

void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */