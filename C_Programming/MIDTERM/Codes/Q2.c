/*
 * Q2.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */
#include <stdio.h>

float SquareRoot(int num){
	float res=((float)num)/2, temp = 0;

	while(res != temp){
		temp = res;
		res = (num/temp+temp)/2;
	}
	return res;
}


void Q2(void){
	int num;
	float res;
	printf("Test 1: Enter The Number To get its square root: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = SquareRoot(num);
	printf("Digits Sum = %f", res);

	printf("\nTest 2: Enter The Number To get its square root: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = SquareRoot(num);
	printf("Digits Sum = %f", res);
}
