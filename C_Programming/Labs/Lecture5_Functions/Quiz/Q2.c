/*
 * Q2.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */


void swap(int arr1[], int n1, int arr2[], int n2){
	int min = n1<n2? n1:n2;
	int i, temp;
	for (i= 0; i<min; i++){
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
