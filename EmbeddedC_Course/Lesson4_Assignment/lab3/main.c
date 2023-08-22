/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Andrew Adel
 * @brief          : Main program body
**/
#include "platform_types.h"

#define SYSCTL_RCGC2_R (*((volatile uint32*) 0x400FE108))
#define GPIO_PORTF_DIR_R (*((volatile uint32*) 0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile uint32*) 0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile uint32*) 0x400253FC))

int main(){
	SYSCTL_RCGC2_R = 0x20;
	//delay to ensure gpiof is up and running
	volatile uint32 delay_counter;
	for (delay_counter = 0; delay_counter < 200; ++delay_counter);
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DEN_R |= 1<<3;
	
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for (delay_counter = 0; delay_counter < 200000; ++delay_counter);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (delay_counter = 0; delay_counter < 200000; ++delay_counter);
	}

	return 0;
}

// parameter to use texas edx lab2: 
// -dedXLab2