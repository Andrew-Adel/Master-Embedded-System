/*
 * Q5.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include<stdio.h>
#define MAX 100
#define MIN 1
void array_search(void){
    int a[100];
    int n, ind, val, i;

    // get number of elements the user will give to the program
    printf("Enter no of elements : ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &n);

    while (n > MAX || n < MIN)
    {
        printf("WRONG number of data, please enter value between 1 and 100\r\n");
        printf("Enter the number of data again: ");
        fflush(stdin); fflush(stdout);
        scanf("%d", &n);
    }
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the elements to be searched : ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &val);

    for (ind = 0; ind < n; ind++)
    {
        if (a[ind] == val)
            break;
    }
    if (ind < n)
        printf("Number found at the location = %d", ind +1);
    else
        printf("Number is not exist in the array");

}
