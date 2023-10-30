/*
 * Q5.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */


#include <stdio.h>
#define PI 3.14

#define calcArea(r) (r*r*PI)

float R = 0;


void Q5(void){
	float r;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &r);
	printf("Area=%.2f", calcArea(r));

}
