/*
 * DC_motor.c
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#include "DC_motor.h"


//Module Variable
unsigned int speed;

void DC_init(void){
	// initialize US motor
	// Call US Driver or motors
	printf("DC_Init is Done\n");
}
void DC_motor(int s){
	speed =s;
	DC_State = STATE(DC_busy);
	printf("CA -------speed(%d)-------> DC \n", s);
}
// states function
STATE_define(DC_busy)
{
	//state action
	DC_state_id = DC_busy;
	// save the old speed
	// change to next state (in US case, it always be busy state)
	DC_State = STATE(DC_idle);

	// Print
	printf("DC_Busy State : speed=%d \n\n", speed);
}

STATE_define(DC_idle)
{
	//state action
	DC_state_id = DC_idle;
	// change speed
	// change to next state (in US case, it always be busy state)
	DC_State = STATE(DC_idle);
	//Print
	printf("DC_idle State : speed=%d \n\n", speed);

}
