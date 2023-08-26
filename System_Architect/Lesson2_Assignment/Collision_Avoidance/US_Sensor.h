/*
 * US_Sensor.h
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#ifndef _US_SENSOR_H_
#define _US_SENSOR_H_

#include "State.h"

enum {
	US_busy
}US_state_id;

// function to initialize US sensor
void US_init(void);
// generate function of each state
STATE_define(US_busy);

//define global pointer to function for states
void (*US_State) ();

#endif
