/*
 * Alarm_Actuatot_Driver.c
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */
// ================== includes ==================

#include "Alarm_Actuatot_Driver.h"

// ================== Functions ==================

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}
