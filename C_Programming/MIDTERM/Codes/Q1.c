/*
 * Q1.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */
#include <stdio.h>

unsigned short Digit_Sum(unsigned short num){
	int res = 0;
	while (num != 0){
		res += num %10;
		num /=10;
	}
	return res;
}

void Q1(void){
	int num, res;
	printf("Test 1\nEnter The Number To be sum its digits: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = Digit_Sum(num);
	printf("Digits Sum = %d", res);

	printf("\nTest 2\nEnter The Number To be sum its digits: ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		res = Digit_Sum(num);
		printf("Digits Sum = %d", res);
}
