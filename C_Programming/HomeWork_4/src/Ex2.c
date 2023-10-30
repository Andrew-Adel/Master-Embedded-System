/*
 * Ex2.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */

#include <stdio.h>

int fact(int x){
	if (x == 2)
		return 2;
	if (x <2)
		return 1;
	return x * fact(x-1);
}

void factorialCall(void){
	int x;
	printf("Enter a positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	printf("Factorial of %d = %d", x, fact(x));
}
