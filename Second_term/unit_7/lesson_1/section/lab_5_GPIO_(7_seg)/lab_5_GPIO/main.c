/*
 * lab_5_GPIO.c
 *
 * Created: 22/08/2022 08:08:45 م
 * Author : salama
 */ 
#define F_CPU 8000000UL
#include "Reg_Map.h"
#include <util/delay.h>

int main(void)
{
    DDRC=0XFF;
    while (1) 
    {
		int i,j;
		for (i=0;i<10;i++)
		{
			for (j=0;j<10;j++)
			{
				PORTC = 0b1000 | (i<<4);
				_delay_ms(50);
				PORTC = 0b0100 | (i<<4);
				_delay_ms(50);
			}
		}
    }
}