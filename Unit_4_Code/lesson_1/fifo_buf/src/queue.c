/*
 ============================================================================
 Name        : fifo.c
 Author      : salama
 Created on  : ٢٩‏/٠٧‏/٢٠٢٢
 ============================================================================
 */
#include "queue.h"

fifo_statuts_t FIFO_enqueue_item(FIFO_BUF_t* fifo_buf , element_type item)
{
	if(FIFO_is_full(fifo_buf)==FIFO_NO_ERROR)
	{
		*(fifo_buf->head)=item;
		fifo_buf->count++;
		if(fifo_buf->head==(fifo_buf->base+(fifo_buf->length * sizeof(element_type))))
			fifo_buf->head=fifo_buf->base;
		else
			fifo_buf->head++;
		return FIFO_NO_ERROR;
	}
	else
	{
		printf("fifo enqueue failed\n");
		return (FIFO_is_full(fifo_buf));
	}
}


fifo_statuts_t FIFO_is_full(FIFO_BUF_t* fifo_buf )
{
	//fifo valid
	if (! fifo_buf->head || ! fifo_buf->base || ! fifo_buf->tail)
		return FIFO_NULL;

	// fifo is full
	if ( fifo_buf->count>= fifo_buf->length)
	{
		printf("fifo is full\n");
		return FIFO_FULL;
	}
	return FIFO_NO_ERROR;
}

void FIFO_print(FIFO_BUF_t* fifo_buf)
{
	element_type* temp;
	int i;
	if(fifo_buf->count==0)
		printf("fifo is empty\n");
	temp=fifo_buf->tail;
	printf("===============print fifo================\n");
	for(i=0;i<fifo_buf->length;i++)
	{
		printf("\t %x \n",*temp);
		temp++;
	}
	printf("\n============================\n");
}


fifo_statuts_t FIFO_dequeue_item(FIFO_BUF_t* fifo_buf , element_type* item)
{
	//fifo valid
	if (! fifo_buf->head || ! fifo_buf->base || ! fifo_buf->tail)
		return FIFO_NULL;

	//fifo is empty
	if(fifo_buf->count==0)
		return FIFO_EMPTY;

	*item = *(fifo_buf->tail);
	fifo_buf->count--;

	//circler fifo
	if(fifo_buf->tail==(fifo_buf->base+(fifo_buf->length * sizeof(element_type))))
		fifo_buf->tail=fifo_buf->base;
	else
		fifo_buf->tail++;

	return FIFO_NO_ERROR;
}


fifo_statuts_t FIFO_init(FIFO_BUF_t* fifo_buf , element_type* buf,uint32_t length)
{
	fifo_buf->base = buf;
	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail =fifo_buf->base;
	fifo_buf->count = 0;
	fifo_buf->length = length;

	if(fifo_buf->base && fifo_buf->length)
		return FIFO_NO_ERROR;
	else
		return FIFO_NULL;
}


