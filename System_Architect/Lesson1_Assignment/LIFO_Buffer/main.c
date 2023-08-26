/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "lifo.h"


uint32 buffer1[5];

int main(){
	uint32* buffer2 = (uint32*)malloc(5*sizeof(uint32));

	LIFO_Buf_t uart_lifo, i2c_lifo;

	LIFO_Init(&uart_lifo, buffer1,5); // static
	LIFO_Init(&i2c_lifo, buffer2,5);  // buffer is reserved dynamically in heap

	int i;
	for (i = 0; i < 6; ++i) {
		printf("push item (%d)\n",i);
		if (LIFO_Push_Item(&uart_lifo, i) == LIFO_no_error)
			printf("\t LIFO Push ----- Done\n");
		else {
			printf("\t LIFO Push ----- Faild\n");
		}

	}
	LIFO_print(&uart_lifo);
	uint32 temp;
	for (i = 0; i < 6; ++i) {
		if (LIFO_Pop_Item(&uart_lifo, &temp) == LIFO_no_error) {
			printf("\n LIFO pop ----- Done\n");
			printf("\t LIFO pop (%d)\n", temp);

		} else {
			printf("\n\t LIFO dequeue ----- Faild");
		}
	}
	LIFO_print(&uart_lifo);

	return 0;
}
