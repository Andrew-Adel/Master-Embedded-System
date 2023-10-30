/*
 * lab1.c
 *
 *  Created on: Aug 7, 2023
 *      Author: andrew
 */


int factorial(int x){

	int i, res = 1;
	for (i = 2; i <= x; i++){
		res = res * i;
	}
	return res;
}
