#include "stdio.h"

void EX_6(){
	float a,b,temp;
	printf("##########Console-output###\r\n");

	printf("Enter value of a: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &a);

	printf("Enter value of b: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &b);

	temp = a;
	a = b;
	b = temp;

	printf("After swapping, value of a = %0.2f\n", a);
	printf("After swapping, value of b = %0.2f\n", b);
	printf("\r\n###########################");

}
