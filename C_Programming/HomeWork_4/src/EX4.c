/*
 * EX4.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */

#include <stdio.h>

int powerRec(int base, int power);

void PowerNumberCalling(void){
	int base, power;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &base);

	printf("Enter power number(positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &power);

	printf("%d^%d = %d", base, power, powerRec(base,power));
}

int powerRec(int base, int power){
	if(power == 0)
		return 0;
	else if (power == 1)
		return base;
	else
		return base * powerRec(base, power-1);
}
