#include "stdio.h"

void EX_7(){
	int in,i,sum;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &in);
	if (in < 0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
		fflush(stdout); fflush(stdin);
	}
	else
	{
		sum = 1;
		for (i = 1; i <= in; i++){
			sum *= i;
		}
		printf("Sum = %d", sum);
		fflush(stdout); fflush(stdin);
	}
}
