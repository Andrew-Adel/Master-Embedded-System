/*
 * fifo.h
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "platform_types.h"
#include <stdio.h>
#include <stdlib.h>

//USER Configuration
// select element type (uint8, uint16, uint32, ...)
#define element_type uint32
#define width1 5
element_type uart_buffer[width1];

typedef struct {
	uint32 length;
	uint32 count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Buf_status;

FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf, uint32 length);
FIFO_Buf_status FIFO_IS_FULL(FIFO_Buf_t* fifo);
FIFO_Buf_status FIFO_print(FIFO_Buf_t* fifo);



#endif
