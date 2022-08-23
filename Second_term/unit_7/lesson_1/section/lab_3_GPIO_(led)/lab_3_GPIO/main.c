/*
 * lab_3_GPIO.c
 *
 * Created: 22/08/2022 08:08:45 م
 * Author : salama
 */ 
#define F_CPU 8000000UL
#include "Reg_Map.h"
#include <util/delay.h>

int main(void)
{
    DDRD |=(7<<5);
	Reset_bit(DDRD,0);
	PORTD |=(0b000<<5);
	char i=5;
    while (1) 
    {
		if (Read_bit(PIND,0)==1)
		{
			if(i<9)
			{
				Toggle_bit(PORTD,i);
				_delay_ms(500);
				i++;
			}
		}
    }
}

