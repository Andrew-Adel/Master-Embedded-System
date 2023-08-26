/*
 * State.h
 *
 *  Created on: Aug 24, 2023
 *      Author: andre
 */


#ifndef _STATE_H
#define _STATE_H
// Factory of functions and label of functions
#define STATE_define(_StateFunc_) void ST_##_StateFunc_()
#define STATE(_StateFunc_) ST_##_StateFunc_

#include <stdio.h>
#include <stdlib.h>

//state Connection
void US_distance_get(int d);
void DC_motor(int s);

#endif
