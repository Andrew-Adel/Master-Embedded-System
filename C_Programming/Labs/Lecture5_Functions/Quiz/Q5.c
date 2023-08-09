/*
 * Q5.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */


int ClearBit(int number, int bit){
	int mask = 1 << bit;
	return number & ~mask;
}
