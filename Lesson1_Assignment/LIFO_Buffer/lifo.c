/*
 * lifo.c
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "lifo.h"

LIFO_buffer_status LIFO_Init(LIFO_Buf_t* lifo_buf, uint32* buf, uint32 length){
	if(buf == NULL)
		return LIFO_Null;
	lifo_buf->base =buf;
	lifo_buf->count = 0;
	lifo_buf->head = buf;
	lifo_buf->length = length;


	return LIFO_no_error;
}

LIFO_buffer_status LIFO_Push_Item(LIFO_Buf_t* lifo_buf, uint32 item){
	// check LIFO is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	// check LIFO is full
	if(lifo_buf->count >= lifo_buf->length)
		return LIFO_full;
	// add item and increment head
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_no_error;
}

LIFO_buffer_status LIFO_Pop_Item(LIFO_Buf_t* lifo_buf, uint32* item){
	// check LIFO is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	// check LIFO is empty
	if(lifo_buf->count <= 0)
		return LIFO_empty;
	*item = *(--lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
}

LIFO_buffer_status LIFO_print(LIFO_Buf_t* lifo){
	int i;
	printf("Printing Elements in buffer:\n");
	// check// if Lifo is empty
	if (lifo->count <= 0) {
		printf("LIFO is empty");
		return LIFO_empty;
	}

	printf("============LIFO Print============\n");
	for (i = 0; i < lifo->count; ++i) {
		// circular from tail to head
		uint32* x =  lifo->head - i-1;
		printf("\t element(%d) = (%ul) (%x)\n", i , *x, x);
	}
	printf("==================================\n");
	return LIFO_no_error;
}
