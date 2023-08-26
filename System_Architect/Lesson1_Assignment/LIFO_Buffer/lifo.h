/*
 * lifo.h
 *
 *  Created on: Aug 23, 2023
 *      Author: andre
 */

#include "platform_types.h"
#include "platform_types.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LIFO_H_
#define LIFO_H_

typedef struct {
	uint32 length;
	uint32 count;
	uint32* base;
	uint32* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_buffer_status;

LIFO_buffer_status LIFO_Push_Item(LIFO_Buf_t* lifo_buf, uint32 item);
LIFO_buffer_status LIFO_Pop_Item(LIFO_Buf_t* lifo_buf, uint32* item);
LIFO_buffer_status LIFO_Init(LIFO_Buf_t* lifo_buf, uint32* buf, uint32 length);


#endif
