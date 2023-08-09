/*
 * Q3.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */


#include<stdio.h>
#include<string.h>
#define MAX 100
void string_reverse(void){
	char str[MAX], rev[MAX];
	int n = 0, i;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	n = strlen(str);

	for ( i = 0; i < n; i++)
	{
		rev[i] = str[n-1-i];
	}
	rev[n] = 0;
	printf("Reverse string is: %s", rev);
}
