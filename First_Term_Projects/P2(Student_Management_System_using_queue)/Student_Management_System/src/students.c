/*
 * students.c
 *
 *  Created on: Aug 28, 2023
 *      Author: andre
 */


// ---------Include important files

#include "../inc/students.h"

// ---------Student Functions---------

// Print Student
void PrintStudent(SStudentInfo_t *student){
	int i;

	DPRINT("=>The Student Details are<=\n")
	DPRINT("The First Name is %s\n", student->fname);
	DPRINT("The Last Name is %s\n", student->lname);
	DPRINT("The Roll Number is %d\n", student->roll);
	DPRINT("The GPA is %.2f\n", student->GPA);
	DPRINT("The Student Courses' ID:\n")
	for (i = 0; i < 5; ++i) {
		DPRINT("  The Course Id is %d\n",student->cid[i]);
	}
}
// Print data of All Students
void PrintAllStudents(SQueue_t* q){
	int i;
	int t = q->tail;
	for (i = 0; i < q->count; ++i) {
		PrintStudent(&q->base[t]);
		DPRINT("----------------------------------\n");
		t = (t+1)%q->length;
	}
}

void add_student_file(void){
	DPRINT("Enter Path of Text File:\n");
	char path[100];
	gets(path);
	Queue_enqueue_ByFile(&queue, path);

}

void add_student_manually(void){
	if(Queue_enqueue(&queue) == QUEUE_NO_ERROR){
		DPRINT("[INFO] Student Details is added Successfully\n");
		DisplayStudentsNumber(&queue);
	}
}

void find_rl(void){
	int id;
	DPRINT("Enter The Roll Number of The Student: ");
	scanf("%d", &id);
	SStudentInfo_t* student = NULL;
	Queue_status stat = Queue_Query(&queue, id, &student);
	if ( stat == QUEUE_NO_ERROR) {
		PrintStudent(student);
	} else if(stat == QUEUE_EMPTY){
		DPRINT("[ERROR] Empty Queue\n");
	}

}

void find_fn(void){
	char temp[50];
	DPRINT("Enter The First Name of The Student: ");
	scanf("%s",temp);

	Queue_Query_All_byName(&queue, temp);
}

void find_c(void){
	DPRINT("Enter Course Id that registered by students: ");
	int temp;
	scanf("%d", &temp);
	Queue_Query_All_byCid(&queue,temp);
}


void tot_s(void){
	DisplayStudentsNumber(&queue);

}
void up_s(void){
	char temp[50], temp2[50];
	DPRINT("Enter The Roll Number to update the entry: ");
	gets(temp);
	SStudentInfo_t* student = NULL;
	if( Queue_Query(&queue, atoi(temp), &student) == STUDENT_NULL )
		return;

	DPRINT("1. first name\n");
	DPRINT("2. last name\n");
	DPRINT("3. roll no\n");
	DPRINT("4. GPA\n");
	DPRINT("5. courses\n");
	DPRINT("Enter Number of field to be update: ");
	gets(temp);
	int i;
	DPRINT("-----------")
	switch (atoi(temp)) {
	case 1:
		DPRINT("\n Enter The New First Name: ");
		gets((student)->fname);
		break;
	case 2:
		DPRINT("\n Enter The New Last Name: ");
		gets((student)->lname);
		break;
	case 3:
		DPRINT("\n Enter The New Roll Number: ");
		gets(temp2);

		if (uniqueID(&queue, atoi(temp2)) != REPEATED_ID) {
			(student)->roll = atoi(temp2);
		}else{
			DPRINT("[ERROR] Roll Number %d is Already taken\n",atoi(temp2));
			return;
		}
		break;
	case 4:
		DPRINT("\n Enter The New GPA: ");
		gets(temp2);
		(student)->GPA = atof(temp2);
		break;
	case 5:
		DPRINT("Enter The Course ID of each course\n");
		for (i = 0; i < 5; ++i) {
			DPRINT("Course %d id: ", i);
			gets(temp);
			(student)->cid[i] = atoi(temp);
		}
		break;
	default:
		DPRINT("[ERROR] Wrong Choice\n");
		return;
		break;
	}

	DPRINT("[INFO] UPDATE SUCCESSFULLY\n");

}

void del_s(void){
	int id;
	DPRINT("Enter The Roll Number which you want to be deleted: ");
	scanf("%d",&id);
	Queue_status status = Queue_Delete_withID(&queue, id);
	if (status == QUEUE_NO_ERROR){
		DPRINT("[INFO] Student with Roll Number (%d) has removed Successfully\n", id);
		DisplayStudentsNumber(&queue);
	}
	else if (status == STUDENT_NULL){
		DPRINT("[ERROR] The Roll Number %d not found\n", id);
	}

}

void show_s(void){
	PrintAllStudents(&queue);
}
