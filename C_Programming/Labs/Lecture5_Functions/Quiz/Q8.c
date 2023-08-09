/*
 * Q8.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */


int lastOccurence(int arr[], int n, int numberToFind){
	int i = n-1;
	for(;i>=0;i--){
		if(arr[i] == numberToFind){
			return i;
		}
	}
	return -1;
}
