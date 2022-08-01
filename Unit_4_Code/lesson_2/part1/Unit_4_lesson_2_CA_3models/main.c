/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : main.c
 ============================================================================
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	// init all drivers
	// init IRQ......
	//init BLOCK
	// set state pointer
	CA_stata=STATE(CA_waiting);
	DC_stata=STATE(DC_idle);
	US_stata=STATE(US_busy);
}

int main(void)
{
	setup();
	volatile int i;
	while(1)
	{
		US_stata();
		CA_stata();
		DC_stata();
		for ( i = 0; i < 1000; i++);
	}
}
