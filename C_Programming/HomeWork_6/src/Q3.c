/*
 * Q3.c
 *
 *  Created on: Aug 12, 2023
 *      Author: andre
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

void Q3(void){
	char str[MAX];
	char* ptr;
	int i;
	printf("Input a string : ");
	fflush(stdin);fflush(stdout);
	fgets(str,MAX, stdin);


	ptr = str+strlen(str)-2;
	printf("Reverse of the string is : ");
	for (i = 0; i < strlen(str); ++i) {
		printf("%c", *(ptr-i));
	}

}
