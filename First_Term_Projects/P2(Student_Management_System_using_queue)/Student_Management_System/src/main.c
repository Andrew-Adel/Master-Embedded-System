/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *      Author: andre
 */


#include "../inc/Queue.h"
#include "../inc/students.h"

int main(){
	int choice;
	if (Queue_Init( &queue, st, 50)!= QUEUE_NO_ERROR) {
		DPRINT("[ERROR] Cannot Initialize");
		return 0;
	}
	//	add_student_file();
	//	find_rl();
	DPRINT("Welcome to The Student Management System\n");
	while(1){
		DPRINT("=============================================================\n");
		DPRINT("Choose the Task That You Want to Perform\n");
		DPRINT("1. Add The Student Details Manually\n");
		DPRINT("2. Add Student Details From Text\n");
		DPRINT("3. Find Student Details by Roll Number\n");
		DPRINT("4. Find Student Details by First Name\n");
		DPRINT("5. Find Student Details by Course ID\n");
		DPRINT("6. Find The Total Number of Students\n");
		DPRINT("7. Delete Student Details by Roll Number\n");
		DPRINT("8. Update Student Details by Roll Number\n");
		DPRINT("9. Show All Information\n");
		DPRINT("10.Exit\n");
		DPRINT("Enter Your Choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			add_student_manually();
			break;
		case 2:
			add_student_file();
			break;
		case 3:
			find_rl();
			break;
		case 4:
			find_fn();
			break;
		case 5:
			find_c();
			break;
		case 6:
			tot_s();
			break;
		case 7:
			del_s();
			break;
		case 8:
			up_s();
			break;
		case 9:
			show_s();
			break;
		case 10:
			DPRINT("=============================================================\n");
			DPRINT("Thank you for using Student Management System Program :) \n");
			DPRINT("Goodbye\n");
			DPRINT("=============================================================\n");
			return 0;
			break;
		default:
			DPRINT("########### WRONG CHOICE ###########");
			break;
		}
	}


	return 0;
}
