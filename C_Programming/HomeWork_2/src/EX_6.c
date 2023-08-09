#include "stdio.h"

void EX_6(){
	int in,i,sum;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &in);
	sum = 0;
	for (i = 1; i <= in; i++){
		sum += i;
	}
	printf("Sum = %d", sum);

}
