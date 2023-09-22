/*
 * SevenSegmentComAnode.c
 *
 *  Created on: Sep 20, 2023
 *      Author: andre
 */

#include "SevenSegmentComAnode.h"

void WriteOn_7Seg(unsigned char value)
{
	MCAL_GPIO_Write8Bits(SevenSegmetn_Port,StartBit, ((uint16_t)value) ); /* write data on to the LED port */
}
