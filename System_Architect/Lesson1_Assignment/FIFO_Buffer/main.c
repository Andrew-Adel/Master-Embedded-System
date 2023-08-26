/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "fifo.h"
int main(){
	FIFO_Buf_t fifo_UART;
	element_type i, temp;
	if (FIFO_Init(&fifo_UART,uart_buffer, width1) == FIFO_no_error) {
		printf("FIFO init ----- Done\n");
	} else {
		printf("FIFO init ----- Faild");
		exit(1);
	}
	for (i = 0; i < width1+2; ++i) {
		printf("FIFO enqueue (%d):\n",i*2);
		if (FIFO_enqueue(&fifo_UART,i*2) == FIFO_no_error) {
			printf("\t FIFO enqueue ----- Done\n");
		} else {
			printf("\t FIFO enqueue ----- Faild\n");
		}
	}
	FIFO_print(&fifo_UART);

	if (FIFO_dequeue(&fifo_UART,&temp) == FIFO_no_error) {
		printf("FIFO dequeue ----- Done\n");
		printf("\t FIFO dequeue (%d)\n", temp);

	} else {
		printf("\t FIFO dequeue ----- Faild");
	}
	if (FIFO_dequeue(&fifo_UART,&temp) == FIFO_no_error) {
		printf("FIFO dequeue ----- Done\n");
		printf("\t FIFO dequeue (%d)\n", temp);

	} else {
		printf("\t FIFO dequeue ----- Faild");
	}
	i = 10;
	printf("FIFO enqueue (%d):\n",i*2);
	if (FIFO_enqueue(&fifo_UART,i*2) == FIFO_no_error) {
		printf("\t FIFO enqueue ----- Done\n");
	} else {
		printf("\t FIFO enqueue ----- Faild\n");
	}

	FIFO_print(&fifo_UART);



	return 0;
}
