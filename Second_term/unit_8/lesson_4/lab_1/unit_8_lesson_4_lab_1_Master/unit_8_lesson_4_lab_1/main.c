/*
 * unit_8_lesson_4_lab_1.c
 *
 * Created: 10/09/2022 12:12:05 ص
 * Author : Salama Mohamed
 */ 
//master
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

void SPI_master_init (void)
{
	// Set MISO to input
	DDRB &=~(1<<MISO);
	//Set MOSI , SS , and SCK output
	DDRB |=(1<<SS) | (1<<SCK) | (1<<MOSI) ;
	// Master mode and shift clock =clk/16 ;
	SPCR |= (1<<MSTR)|(1<<SPR0)   ;
	// Enable SPI
	SPCR |= (1<<SPE);
}

unsigned char SPI_Master_SendData(unsigned char DATA)
{
	SPDR = DATA ;
	while(!(SPSR & (1<<SPIF)));
	return SPDR ;
}

int main(void)
{
    DDRA = 0XFF ;
	unsigned char DATA  ;
	SPI_master_init();
	while(1)
	{
		for(DATA=0 ; DATA <=255 ; DATA++)
		{
			_delay_ms(1000);
			PORTA= SPI_Master_SendData(DATA);
		}	
	}
	return 0 ;
}

