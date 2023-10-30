/*
 * Q2.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include<stdio.h>
#define MAX 100
#define MIN 1
void calc_Avg(void){
    float a[100], sum, avg;
    int n,i;

    // get number of elements the user will give to the program
    printf("Enter the number of data: ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &n);

    while (n > MAX || n < MIN)
    {
        printf("WRONG number of data, please enter value between 1 and 100\r\n");
        printf("Enter the number of data again: ");
        fflush(stdin); fflush(stdout);
        scanf("%d", &n);
    }


    // get data from user

    for ( i = 0; i < n; i++)
    {
        printf("%d. Enter number: ",i+1);
        fflush(stdin); fflush(stdout);
        scanf("%f", &a[i]);
        // calc sum
        sum += a[i];
    }
    // calc average
    avg = sum/n;

    printf("Average = %.2f", avg);
}
