/*
 * Q5.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include <stdio.h>
int CountOnes(int num){
	int res=0;

	while(num != 0){
		if(num%2 == 1)
			res++;
		num >>= 1;
	}
	return res;
}


void Q5(void){
	int num;
	int res;
	printf("Test 1: Enter The Numbers Count its 1s: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = CountOnes(num);
	printf("Number of 1s = %d", res);

	printf("\nTest 2: Enter The Numbers Count its 1s: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	res = CountOnes(num);
	printf("Number of 1s = %d", res);
}
