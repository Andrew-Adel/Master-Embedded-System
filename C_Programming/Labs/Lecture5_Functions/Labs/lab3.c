/*
 * lab3.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */

#include <string.h>
int findName(char names[][14], int n, char name[]){
	int i;
	for (i = 0; i < n; i++){
		int x = (strcmp(names[i],name) == 0);
		if (strcmp(names[i],name) == 0){
			return 1;
		}

	}
	return 0;
}
