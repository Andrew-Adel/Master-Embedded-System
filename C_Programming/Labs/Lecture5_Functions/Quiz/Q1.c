/*
 * Q1.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */

#include <string.h>

int findNamee(char names[][14], int n, char name[]){
	int i;
	for (i = 0; i < n; i++){
		if (strcmp(names[i],name) == 0){
			return 1;
		}

	}
	return 0;
}
