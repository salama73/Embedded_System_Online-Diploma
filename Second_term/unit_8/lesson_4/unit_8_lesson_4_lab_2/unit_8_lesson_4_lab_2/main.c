/*
 * unit_8_lesson_4_lab_2.c
 *
 * Created: 10/09/2022 12:58:21 ص
 * Author : salama mohamed
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>

#define SS		4
#define MOSI	5
#define SCK		7

void execute ( unsigned char cmd , unsigned char DATA)
{
	// ss low 
	PORTB &=~(1<<SS);
	// start byte as command 
	SPDR = cmd ;
	while(!(SPSR & (1<<SPIF)));
	SPDR = DATA ;
	while(!(SPSR & (1<<SPIF)));
	// End transmit
	PORTB |=(1<<SS);
}

void SPI_master_init (void)
{
	//Set MOSI , SS , and SCK output
	DDRB |=(1<<SS) | (1<<SCK) | (1<<MOSI) ;
	// Master mode and shift clock =clk/16 ;
	SPCR |= (1<<MSTR)|(1<<SPR0)  ;
	// Enable SPI
	SPCR |= (1<<SPE);
}

int main(void)
{
    unsigned char count=0  ;
	unsigned char index  ;
	SPI_master_init() ; 
	execute(0x09, 0xFF);// decode all displays
	execute(0x0A, 0xFF);// max intensity
	execute(0x0B, 0xF7);//  set scan limit
	execute(0x0C, 0x01);// turn on display
    while (1) 
    {
		for(index=1 ; index<9 ; index++)
		{
			execute(index,count++);
			_delay_ms(1000);
		}	
    }
	return 0;
}

