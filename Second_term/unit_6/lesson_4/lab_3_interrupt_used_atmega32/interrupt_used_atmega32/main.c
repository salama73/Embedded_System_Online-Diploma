/*
 * interrupt_used_atmega32.c
 *
 * Created: 20/08/2022 10:46:12 م
 * Author : salama
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int main(void)
{
	// PORTD PIN0 IS OUTPUT
    DDRD |=(1<<0);
	// PORTD PIN2 IS INPUT
	DDRD &=~(1<<2);
	//Global Interrupt Enable
	SREG |=(1<<7);
	//Any logical change on INT0 generates an interrupt request.
	MCUCR |=0X01;
	// External Interrupt Request 0 Enable
	GICR |=(1<<6);
    while (1) 
    {
    }
}
ISR(INT0_vect)
{
	PORTD |=(1<<0);
	_delay_ms(500);
	PORTD &=~(1<<0);
	_delay_ms(200);
}

