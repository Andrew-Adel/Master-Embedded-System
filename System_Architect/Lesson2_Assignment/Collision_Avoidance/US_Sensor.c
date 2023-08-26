/*
 * US_Sensor.c
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */

#include "US_Sensor.h"
//Module Variable
unsigned int US_distance = 0;

void US_init(void){
	// initialize US Sensor
	// Call US Driver or sensors
	printf("US_Init is Done\n");
}

int generate_random(int l, int r)
{
	return rand()% (r-l+1) +l;
}

// states function
STATE_define(US_busy)
{
	//state action
	US_state_id = US_busy;
	//read from US sensor
	US_distance = generate_random(45,55);

	//Print
	printf("US_busy state : distance=%d \n", US_distance);

	// send distance to CA
	US_distance_get(US_distance);
	// change to next state (in US case, it always be busy state)
	US_State = STATE(US_busy);
}

