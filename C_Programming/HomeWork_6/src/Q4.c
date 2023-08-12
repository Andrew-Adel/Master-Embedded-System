/*
 * Q4.c
 *
 *  Created on: Aug 12, 2023
 *      Author: andre
 */


#include <stdio.h>
#define MAX 15
void Q4(void){
	int arr[MAX];
	int *ptr;
	int num,i;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	ptr = arr;
	printf("Input 5 number of elements in the array :\n");
	for (i = 0; i < num; ++i) {
		printf("element - %d : ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d", ptr++);
	}
	ptr--;
	printf("\n\nThe elements of array in reverse order are : \n");
	for (i = num; i > 0; --i) {
		printf("element - %d : %d\n", i, *(ptr--));
	}
}
