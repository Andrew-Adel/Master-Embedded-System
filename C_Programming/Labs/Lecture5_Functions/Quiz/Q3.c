/*
 * Q3.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */

#include <stdio.h>

void reverse(int arr[], int n){
	int i;
	for (i=n-1; i>=0; i--){
		printf("%d, ", arr[i]);
	}
}
