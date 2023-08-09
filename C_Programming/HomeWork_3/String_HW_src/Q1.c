/*
 * Q1.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */

#include<stdio.h>
#define MAX 100
void char_freq(void){
    char str[MAX];
    int freq = 0, i;
    char c;

    printf("Enter a string: ");
    fflush(stdin); fflush(stdout);
    gets(str);

    printf("Enter a character to find frequency: ");
    fflush(stdin); fflush(stdout);
    scanf("%c", &c);
    for ( i = 0; i < MAX && str[i] != 0; i++){
        if (str[i] == c)
            freq++;
    }
    printf("Frequency of %c = %d", c, freq);

}
