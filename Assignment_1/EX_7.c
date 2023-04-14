#include "stdio.h"

void EX_7(){
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &a);

	printf("Enter value of b: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &b);

	a = a + b;
	b = a - b;
	a = a - b;

	/* a = a * b;
	 * b = a / b;
	 * a = a / b;
	 * */

	printf("After swapping, value of a = %0.2f\n", a);
	printf("After swapping, value of b = %0.2f\n", b);

}
