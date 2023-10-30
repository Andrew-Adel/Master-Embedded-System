/*
 * Q3.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include<stdio.h>
#define MAX 10
#define MIN 1

void matrix_transpose(void){
	int r, c, i ,j;
	int a[MAX][MAX], b[MAX][MAX];
	//get data
	printf("Enter row and column of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &r);
	scanf("%d", &c);
	//check the validation of number of columns or row
	while (r > MAX || r < MIN || c > MAX || c < MIN){
		printf("WRONG value of rows or columns, please enter value between 1 and 10\r\n");
		printf("Enter row and column of matrix again: ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &r);
		scanf("%d", &c);
	}

	// get elements from user
	printf("Enter elements of matrix\r\n");
	for ( i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("Enter elements a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d;", &a[i][j]);
			// transpose
			b[j][i] = a[i][j];
		}
	}

	// outputs

	printf("Entered Matrix:\r\n");
	for (int i = 0; i < r; i++)
	{
		for ( j = 0; j < c; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\r\n\r\n");
	}

	printf("Transpose of Matrix:\r\n");
	for ( i = 0; i < c; i++)
	{
		for ( j = 0; j < r; j++)
		{
			printf("%d  ", b[i][j]);
		}
		printf("\r\n");
	}
}
