/*
 * lab_4_GPIO.c
 *
 * Created: 22/08/2022 08:08:45 م
 * Author : salama
 */ 
#define F_CPU 8000000UL
#include "Reg_Map.h"
#include <util/delay.h>

int main(void)
{
	Reset_bit(DDRD,0);
	Set_bit(DDRD,4);
    while (1) 
    {
		if (Read_bit(PIND,0)==1)
		{
			Set_bit(PORTD,4);
			_delay_ms(1000);
			Reset_bit(PORTD,4);
			_delay_ms(200);
		}
    }
}