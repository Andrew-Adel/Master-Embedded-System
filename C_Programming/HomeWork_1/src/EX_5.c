#include "stdio.h"

void EX_5(){
	char in;
	printf("##########Console-output###\r\n");

	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &in);
	printf("ASCII value of %c = %d", in,in);
	printf("\r\n###########################");
}
