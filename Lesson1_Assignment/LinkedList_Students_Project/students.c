/*
 * students.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "students.h"


void Fill_the_record(SStudent* new_student){
	char temp[40];

	DPRINT("\n Enter the ID: ");
	gets(temp);
	new_student->Student_Data.ID = atoi(temp);

	DPRINT("Enter Student Full Name: ");
	gets(new_student->Student_Data.name);

	DPRINT("Enter the height: ");
	gets(temp);
	new_student->Student_Data.height = atof(temp);

}

void AddStudent(SStudent** gpFirstStudent ){
	//pointer to refer to new student
	SStudent* pNewStudent;

	// if list is empty
	if (gpFirstStudent == NULL) {
		// create new student by dynamic allocation
		pNewStudent = (SStudent*) malloc ( sizeof(SStudent) );
		// assign first student to the list
		*gpFirstStudent = pNewStudent;
	} else { // list is not empty
		// navigate through all student until reach the end of the list
		pNewStudent = *gpFirstStudent;
		while(pNewStudent->PNextStudent){
			// refer to next student in list as it is not empty
			pNewStudent = pNewStudent->PNextStudent;
		}
		// create new student by dynamic allocation and assign it in the last of list
		pNewStudent->PNextStudent = (SStudent*) malloc ( sizeof(SStudent) );
		// refer to new student has been created
		pNewStudent = pNewStudent->PNextStudent;
	}
	// fill the new student
	Fill_the_record(pNewStudent);
	// make the next student of new student be null
	pNewStudent->PNextStudent = NULL;
}

int DeleteStudent(SStudent** gpFirstStudent)
{
	char temp[40];
	int selected_id;
	// get id of student to be deleted
	DPRINT("\n Enter Student ID to be deleted: ");
	gets(temp);
	selected_id = atoi(temp);

	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("Empty List!!!");
	} else
	{
		SStudent* pSelectedStudent = *gpFirstStudent;
		SStudent* pPreviousStudent = NULL;
		// navigate list until reach the student with this id
		while(pSelectedStudent)
		{
			if(pSelectedStudent->Student_Data.ID == selected_id)
			{
				if(!pPreviousStudent){
					*gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				else
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				//delete student with selected id
				free(pSelectedStudent);
				DPRINT("\n Student with id (%d) has been deleted\n", selected_id);
				return 1;
			}
			// check the next student
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
		DPRINT("No student with ID = (%d)!!!", selected_id);
	}
	return 0;
}

void ViewStudents(SStudent* gpFirstStudent)
{
	int count = 1;
	SStudent* pSelectedStudent = gpFirstStudent;
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return;
	}
	// looping on list until the end
	while(pSelectedStudent)
	{
		// print data of student
		DPRINT("\n Record Number (%d)", count);
		DPRINT("\n ID: %d",pSelectedStudent->Student_Data.ID)
		DPRINT("\n Name: %s",pSelectedStudent->Student_Data.name)
		DPRINT("\n Height: %f",pSelectedStudent->Student_Data.height)
		DPRINT("\n-----------------------")
		// point to next student
		pSelectedStudent = pSelectedStudent->PNextStudent;
		// increment counter
		count++;
	}

}

void DeleteAll(SStudent** gpFirstStudent)
{
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return;
	}
	SStudent* pCurrentStudent = *gpFirstStudent;
	SStudent* pTempStudent = NULL;

	while(pCurrentStudent)
	{
		pTempStudent = pCurrentStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
		free(pTempStudent);
	}
	DPRINT("\n All student has been deleted \n");
	*gpFirstStudent = NULL;
}

SStudent* GetNth(SStudent* gpFirstStudent){
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return NULL;
	}
	char temp[40];
	int n;
	DPRINT("\n Enter Index of Student to be Found: ");
	gets(temp);
	n = atoi(temp);

	int i;
	SStudent* pCurrentStudent = gpFirstStudent;
	for (i = 0; i < n; ++i) {
		pCurrentStudent = pCurrentStudent->PNextStudent;
		if (!pCurrentStudent) {
			DPRINT("List contain (%d) elements which is less than your index", i+1);
			return NULL;
		}
	}
	DPRINT("\n Target Student with index (%d) has\n ID = %d, name = %s, height = %f\n",n,pCurrentStudent->Student_Data.ID, pCurrentStudent->Student_Data.name, pCurrentStudent->Student_Data.height);
	return pCurrentStudent;
}

// use for ListLength function
static int getCount(SStudent* pCurrentStudent){
	if(!pCurrentStudent)
		return 0;
	return getCount(pCurrentStudent->PNextStudent)+1;
}

int ListLength(SStudent* gpFirstStudent){
	int res = getCount(gpFirstStudent);
	DPRINT("\n\t Length of List = %d", res);
	return res;
}

SStudent* GetNth_ByBack(SStudent* gpFirstStudent){
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return NULL;
	}
	char temp[40];
	int n;
	DPRINT("\n Enter Index of Student to be Found from End: ");
	gets(temp);
	n = atoi(temp);

	int i;
	SStudent* pCurrentStudent, *pLastStudent;
	pCurrentStudent = gpFirstStudent;
	pLastStudent = gpFirstStudent;

	for (i = 1; i < n; ++i) {
		pLastStudent = pLastStudent->PNextStudent;
		//check if length of list less than number needed to get index
		if (!pLastStudent) {
			DPRINT("List contain (%d) elements which is less than your index", i+1);
			return NULL;
		}
	}
	while(pLastStudent->PNextStudent){
		pLastStudent = pLastStudent->PNextStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	DPRINT("\n Target Student with index (%d) has\n ID = %d, name = %s, height = %f\n",n,pCurrentStudent->Student_Data.ID, pCurrentStudent->Student_Data.name, pCurrentStudent->Student_Data.height);

	return pCurrentStudent;

}

SStudent* GetMiddle(SStudent* gpFirstStudent){
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return NULL;
	}

	SStudent* pCurrentStudent = gpFirstStudent;
	SStudent* pFastStudent = gpFirstStudent;

	while((pFastStudent) && (pFastStudent->PNextStudent) ){
		pFastStudent = pFastStudent->PNextStudent->PNextStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	DPRINT("\n Target Student in Middle has:\n ID = %d, name = %s, height = %f\n",pCurrentStudent->Student_Data.ID, pCurrentStudent->Student_Data.name, pCurrentStudent->Student_Data.height);
	return pCurrentStudent;

}

int CheckLoop(SStudent* gpFirstStudent){
	//check if list is empty
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return 0;
	}
	SStudent* pSlowStudent = gpFirstStudent;
	SStudent* pFastStudent = gpFirstStudent;

	while(pFastStudent && pFastStudent->PNextStudent){
		pFastStudent = pFastStudent->PNextStudent->PNextStudent;
		pSlowStudent = pSlowStudent->PNextStudent;
		if (pFastStudent == pSlowStudent) {
			DPRINT("\n there is a loop!!! \n");
			return 1;
		}
	}
	DPRINT("\n there is No loop \n");
	return 0;

}

void ReverseList(SStudent** gpFirstStudent){
	if (!gpFirstStudent)
	{
		DPRINT("\n Empty List!!!");
		return ;
	}
	SStudent* pPrev, *pCurrent, *pNext;
	pCurrent = *gpFirstStudent;
	while (pCurrent)
	{
		pNext = pCurrent->PNextStudent;
		pCurrent->PNextStudent = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	*gpFirstStudent = pPrev;
	DPRINT("\n\tReverse Done Successfully\n")
}

