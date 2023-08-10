/*
 * Q4.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */



#include <stdio.h>
#include <string.h>
#define SIZE 10

struct SStudent {
	char m_name[50];
	int m_roll;
	float m_marks;
};

struct SStudent readOneStudent(int i){
	struct SStudent student;

	student.m_roll = i;
	printf("\nFor roll number %d\n", i);
	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s", student.m_name);

	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &student.m_marks);


	return student;
}

void DisplayStudents(struct SStudent students[], int n){
	int i;
	printf("\r\nDisplaying information of students\r\n");
	for (i = 0; i < n; ++i) {
		printf("information for roll number %d:\n"
				"name: %s\n"
				"Marks: %.2f\r\n",students[i].m_roll, students[i].m_name, students[i].m_marks);

	}
}

void FullingStudentArray(struct SStudent students[], int n){
	int i;
	printf("Enter information of students:\n");

	for (i = 1; i <= n; ++i) {
		students[i-1] = readOneStudent(i);
	}
}


void Q4(void){
	struct SStudent students[SIZE];
	FullingStudentArray(students, SIZE);
	DisplayStudents(students, SIZE);
}
