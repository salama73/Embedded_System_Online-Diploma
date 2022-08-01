/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : main.c
 ============================================================================
 */

#include "CA.h"

void setup()
{
	// init all drivers
	// init IRQ......
	//init BLOCK
	// set state pointer
	CA_stata=STATE(CA_waiting);
}

int main(void)
{
	setup();
	volatile int i;
	while(1)
	{
		CA_stata();
		for ( i = 0; i < 1000; i++);
	}
}
