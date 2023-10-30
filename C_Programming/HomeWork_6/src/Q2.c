/*
 * Q2.c
 *
 *  Created on: Aug 12, 2023
 *      Author: andre
 */

#include <stdio.h>
#define nAlphapets 26

void Q2(void){
	char alphabets[nAlphapets];
	char* ptr = alphabets;
	int i;

	for (i = 0; i < nAlphapets; ++i) {
		*(ptr+i) = 'A' + i;
	}

	printf("Alphabets : ");
	for (i = 0; i < nAlphapets; ++i) {
		printf("%c ", *(ptr+i));
	}
}
