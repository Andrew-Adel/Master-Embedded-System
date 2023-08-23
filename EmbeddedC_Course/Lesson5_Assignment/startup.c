/*startup_cortexM3.c
Eng. Andrew Adel
*/

/*SRAM @ 0x20000000*/
#include "platform_types.h"

extern uint32 _stack_top;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;
extern uint32 _E_TEXT;


void Rest_Handler(void);

extern int main(void);

void Default_Handler(void){
	Rest_Handler();
}


void NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));

static volatile uint32 stack[256];



void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
	( void(* const)() ) (&_stack_top) ,
	&Rest_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler
};

void Rest_Handler(void){
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