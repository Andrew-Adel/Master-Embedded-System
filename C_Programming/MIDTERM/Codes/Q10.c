/*
 * Q10.c
 *
 *  Created on: Aug 9, 2023
 *      Author: andre
 */


#include <stdio.h>
#include <string.h>

short MaxSequenceOnes(int num){
	int max = 0, temp, rem;
	while (num != 0){

		rem = num %2;
		temp += rem;
		if (rem == 0){
			if (temp > max)
				max = temp;
			temp = 0;
		}
		num /=2;
	}
	if (temp > max)
		max = temp;
	return max;
}

void Q10(void){
	int num,res;
	printf("Test 1:\nEnter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);

	res = MaxSequenceOnes(num);
	printf("Max number of ones between two zeros = %d", res);

	printf("\nTest 2:\nEnter a number: ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);

		res = MaxSequenceOnes(num);
		printf("Max number of ones between two zeros = %d", res);


}
