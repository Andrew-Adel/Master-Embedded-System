/*
 * Q9.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */



#include <stdio.h>
#include <string.h>

void reverseWords(char str[], char res[]){
	char temp[100];
		char* lastWord;
		strcpy(temp, str);
		strcpy(res, "");

		while (strlen(temp)){
			lastWord = strrchr(temp,' ');
			if (lastWord == 0)
				break;
			strcat(res,strcat(lastWord+1, " "));
			temp[(int)(lastWord-temp)] = '\0';
		}
		strcat(res,temp);
}

void Q9(void){
	char str[100] = "", res[100];
	printf("Test 1:\nEnter The String: ");
	fflush(stdin);fflush(stdout);
	gets(str);

	reverseWords(str, res);
	printf("Reversed Words: %s", res);
}
