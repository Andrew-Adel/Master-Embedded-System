#include "stdio.h"
void EX_2(void){
	int in;
	printf("##########Console-output###\r\n");

	printf("Enter a integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &in);
	printf("You entered: %i", in);
	printf("\r\n###########################");
}
