/*
 * Queue.h
 *
 *  Created on: Aug 28, 2023
 *      Author: andre
 */

// ---------Avoid Repetition of File---------

#ifndef _QUEUE_H
#define _QUEUE_H

// ---------Including needed libraries---------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "platform_types.h"

// ---------MACROS---------

#define MAX_QUEUE_LENGTH 50

// ---------Printing on Console---------

#define DPRINT(...) fflush(stdin); fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin); fflush(stdout);

// ---------Queue Data type---------
#define MAX_NAME_LENGTH 50

typedef struct {
	char fname[MAX_NAME_LENGTH];
	char lname[MAX_NAME_LENGTH];
	int roll;
	float GPA;
	int cid[10];
}SStudentInfo_t;

typedef struct {
	uint32 length;
	uint32 count;
	SStudentInfo_t* base;
	int head;
	int tail;
}SQueue_t;

SStudentInfo_t st[MAX_QUEUE_LENGTH];
SQueue_t queue;

// prototypes

void PrintStudent(SStudentInfo_t *student);

// ---------Queue Status---------

typedef enum{
	QUEUE_NO_ERROR,
	QUEUE_FULL,
	QUEUE_EMPTY,
	QUEUE_NULL,
	QUEUE_ERROR,
	STUDENT_NULL,
	REPEATED_ID,
	FILE_IS_NULL
}Queue_status;

// ---------Queue Functions---------
// Add Data
Queue_status AddStudent(SQueue_t* q, SStudentInfo_t* head);
// check uniqueness of given id (roll no.)
Queue_status uniqueID(SQueue_t* q, int id);
// initialize the queue
Queue_status Queue_Init(SQueue_t* q, SStudentInfo_t* buf, uint32 length);
// check if queue is empty
Queue_status isEmpty(SQueue_t* q);
// check if queue is full
Queue_status isFull(SQueue_t* q);
// display total number of student in the queue
Queue_status DisplayStudentsNumber(SQueue_t* q);
// enqueue student into queue from a file
Queue_status Queue_enqueue_ByFile(SQueue_t* q, char* PATH);
// enqueue student manually into queue
Queue_status Queue_enqueue(SQueue_t* q);
// dequeue from queue and return it inside the student argument
Queue_status Queue_dequeue(SQueue_t* q, SStudentInfo_t* student);
// Search inside queue about a specific student by its roll number
Queue_status Queue_Query(SQueue_t* q,int roll, SStudentInfo_t** student);
// Search inside queue about a specific student by its first name
Queue_status Queue_Query_All_byName(SQueue_t* q,char* temp);
// Search inside queue about a specific student by its courses
Queue_status Queue_Query_All_byCid(SQueue_t* q,int cid);
// delete specific student from queue by its roll number
Queue_status Queue_Delete_withID(SQueue_t* q, int id);

#endif
