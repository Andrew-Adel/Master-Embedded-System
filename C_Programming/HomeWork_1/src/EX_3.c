#include "stdio.h"
void EX_3(){
	int in1, in2;
	printf("##########Console-output###\r\n");

	printf("Enter two integers: ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d", &in1, &in2);
	printf("Sum: %d", in1 + in2);
	printf("\r\n###########################");
}
