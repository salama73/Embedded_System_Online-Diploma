/*
 ============================================================================
 Name        : lifo.h
 Author      : salama
 Created on  : ٢٩‏/٠٧‏/٢٠٢٢
 ============================================================================
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	unsigned int length;
	unsigned int* head;
	unsigned int* base;
	unsigned int count;
} LIFO_BUF_t;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL,
}lifo_statuts_t;

//apis

lifo_statuts_t LIFO_add_item(LIFO_BUF_t* lifo_buf , unsigned int item);
lifo_statuts_t LIFO_get_item(LIFO_BUF_t* lifo_buf , unsigned int* item);
lifo_statuts_t LIFO_init(LIFO_BUF_t* lifo_buf , unsigned int* buf,unsigned int length);

#endif /* LIFO_H_ */
