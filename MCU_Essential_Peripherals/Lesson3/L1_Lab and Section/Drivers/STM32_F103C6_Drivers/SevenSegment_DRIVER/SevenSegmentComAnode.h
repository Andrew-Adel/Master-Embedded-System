/*
 * SevenSegmentComAnode.h
 *
 *  Created on: Sep 20, 2023
 *      Author: andre
 */

#ifndef SEVENSEGMENT_DRIVER_SEVENSEGMENTCOMANODE_H_
#define SEVENSEGMENT_DRIVER_SEVENSEGMENTCOMANODE_H_

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

#define SS_ZERO 0xC0
#define SS_ONE 0x79
#define SS_TWO 0x24
#define SS_THREE 0x30
#define SS_FOUR 0x19
#define SS_FIVE 0x12
#define SS_SIX 0x02
#define SS_SEVEN 0xF8
#define SS_EIGHT 0x00
#define SS_NINE 0x10

#define SevenSegmetn_Port 		GPIOB
#define StartBit				9

void WriteOn_7Seg(unsigned char value);



#endif /* SEVENSEGMENT_DRIVER_SEVENSEGMENTCOMANODE_H_ */
