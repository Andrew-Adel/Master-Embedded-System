/*
 * lab2.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andrew
 */

int calcMin(int arr[], int n){
	int min = arr[0], i = 1;
	for (; i<n; i++){
		if(min > arr[i]){
			min = arr[i];
		}
	}
	return min;
}
