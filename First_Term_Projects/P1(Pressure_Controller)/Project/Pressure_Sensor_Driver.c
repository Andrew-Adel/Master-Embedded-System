/*
 * Pressure_Sensor_Driver.c
 *
 *  Created on: Aug 30, 2023
 *      Author: andre
 */

#include "Pressure_Sensor_Driver.h"

// get pressure sensor' reading
int Read_PressureSensor(){
	return (GPIOA_IDR & 0xFF);
}
