/*
 * Q2.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */


#include<stdio.h>
#define MAX 100
void string_length(void){
	char str[MAX];
	int count = 0, i;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	for ( i = 0; i < MAX && str[i] != 0; i++)
		count++;

	printf("Length of string: %d", count);

}
