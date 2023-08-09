/*
 * Q7.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>

int sumation(int start, int end){
	if ( start > end)
		return 0;
	else if (start == end)
		return start;
	else{
		return start + sumation(start+1, end);
	}

}


void Q7(void){
	int start, end, res;
	printf("Test 1:\nEnter The Start of Range: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &start);
	printf("Enter The End of Range: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &end);

	res = sumation(start, end);
	printf("Sum = %d", res);
}
