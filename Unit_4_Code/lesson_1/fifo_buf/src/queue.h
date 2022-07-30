/*
 ============================================================================
 Name        : queue.h
 Author      : salama
 Created on  : ٢٩‏/٠٧‏/٢٠٢٢
 ============================================================================
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Platform_Types.h"
#include <stdio.h>
#include <stdlib.h>
//select the element type ex---->(uint8_t or uint16_t or uint32_t)
#define element_type uint8_t

typedef struct
{
	uint32_t length;
	element_type* head;
	element_type* base;
	element_type* tail;
	uint32_t count;
} FIFO_BUF_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL,
}fifo_statuts_t;

//FIFO APIS

fifo_statuts_t FIFO_enqueue_item(FIFO_BUF_t* fifo_buf , element_type item);
fifo_statuts_t FIFO_is_full(FIFO_BUF_t* fifo_buf );
void FIFO_print(FIFO_BUF_t* fifo_buf);
fifo_statuts_t FIFO_dequeue_item(FIFO_BUF_t* fifo_buf , element_type* item);
fifo_statuts_t FIFO_init(FIFO_BUF_t* fifo_buf , element_type* buf,uint32_t length);

#endif /* QUEUE_H_ */
