/*
 * students.h
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#ifndef _STUDENTS_H
#define _STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINT(...) printf(__VA_ARGS__);\
					fflush(stdin); fflush(stdout);\

typedef struct {
	int ID;
	char name[40];
	float height;
} SData;

struct Student{
	SData Student_Data;
	struct Student* PNextStudent;
};

typedef struct Student SStudent;


void Fill_the_record(SStudent* new_student);
void AddStudent(SStudent** gpFirstStudent);
int DeleteStudent(SStudent** gpFirstStudent);
void ViewStudents(SStudent* gpFirstStudent);
void DeleteAll(SStudent** gpFirstStudent);

SStudent* GetNth(SStudent* gpFirstStudent);
int ListLength(SStudent* gpFirstStudent);
SStudent* GetNth_ByBack(SStudent* gpFirstStudent);
SStudent* GetMiddle(SStudent* gpFirstStudent);
int CheckLoop(SStudent* gpFirstStudent);
void ReverseList(SStudent** gpFirstStudent);


#endif

