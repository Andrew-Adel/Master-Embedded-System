/*
 * Q1.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */

#include <stdio.h>
#include <string.h>
struct SStudent {
	char m_name[50];
	int m_roll;
	float m_marks;
};

struct SStudent readStudent(void){
	struct SStudent student;
	printf("Enter information of student:\r\n");


	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s", student.m_name);

	printf("Enter roll number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &student.m_roll);

	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &student.m_marks);


	return student;
}

void DisplayStudent(struct SStudent student){
	printf("\r\nDisplaying information\r\n");
	printf("name: %s\r\n"
			"Roll: %d\r\n"
			"Marks: %.2f\r\n", student.m_name, student.m_roll, student.m_marks);
}

void Q1(void){
	struct SStudent student = readStudent();
	DisplayStudent(student);
}
