/*
 * Ex1.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */

#include <stdio.h>
int checkPrime(int i);
void primeNumber(void){
	int x,y,i;
	printf("Enter two number(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	scanf("%d", &y);
	printf("Prime numbers between %d and %d are: ",x,y);
	for (i = x; i <=y; i++){
		if (checkPrime(i) == 1){
			printf("%d ", i);
		}
	}
}

int checkPrime(int i){
	int j;
	for (j = 2; j< i; j++){
		if ( i%j == 0 ){
			return 0;
		}
	}
	return 1;
}
