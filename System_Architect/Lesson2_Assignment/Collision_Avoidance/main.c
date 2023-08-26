/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#include "Collision_Avoidance.h"
#include "US_Sensor.h"
#include "DC_motor.h"
extern void (*DC_State) ();

void setup (){
	// init all drivers
	// init IRQ...
	// init HAL US_Driver DC_Driver
	// init Blocks
	US_init();
	DC_init();
	// set states pointer for each block
	US_State = STATE(US_busy);
	DC_State = STATE(DC_idle);
	CA_State = STATE(CA_waiting);

}

int main(){
	setup();
	volatile int i;
	for(i = 0; i<30;i++)
	//while(1)
	{
		printf("===================================\n");
		US_State();
		CA_State();
		DC_State();
//		for(d=0; d<10000; d++);
	}
}
