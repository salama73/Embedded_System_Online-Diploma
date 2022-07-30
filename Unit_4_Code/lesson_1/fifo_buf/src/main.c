/*
 ============================================================================
 Name        : main.c
 Author      : salama
 Created on  : ٢٩‏/٠٧‏/٢٠٢٢
 ============================================================================
 */


#include "queue.h"
#define buffer_length 5
element_type buffer1[buffer_length];

int main(void)
{
	uint8_t i,temp=0;

	FIFO_BUF_t uart_fifo;

	if (FIFO_init(&uart_fifo, buffer1,buffer_length)==FIFO_NO_ERROR)
		printf("fifo init--------------> DONE\n");


	for(i=0;i<7;i++)
	{
		printf("fifo enqueue : %x\n",i);
		if ( FIFO_enqueue_item(&uart_fifo, i)==FIFO_NO_ERROR)
			printf("fifo enqueue : %x --------------->DONE\n",i);
		else
			printf("fifo enqueue : %x --------------->FAILED\n",i);

	}

	FIFO_print(&uart_fifo);
	FIFO_dequeue_item(&uart_fifo, &temp);
	printf("FIFO dequeue data= %x\n",temp);
	FIFO_dequeue_item(&uart_fifo, &temp);
	printf("FIFO dequeue data= %x\n",temp);

	for(i=0;i<2;i++)
	{
		printf("fifo enqueue : %x\n",i);
		if ( FIFO_enqueue_item(&uart_fifo, i)==FIFO_NO_ERROR)
			printf("fifo enqueue : %x --------------->DONE\n",i);
		else
			printf("fifo enqueue : %x --------------->FAILED\n",i);

	}

}
