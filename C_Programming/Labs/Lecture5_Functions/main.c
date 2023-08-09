/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andre
 */
#include <stdio.h>

int asciiToInt(int ascii[][4], int n);

int main(void)
{
	char ascii[][4] = {"0x31","0x32","0x33", "ox34"};
	int res = asciiToInt(ascii , 4);

	printf("%d",res);

	return 0;
}

