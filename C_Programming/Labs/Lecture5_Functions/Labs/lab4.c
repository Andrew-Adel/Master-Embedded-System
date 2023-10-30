/*
 * lab4.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */


void produceTriangleNumber(int x){
	int i,j;
	for	(i = 0; i<= x; i++){
		for	(j = i; j<= x; j++){
			printf("%d ", j);
		}
		printf("\r\n");
	}
}
