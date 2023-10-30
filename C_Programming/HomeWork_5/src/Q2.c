/*
 * Q2.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */
#include <stdio.h>

struct SFDistance{
	int m_feet;
	float m_inch;
};

struct SFDistance ReadDistance (void){
	struct SFDistance res;
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &res.m_feet);

	printf("Enter inch: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &res.m_inch);


	return res;
}

struct SFDistance AddDistance (struct SFDistance d1, struct SFDistance d2){
	struct SFDistance res;
	float inchs = d1.m_inch + d2.m_inch;
	res.m_feet = d1.m_feet + d2.m_feet + inchs/12;
	int inchs_rem = ((int)inchs)%12;
	res.m_inch = inchs_rem + inchs - ((int)inchs);

	return res;
}

void DisplayResult(struct SFDistance res){
	printf("\r\nSum of distance=%d\'-%.1f\"",res.m_feet, res.m_inch);
}

void Q2(void){
	struct SFDistance d1, d2, res;
	printf("Enter information for 1st distance\r\n");
	d1 = ReadDistance();
	printf("\r\nEnter information for 2nd distance\r\n");
	d2 = ReadDistance();
	res = AddDistance(d1, d2);
	DisplayResult(res);
}
