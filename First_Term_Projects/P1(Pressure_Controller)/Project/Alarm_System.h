/*
 * Alarm_System.h
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */

#ifndef _ALARM_SYSTEM_H_
#define _ALARM_SYSTEM_H_

// ================== includes ==================

#include "PortA_driver.h"

// ================== MACROS ==================

#define nCount 530000
#define P_Threshold 20

// ================== Functions ==================

// set delay for specific number of seconds
void Set_Timer(int seconds);
// turn on the alarm
void Turn_on_Alarm();
// turn off the alarm
void Turn_off_Alarm();
// start the alarm by turn on alarm, wait 60sec and turn off the alarm
void Set_Output();

#endif
