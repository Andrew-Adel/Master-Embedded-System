/*
 * students.h
 *
 *  Created on: Aug 28, 2023
 *      Author: andre
 */

// ---------Avoid Repetition of File---------

#ifndef _STUDENTS_H
#define _STUDENTS_H

// ---------Including needed libraries---------

#include "../inc/platform_types.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/Queue.h"

// ---------Student Functions---------

// add students from external file
void add_student_file(void);
// add student manually in console
void add_student_manually(void);
// Find the Student Details by Roll Number
void find_rl(void);
// Find the Student Details by First Name
void find_fn(void);
// Find the Student Details by Course Id
void find_c(void);
// Find the Total Number of Students
void tot_s(void);
// Delete the Students Details by Roll Number
void del_s(void);
// Update the Students Details by Roll Number
void up_s(void);
// Show all Information
void show_s(void);

// // Print data of specific student
void PrintStudent(SStudentInfo_t *student);
// Print data of all students
void PrintAllStudents(SQueue_t* q);

#endif
