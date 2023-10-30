#include "stdio.h"
void EX_4(){
	float in1, in2;
	printf("##########Console-output###\r\n");

	printf("Enter two numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &in1, &in2);
	printf("Sum: %f", in1 * in2);
	printf("\r\n###########################");
}
