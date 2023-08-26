/*
 * DC_motor.h
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */



#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include "State.h"

enum {
	DC_idle,
	DC_busy
}DC_state_id;

// function to initialize DC MOTOR
void DC_init(void);
// generate function of each state
STATE_define(DC_busy);
STATE_define(DC_idle);

//define global pointer to function for states
void (*DC_State) ();

#endif
