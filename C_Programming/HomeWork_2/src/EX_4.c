#include "stdio.h"
void EX_4(){
	float in;
	printf("Enter a number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &in);
	if (in == 0)
		printf("You entered zero");
	else
		printf("%.2f is %s", in, in > 0? "positive":"negative");
}
