/*
 * Q4.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */
#include<stdio.h>
#define MAX 100
#define MIN 1

void array_insert(void){
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

    printf("Enter the elements to be inserted : ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &val);
    printf("Enter the location : ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &ind);
    while (ind > n || ind < 1)
    {
        printf("the index is not exist in range (1, %d)\r\n", n);
        printf("Enter the location : ");
        fflush(stdin); fflush(stdout);
        scanf("%d", &ind);
    }

    ind--;
    a[ind] = val;
    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

}
