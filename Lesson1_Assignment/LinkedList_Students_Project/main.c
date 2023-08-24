/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "students.h"

SStudent* gpFirstStudent = NULL;

int main ()
{
	SStudent s1 = {{1, "Andrew Adel", 170.0}, NULL};
	SStudent s2 =  {{2, "Kerollos Shenouda", 172.0}, &s1};
	SStudent s3 =  {{3, "Mina Karam", 180.0}, &s2};
	SStudent s4 =  {{4, "Nabil", 173.0}, &s3};
	SStudent s5 =  {{5, "Marko", 173.0}, &s4};
	//s1.PNextStudent = &s4; // create loop // s5 -> s4 -> s3 -> s2 -> s1 -> s4
	gpFirstStudent = &s5;

	char temp[40];
	while (1)
	{
		DPRINT("\n =====================================");
		DPRINT("\n\t Choose of the following Options \n");
		DPRINT("\n 1: AddStudent ");
		DPRINT("\n 2: DeleteStudent ");
		DPRINT("\n 3: ViewStudents ");
		DPRINT("\n 4: DeleteAll ");
		DPRINT("\n 5: GetNth ");
		DPRINT("\n 6: ListLength ");
		DPRINT("\n 7: GetNth_ByBack ");
		DPRINT("\n 8: GetMiddle ");
		DPRINT("\n 9: CheckLoop ");
		DPRINT("\n 10: ReverseList ");
		DPRINT("\n Enter Option Number: ");
		gets(temp);
		DPRINT("\n =====================================");

		switch (atoi(temp)) {
		case 1:
			AddStudent(&gpFirstStudent);
			break;
		case 2:
			DeleteStudent(&gpFirstStudent);
			break;
		case 3:
			ViewStudents(gpFirstStudent);
			break;
		case 4:
			DeleteAll(&gpFirstStudent);
			break;
		case 5:
			GetNth(gpFirstStudent);
			break;
		case 6:
			ListLength(gpFirstStudent);
			break;
		case 7:
			GetNth_ByBack(gpFirstStudent);
			break;
		case 8:
			GetMiddle(gpFirstStudent);
			break;
		case 9:
			CheckLoop(gpFirstStudent);
			break;
		case 10:
			ReverseList(&gpFirstStudent);
			break;
		default:
			DPRINT("\n Wrong Option");
			break;
		}
	}
}
