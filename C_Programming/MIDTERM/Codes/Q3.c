/*
 * Q3.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>
int checkPrime(int i){
	int j;
	for (j = 2; j< i; j++){
		if ( i%j == 0 ){
			return 0;
		}
	}
	return 1;
}

void PrimeNumbers(int start, int end){
	int i;
	for (i = start; i <= end; ++i) {
		if(checkPrime(i))
			printf("%d ", i);
	}
}


void Q3(void){
	int start, end;
	printf("Test 1:\nEnter The Start of Range: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &start);
	printf("Enter The End of Range: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &end);

	PrimeNumbers(start, end);
}
