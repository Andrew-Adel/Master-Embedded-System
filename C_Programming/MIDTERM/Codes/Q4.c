/*
 * Q4.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>

int reverse(int num){
	int res;

	while(num != 0){
		res = res*10 + num%10;
		num/=10;
	}
	return res;
}


void Q4(void){
	int num;
	int res;
	printf("Test 1: Enter The Numbers To be reverse: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = reverse(num);
	printf("Reverse Number = %d", res);

	printf("\nTest 2: Enter The Numbers To be reverse: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = reverse(num);
	printf("Reverse Number = %d", res);
}
