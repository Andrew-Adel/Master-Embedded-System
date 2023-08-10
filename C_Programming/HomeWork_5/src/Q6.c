/*
 * Q6.c
 *
 *  Created on: Aug 10, 2023
 *      Author: andre
 */

#include <stdio.h>

union job{
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1{
	char name[32];
	float salary;
	int worker_no;
}s;

void Q6(void){
	printf("size of union=%d", sizeof(u));
	printf("\nsize of union=%d", sizeof(s));

}
