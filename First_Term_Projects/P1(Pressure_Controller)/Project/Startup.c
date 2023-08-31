/*
	Startup file for STM32F103C6
	Eng. Andrew Adel Hosny Goued
*/

// Start of SRAM is at address 0x20000000
// ============== include needed data type ============== 

#include "platform_types.h"

// ============== Exporting needed labels from linker ============== 

extern uint32 _stack_top;
extern uint32 _E_BSS;
extern uint32 _S_BSS;
extern uint32 _E_DATA;
extern uint32 _S_DATA;
extern uint32 _E_TEXT;
extern uint32 _S_TEXT;

// ============== Exporting needed functions labels ============== 

extern int main(void);

// ============== declaration imoortant Handler ============== 

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));

// ============== declaration vector section to be stored in first of memory ============== 

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
	( void(* const)() ) (&_stack_top) ,
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler
};

// ============== defination of some Handler ============== 

void Reset_Handler(void){
	uint32 DATA_SIZE = (uint8*)&_E_DATA - (uint8*)&_S_DATA;
	uint8* P_src = (uint8*)&_E_TEXT;
	uint8* P_dst = (uint8*)&_S_DATA;
	int i;
	for (i = 0; i < DATA_SIZE; ++i)
	{
		*(P_dst++) = *(P_src++);
	}

	uint32 BSS_SIZE = (uint8*)&_E_BSS - (uint8*)&_S_BSS;
	P_dst = (uint8*)&_S_BSS;
	for (i = 0; i < BSS_SIZE; ++i)
	{
		*(P_dst++) = *(uint8*)0;
	}


	main();
}

void Default_Handler(void){

	Reset_Handler();

}