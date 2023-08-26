/*
 * Collision_Avoidance.h
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#ifndef _Collision_Avoidance_H_
#define _Collision_Avoidance_H_

#include "State.h"

enum {
	CA_waiting,
	CA_Driving
} CA_state_ID;

// states function
STATE_define(CA_waiting);
STATE_define(CA_Driving);
// global pointer to state
extern void (*CA_State) ();

#endif
