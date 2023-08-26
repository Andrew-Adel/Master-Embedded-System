/*
 * fifo.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "fifo.h"

FIFO_Buf_status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf, uint32 length){
	//check buffer
	if (buf == NULL) {
		return FIFO_Null;
	}

	// set fifo
	fifo->base = buf;
	fifo->count = 0;
	fifo->head = buf;
	fifo->length = length;
	fifo->tail = buf;

	return FIFO_no_error;
}

FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, element_type item){
	//check buffer
	if (!fifo->base || !fifo->head || !fifo->tail ) {
		return FIFO_Null;
	}
	// if fifo is full
	if (FIFO_IS_FULL(fifo) == FIFO_full) {
		return FIFO_full;
	}
	// add to fifo
	*(fifo->head) = item;
	// circular increment
	fifo->head = fifo->base + (( (fifo->head - fifo->base) + sizeof(element_type)) % (fifo->length * sizeof(element_type)));
	fifo->count++;
	// return no error
	return FIFO_no_error;
}

FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item){
	//check buffer
	if (!fifo->base || !fifo->head || !fifo->tail ) {
		return FIFO_Null;
	}
	// if fifo is empty
	if (fifo->count <= 0) {
		return FIFO_empty;
	}
	// add to fifo
	*item = *(fifo->tail);
	fifo->tail = fifo->base + (( (fifo->tail - fifo->base) + sizeof(element_type)) % (fifo->length * sizeof(element_type)));
	fifo->count--;
	// return no error
	return FIFO_no_error;
}

FIFO_Buf_status FIFO_IS_FULL(FIFO_Buf_t* fifo){
	//check buffer
	if (!fifo->base || !fifo->head || !fifo->tail ) {
		return FIFO_Null;
	}

	if (fifo->count >= fifo->length) {
		return FIFO_full;
	}

	return FIFO_no_error;
}

FIFO_Buf_status FIFO_print(FIFO_Buf_t* fifo){
	element_type i;
	printf("Printing Elements in buffer:\n");
	// check// if fifo is empty
	if (fifo->count <= 0) {
		printf("FIFO is empty");
		return FIFO_empty;
	}

	int x;
	printf("============FIFO Print============\n");
	for (i = 0; i < fifo->count; ++i) {
		// circular from tail to head
		x = ( (fifo->tail - fifo->base) + (i * sizeof(element_type)) ) % (fifo->length * sizeof(element_type));
		printf("\t element(%d) = (%d)\n",(x/sizeof(element_type)) , *(fifo->base + x));
	}
	printf("==================================\n");
	return FIFO_no_error;
}
