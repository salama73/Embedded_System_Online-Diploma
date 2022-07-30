/*
 ============================================================================
 Name        : lifo.c
 Author      : salama
 Created on  : ٢٩‏/٠٧‏/٢٠٢٢
 ============================================================================
 */
#include "lifo.h"

lifo_statuts_t LIFO_add_item(LIFO_BUF_t* lifo_buf , unsigned int item)
{
	//lifo valid
	if (! lifo_buf->head || ! lifo_buf->base )
		return LIFO_NULL;

	// lifo is fill
	if ( lifo_buf->count== lifo_buf->length)
		return LIFO_FULL;

	//add item
	*(lifo_buf->head)=item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_NO_ERROR;
}


lifo_statuts_t LIFO_get_item(LIFO_BUF_t* lifo_buf , unsigned int* item)
{
	//lifo valid
	if (! lifo_buf->head || ! lifo_buf->base )
		return LIFO_NULL;

	//lifo is ampty
	if(lifo_buf->count==0)
		return LIFO_EMPTY;

	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_NO_ERROR;
}


lifo_statuts_t LIFO_init(LIFO_BUF_t* lifo_buf , unsigned int* buf,unsigned int length)
{
	if(buf == NULL)
		return LIFO_NULL;
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->count = 0;
	lifo_buf->length = length;
	return LIFO_NO_ERROR;
}


