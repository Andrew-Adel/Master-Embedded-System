/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Andrew Adel
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

// #if !defined(__SOFT_FP__) && defined(__ARM_FP)
//   #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
// #endif
#include "platform_types.h"
int global_var[11];
int init_global[] = {5,6,7,8};
int const const_global_var[4] = {1,2,3,4};
extern void Usage_Fault_Handler(void){

}


//define bases of registers
#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
// define needed address
#define RCC_APB2ENR *(vuint32*)(RCC_BASE+ 0x18)
#define GPIO_PA_CHR *(vuint32*)(GPIOA_BASE+ 0x04)

#define GPIO_PA_ODR (GPIOA_BASE+ 0x0c)
// define the position of desired bit in each address
#define RCC_IOPAEN_BIT 		1<<2
#define GPIO_ODR_PA13		1<<13
// union for all pins in ODR
typedef union{
	vint32 all_field;
	struct {
		vint32 reserved:13;
		vint32 P_13:1;
	}Pins;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)GPIO_PA_ODR;

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN_BIT;

	GPIO_PA_CHR &= 0xFF0FFFFF;
	GPIO_PA_CHR |= 0X00200000;

	int i;
	while(1){
		R_ODR->Pins.P_13 = 1;
		for(i=0;i<5000;i++);
		R_ODR->Pins.P_13 = 0;
		for(i=0;i<5000;i++);
	}

}
