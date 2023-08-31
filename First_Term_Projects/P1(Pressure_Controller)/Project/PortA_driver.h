/*
 * PortA_driver.h
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */


#ifndef _PORTA_DRIVER_H_
#define _PORTA_DRIVER_H_

#include "platform_types.h"

#define SET_BIT(ADDRESS,BIT)   ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS) &   (1<<(BIT)))


#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32 *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(volatile uint32 *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32 *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32 *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32 *)(GPIO_PORTA + 0x0C)



void GPIO_PA_INITIALIZATION ();


#endif
