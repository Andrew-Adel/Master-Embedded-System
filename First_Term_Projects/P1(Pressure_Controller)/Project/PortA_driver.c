/*
 * PortA_driver.c
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */
// ================== includes ==================

#include "PortA_driver.h"

// ================== Functions ==================
// initialize PortA before start the program
void GPIO_PA_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
	SET_BIT(GPIOA_ODR,13);

}
