/*
 * Q4.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int power(int base, int power){
	int i;
	int res=1;
	for (i=1;i<=power;i++){
		res *= base;
	}
	return res;
}


int asciiToInt(char ascii[][4], int n){

	char integer[3];
	int i, res = 0;



	for(i=0; i<n; i++)
	{


//		strncpy(&integer2[0], ascii+i*4, 4);
		strncpy(integer, ascii[i]+2 ,2);
		int k = atoi(integer)-30;

		int x = power(10,i);
		res += k * x;

		//printf("temp res[i=%d] = %d\n", i, res);

	}

	return res;

}
