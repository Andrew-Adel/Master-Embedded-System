/*
 * stm32f103x6.h
 *
 *  Created on: Sep 17, 2023
 *      Author: andre
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//------------------------------------------
//Includes
//------------------------------------------

#include "stdlib.h"
#include "stdint.h"

//------------------------------------------
//Base Addresses For Memory
//------------------------------------------

#define FLASH_MEMORY_BASE							0x08000000UL
#define	SYSTEM_MEMORY_BASE							0X1FFFF000UL
#define	SRAM_MEMORY_BASE							0X20000000UL

// Peripherals

#define	Peripherals_BASE							0X40000000UL
#define	Cortex_M3_Internal_Peripherals_BASE			0X1FFFF000UL

//------------------------------------------
//Base Addresses For AHB Peripherals
//------------------------------------------

// RCC
#define RCC_BASE									0x40021000UL

//------------------------------------------
//Base Addresses For APB2 Peripherals
//------------------------------------------

// GPIO
// A,B Fully Included in LQFP48 Package
#define GPIOA_BASE									0x40010800UL
#define GPIOB_BASE									0x40010C00UL


// C,D Partial included in LQFP48 Package
#define GPIOC_BASE									0x40011000UL
#define GPIOD_BASE									0x40011400UL

// E is not included LQFP48 Package
#define GPIOE_BASE									0x40021000UL

// EXTI
#define EXTI_BASE									0x40010400UL


// AFIO
#define AFIO_BASE									0x40010000UL

//------------------------------------------
//Base Addresses For APB1 Peripherals
//------------------------------------------

//======================================================================================

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals Registers
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//------------------------------------------
//Peripherals Register: GPIO
//------------------------------------------

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


//------------------------------------------
//Peripherals Register: RCC
//------------------------------------------

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

//------------------------------------------
//Peripherals Register: EXTI
//------------------------------------------

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//------------------------------------------
//Peripherals Register: AFIO
//------------------------------------------

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t 		  RESERVED0;
	volatile uint32_t MAPR2;

}AFIO_TypeDef;

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals Instants
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//------------------------------------------
//Peripherals Register: AFIO
//------------------------------------------

#define GPIOA							 			((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB							 			((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC							 			((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD							 			((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE							 			((GPIO_TypeDef *) GPIOE_BASE)

#define RCC								 			((RCC_TypeDef *) RCC_BASE)

#define EXTI							 			((EXTI_TypeDef *) EXTI_BASE)

#define AFIO							 			((AFIO_TypeDef *) AFIO_BASE)

//======================================================================================

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Clock Enable Macros
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
#define RCC_AFIO_CLK_EN()							(RCC->APB2ENR |= 1<<0)

#define RCC_GPIOA_CLK_EN()							(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()							(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()							(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()							(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()							(RCC->APB2ENR |= 1<<6)

#endif /* INC_STM32F103X6_H_ */
