/*
 * Q3.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */


#include <stdio.h>
struct SComplex{
	double m_R;
	double m_I;
};

struct SComplex readComplex(void){
	struct SComplex res;
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%lf", &res.m_R);
	scanf("%lf", &res.m_I);
	return res;
}

struct SComplex AddComplex(struct SComplex A,struct SComplex B){
	struct SComplex res = {A.m_R+B.m_R, A.m_I+B.m_I};
	return res;
}

void PrintComplex(struct SComplex A){
	printf("%.1lf+%.1lfi", A.m_R, A.m_I);
}

void Q3(void){
	struct SComplex n1,n2,res;
	printf("For 1st complex number\r\n");
	n1 = readComplex();

	printf("\r\nFor 2st complex number\r\n");
	n2 = readComplex();

	res = AddComplex(n1, n2);
	printf("Sum=");
	PrintComplex(res);
}
