#include "stdio.h"
void EX_2(void){
	int in;
	printf("Enter a integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &in);
	printf("You entered: %i", in);
}
