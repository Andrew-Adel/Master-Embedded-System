/*
 * Alarm_System.c
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */
// ================== includes ==================

#include "Alarm_System.h"
#include "Alarm_Actuatot_Driver.h"
// ================== Functions ==================

void Set_Timer(int seconds)
{
	int i,j;
	for (i = 0; i < seconds; ++i) {
		j = nCount;
		for(; j != 0; j--);
	}
}

void Turn_on_Alarm(){
	Set_Alarm_actuator(0);
}

void Turn_off_Alarm(){
	Set_Alarm_actuator(1);
}

void Set_Output(){
	Turn_on_Alarm();
	Set_Timer(60);
	Turn_off_Alarm();
}

