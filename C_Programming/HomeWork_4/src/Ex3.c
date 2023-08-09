/*
 * Ex3.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */


#include <stdio.h>
void rev(char str[], int i);
void ProgramReversingCall(void){
	char str[100];
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	rev(str, 0);
}
void rev(char str[], int i){
	if (str[i] == 0){
		return;
	}
	rev(str, i+1);
	printf("%c", str[i]);
}
