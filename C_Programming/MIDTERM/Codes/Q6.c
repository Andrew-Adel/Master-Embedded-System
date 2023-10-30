/*
 * Q6.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>
int UniqueNumber(int arr[],int n){
	int i, unique = 0, count[100] = {0};
	for (i = 0; i < n; ++i) {
		if( count[arr[i]] == 0 || count[arr[i]] == 1){
			unique ^= arr[i];
			count[i]++;
		}
	}
	return unique;

}


void Q6(void){
	int n, arr[100], i, res;

	printf("Test 1:\nEnter The Number of array: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	printf("Enter The elements: ");
	fflush(stdin);fflush(stdout);
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	res = UniqueNumber(arr, n);
	printf("Unique Element = %d", res);

	printf("\nTest 2:\nEnter The Number of array: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	printf("Enter The elements: ");
	fflush(stdin);fflush(stdout);
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	res = UniqueNumber(arr, n);
	printf("Unique Element = %d", res);

}
