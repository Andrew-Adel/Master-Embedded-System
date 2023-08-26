/*
 * Collision_Avoidance.c
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#include "Collision_Avoidance.h"

// variable
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;
// pointer to state function
void (*CA_State) ();

int generate_random(int l, int r);

void US_distance_get(int d){
	CA_distance = d;
	(CA_distance > CA_threshold) ? (CA_State = STATE(CA_Driving)) : (CA_State = STATE(CA_waiting));
	printf("US -------distance(%d)-------> CA \n", CA_distance);
}

STATE_define(CA_waiting){
	// set state id
	CA_state_ID = CA_waiting;
	printf("before decision CA_Waiting State: [Distance =%d, Speed=%d]\n", CA_distance, CA_speed);

	CA_speed = 0;
	printf("After decision CA_Waiting State: [Distance =%d, Speed=%d]\n", CA_distance, CA_speed);

	DC_motor(CA_speed);


}

STATE_define(CA_Driving){
	// set state id
	CA_state_ID = CA_Driving;
	//print
	printf("before decision CA_Driving State: [Distance =%d, Speed=%d]\n", CA_distance, CA_speed);
	// set speed
	CA_speed = 30;
	printf("After decision CA_Driving State: [Distance =%d, Speed=%d]\n", CA_distance, CA_speed);

	DC_motor(CA_speed);



}
