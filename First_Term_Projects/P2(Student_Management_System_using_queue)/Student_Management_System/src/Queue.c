/*
 * Queue.c
 *
 *  Created on: Aug 28, 2023
 *      Author: andre
 */


// ---------Include important files

#include "../inc/Queue.h"
// --------- Add Data ---------

Queue_status AddStudent(SQueue_t* q, SStudentInfo_t* head){
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is full
	if (isFull(q)) {
		DPRINT("[ERROR] queue is Full");
		return QUEUE_FULL;
	}

	char temp[50];
	int id, i;

	DPRINT("\n Add The Student Details\n");
	DPRINT("----------------------------");
	DPRINT("\nEnter Student Roll Number: ");
	gets(temp);
	id = atoi(temp);
	if(uniqueID(q,id) == REPEATED_ID){
		DPRINT("[ERROR] This ID is used\n");
		return REPEATED_ID;
	}
	head->roll = id;

	DPRINT("Enter Student First Name: ");
	gets(head->fname);

	DPRINT("Enter Student Last Name: ");
	gets(head->lname);

	DPRINT("Enter Student's GPA: ");
	gets(temp);
	head->GPA = atof(temp);

	DPRINT("Enter The Course ID of each course\n");
	for (i = 0; i < 5; ++i) {
		DPRINT("Course %d id: ", i);
		gets(temp);
		head->cid[i] = atoi(temp);
	}

	return QUEUE_NO_ERROR;
}

// check uniqueness
Queue_status uniqueID(SQueue_t* q, int id){
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}

	int t = q->tail;
	int i;
	for (i = 0; i < q->count; ++i) {
		if(q->base[t].roll == id)
			return REPEATED_ID;
		t = (t + 1)%q->length;
	}

	return QUEUE_NO_ERROR;
}

// ---------Queue Functions---------

Queue_status Queue_Init(SQueue_t* q, SStudentInfo_t* buf, uint32 length){
	// check length of queue
	if (length < 1) {
		printf("[ERROR] Length should be at least = 1\n");
		return QUEUE_ERROR;
	}

	// check if buffer is empty
	if (buf == NULL){
		printf("[ERROR] Empty Buffer");
		return QUEUE_NULL;
	}

	// initialize queue
	q->base = buf;
	q->count = 0;
	q->head = 0;
	q->length = length;
	q->tail = 0;

	//DPRINT("Done");
	return QUEUE_NO_ERROR;
}

Queue_status isEmpty(SQueue_t* q){
	//check buffer
	if (!q->base ) {
		return QUEUE_NULL;
	}
	// if queue is full
	if (q->count == 0) {
		return QUEUE_EMPTY;
	}
	return QUEUE_NO_ERROR;
}

Queue_status isFull(SQueue_t* q){
	//check buffer
	if (!q->base) {
		return QUEUE_NULL;
	}
	// if queue is full
	if (q->count == q->length) {
		return QUEUE_FULL;
	}
	return QUEUE_NO_ERROR;
}

Queue_status DisplayStudentsNumber(SQueue_t* q){
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is full
	if (isEmpty(q)) {
		DPRINT("[INFO] queue is empty");
		return QUEUE_EMPTY;
	}

	DPRINT("-----------------------------------\n");
	DPRINT("[INFO] The Total Number of Students is %lu \n", q->count);
	DPRINT("[INFO] You Can add up to %lu student\n", q->length);
	DPRINT("[INFO] You can add %lu more student\n", q->length - q->count);

	return QUEUE_NO_ERROR;
}

Queue_status Queue_enqueue_ByFile(SQueue_t* q, char* PATH){
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is full
	if (isFull(q)) {
		DPRINT("[ERROR] QUEUE IS FULL");
		return QUEUE_FULL;
	}

	FILE *fptr;
	fptr = fopen(PATH,"r");
	if(fptr == NULL) {
		printf("Not able to open the file.\n");
		return FILE_IS_NULL;
	}
	char chc[100];
	while(fgets(chc,100, fptr)){
		if (q->count < q->length) {
			SStudentInfo_t s;
			sscanf(chc,"%d %s %s %f %d %d %d %d %d", &s.roll, s.fname, s.lname,
					&s.GPA, &s.cid[0],&s.cid[1],&s.cid[2],&s.cid[3],&s.cid[4]);

			if(uniqueID(q, s.roll) != REPEATED_ID ){
				q->base[q->head] = s;
				q->head = (q->head + 1)%q->length;
				q->count++;
				DPRINT("[INFO] Roll Number %d saved successfully\n",s.roll);
			}
			else{
				DPRINT("[ERROR] Roll Number %d is Already taken\n",s.roll);
			}
		}
		else {
			DPRINT("[ERROR] QUEUE IS FULL");
		}
	}
	DisplayStudentsNumber(q);
	fclose(fptr);

	return QUEUE_NO_ERROR;
}


Queue_status Queue_enqueue(SQueue_t* q){
	// ----------check the inputs and buffer----------

	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is full
	if (isFull(q)) {
		DPRINT("[ERROR] QUEUE IS FULL");
		return QUEUE_FULL;
	}

	// ----------insert student into the queue----------
	if ( AddStudent(q,&q->base[q->head]) == REPEATED_ID)
		return REPEATED_ID;
	// circular increment
	q->head = (q->head + 1)%q->length;
	q->count++;
	//DisplayStudentsNumber(q);
	return QUEUE_NO_ERROR;
}

Queue_status Queue_dequeue(SQueue_t* q, SStudentInfo_t* student){
	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is empty
	if (isEmpty(q)) {
		DPRINT("[ERROR] QUEUE IS EMPTY");
		return QUEUE_EMPTY;
	}

	*student = (q->base[q->tail]);
	q->tail = (q->tail + 1)%q->length;
	q->count--;
	DPRINT("Dequeue is Done\n");
	return QUEUE_NO_ERROR;
}

Queue_status Queue_Query(SQueue_t* q,int roll, SStudentInfo_t** student){
	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is empty
	if (isEmpty(q)) {
		DPRINT("[ERROR] QUEUE IS EMPTY");
		return QUEUE_EMPTY;
	}

	int i, cur = q->tail;
	for (i = 0; i < q->count; ++i) {
		if (roll == q->base[cur].roll) {
			*student = &q->base[cur];
			return QUEUE_NO_ERROR;
		}
		cur = (cur+1)%q->length;
	}

	DPRINT("[ERROR] Roll Number %d not found\n", roll);

	return STUDENT_NULL;
}

Queue_status Queue_Query_All_byName(SQueue_t* q,char* temp){
	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is empty
	if (isEmpty(q)) {
		DPRINT("[ERROR] QUEUE IS EMPTY");
		return QUEUE_EMPTY;
	}

	int t = q->tail;
	char flag = 0;
	for (int i = 0; i < q->count; ++i) {
		if(strcmp(q->base[t].fname, temp) == 0){
			PrintStudent(&q->base[t]);
			DPRINT("---------------\n");
			flag = 1;
		}
		t = (t+1)%q->length;
	}

	if (flag == 0){
		DPRINT("[ERROR] First Name %s not found\n", temp);
		return STUDENT_NULL;
	}else{
		return QUEUE_NO_ERROR;
	}
}

Queue_status Queue_Query_All_byCid(SQueue_t* q,int cid){
	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is empty
	if (isEmpty(q)) {
		DPRINT("[ERROR] QUEUE IS EMPTY");
		return QUEUE_EMPTY;
	}

	int t = q->tail;
	int cnt = 0;
	int i,j;
	for ( i = 0; i < q->count; ++i) {
		for (j = 0; j < 5; ++j) {
			if(q->base[t].cid[j] == cid){
				PrintStudent(&q->base[t]);
				cnt++;
			}
		}
		t = (t+1)%q->length;
	}

	if (cnt == 0){
		DPRINT("[ERROR] Course ID %d not found\n", cid);
		return STUDENT_NULL;

	}else{
		DPRINT("[INFO] Total Number of Students Enrolled: %d student(s)\n", cnt);
		return QUEUE_NO_ERROR;
	}
}

Queue_status Queue_Delete_withID(SQueue_t* q, int id){
	//check buffer
	if (!q->base ) {
		DPRINT("[ERROR] Queue is null");
		return QUEUE_NULL;
	}
	// if queue is empty
	if (isEmpty(q)) {
		DPRINT("[ERROR] QUEUE IS EMPTY");
		return QUEUE_EMPTY;
	}

	int t = q->tail;
	int i,j;
	for ( i = 0; i < q->count; ++i) {
		if(q->base[t].roll == id){
			for (j = i; j < q->count-1; ++j) {
				q->base[t] = q->base[t+1];
				t = (t+1)%q->length;
			}
			q->head = (q->length-1)%q->length;
			q->count--;
			return QUEUE_NO_ERROR;
		}
		t = (t+1)%q->length;

	}
	return STUDENT_NULL;
}


