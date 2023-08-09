#include "stdio.h"

void EX_8(){
	char operator,r;
	float op1, op2, result;
	r = 1;
	printf("Enter operator either + or - or * or /: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &operator);

	printf("Enter two operands: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &op1, &op2);

	switch (operator) {
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		default:
			r = 0;
			break;
	}
	if (r == 0)
		printf("Wrong Operator!!!");
	else
		printf("%.2f %c %.2f = %.2f",op1, operator, op2, result);


}
