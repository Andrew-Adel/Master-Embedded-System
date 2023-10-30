/*
 * Q6.c
 *
 *  Created on: Aug 8, 2023
 *      Author: andre
 */


int fourthLeastSignificantBit(int number){
	int rem = (number>>3);
	rem = rem%2;
	return rem;
}
