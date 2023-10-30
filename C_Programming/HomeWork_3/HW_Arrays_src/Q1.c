/*
 * Q1.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include <stdio.h>
#define n 2

void matix_sum(void){
	float a[n][n], b[n][n], sum[n][n];
	printf("Enter the elements of 1st matix:\r\n");
	int i,j;
	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f;", &a[i][j]);
		}
	}

	printf("\r\nEnter the elements of 2nd matix:\r\n");
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f;", &b[i][j]);
		}
	}
	for ( i = 0; i < n; i++)
		for ( j = 0; j < n; j++)
			sum[i][j] = a[i][j] + b[i][j];

	printf("\r\nSum Of Matrix:\r\n");
	for ( i = 0; i < n; i++){
		for ( j = 0; j < n; j++){
			printf("%.1f", sum[i][j]);
			if (j+1 < n)
			{
				printf("\t");
			}
		}
		printf("\r\n");
	}
}
