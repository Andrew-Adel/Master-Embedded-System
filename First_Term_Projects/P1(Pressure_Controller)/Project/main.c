/*
 * main.c
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */
// ================== includes ==================

#include "PortA_driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Alarm_System.h"

// ================== Main Function ==================

int main(){
	GPIO_PA_INITIALIZATION();
	int Pressure;
	while(1){
		Pressure = Read_PressureSensor();
		if (Pressure > P_Threshold)
			Set_Output();
		else
			Set_Timer(1);
	}
	return 1;
}
