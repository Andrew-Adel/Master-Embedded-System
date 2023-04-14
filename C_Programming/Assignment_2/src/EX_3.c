#include "stdio.h"
void EX_3(){
	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f %f", &a, &b, &c);
	printf("Largest number = %f", a > b ? a : (b > c? b : c) );
}
