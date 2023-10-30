/*
 * Q1.c
 *
 *  Created on: Aug 12, 2023
 *      Author: andre
 */

#include <stdio.h>
void Q1(void){
	int m = 29, *ab;
	printf("Address of m : 0x%x\n Value of m : %d\r\n", (unsigned int)&m, m);
	ab = &m;
	printf("Now ab is assigned with the address of m.\n");

	printf("Address of pointer ab : 0x%x\nContent of pointer ab : %d\r\n", (unsigned int)ab, *ab);
	m=34;
	printf("The value of m assigned to %d now.\n", m);

	printf("Address of pointer ab : 0x%x\nContent of pointer ab : %d", (unsigned int)ab, *ab);

}
