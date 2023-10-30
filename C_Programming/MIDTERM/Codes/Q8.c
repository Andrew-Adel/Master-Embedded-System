/*
 * Q8.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>

void reverseArray(int arr[], int n){
	int i, temp;
	for (i = 0; i < n/2; ++i) {
		temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}

}


void Q8(void){
	int n, arr[100], i;
	printf("Test 1:\nEnter The Number of array: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	printf("Enter The elements: ");
	fflush(stdin);fflush(stdout);
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	reverseArray(arr, n);
	printf("array after reverse: {");
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("}");
}
