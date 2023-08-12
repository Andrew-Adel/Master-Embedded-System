/*
 * Q5.c
 *
 *  Created on: Aug 12, 2023
 *      Author: andre
 */


#include <stdio.h>
#include <string.h>
#define N_EMP 3
#define MAX_NAME_LENGTH 32
struct SEmployee{
	char m_name[MAX_NAME_LENGTH];
	int m_ID;
};

void Q5(void){
	struct SEmployee employees[N_EMP];
	struct SEmployee *P_employees[N_EMP];
	struct SEmployee* (*P_A_Employees)[] = &P_employees;

	int i;

	for (i = 0; i < N_EMP; ++i) {


		printf("Enter employee %d name : ",i+1);
		fflush(stdin);fflush(stdout);
		fgets(employees[i].m_name, MAX_NAME_LENGTH, stdin);
		// fix new line problem in fgets()
		employees[i].m_name[strlen(employees[i].m_name)-1] = '\0';

		printf("Enter employee %d ID : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d", &employees[i].m_ID);

		P_employees[i] = &employees[i];
	}
	printf("\nYour entered data:\n");
	for (i = 0; i < N_EMP; ++i) {
		//printf("")
		printf("Employee %d has Name : %s, and ID : %d\n",i+1, (**(*P_A_Employees +i)).m_name,
				(**(*P_A_Employees+i)).m_ID);
	}
	printf("\n\nrequested pointer is written in : struct SEmployee* (*P_A_Employees)[]\n");
	printf("Employee name can be printed by:\n");
	printf("**(*P_A_Employees +i)).m_name \n*(*P_A_Employees+i)->m_name\n");
	printf("**(*&P_Employees +i)).m_name \n*(*&P_Employees+i)->m_name\n");
	printf("**(*P_A_Employees +i)).m_name \n*(*P_A_Employees+i)->m_name");
	printf("(employee+i).m_name\n");

	printf("Employee ID can be printed by:\n");
	printf("**(*P_A_Employees +i)).m_ID \n*(*P_A_Employees+i)->m_ID\n");
	printf("**(*&P_Employees +i)).m_ID \n*(*&P_Employees+i)->m_ID\n");
	printf("**(*P_A_Employees +i)).m_ID \n*(*P_A_Employees+i)->m_ID\n");
	printf("(employee+i).m_ID\n");

}
