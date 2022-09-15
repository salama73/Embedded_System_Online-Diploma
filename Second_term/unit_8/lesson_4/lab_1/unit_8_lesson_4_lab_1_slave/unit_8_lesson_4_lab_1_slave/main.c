/*
 * unit_8_lesson_4_lab_1.c
 *
 * Created: 10/09/2022 12:12:05 ص
 * Author : Salama Mohamed
 */ 
//slave
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

void SPI_slave_init (void)
{
	// Set MISO to output
	DDRB |=(1<<MISO);
	//Set MOSI , SS , and SCK input
	DDRB &=~(1<<SS) & ~(1<<SCK) & ~(1<<MOSI) ;
	// Enable SPI
	SPCR |= (1<<SPE);
}

unsigned char SPI_slave_ReceiveData(unsigned char DATA)
{
	SPDR = DATA ; // send data to master
	while(!(SPSR & (1<<SPIF)));
	return SPDR ;
}

int main(void)
{
    DDRA = 0XFF ;
	unsigned char DATA  ;
	SPI_slave_init();
	while(1)
	{
		for(DATA=255 ; DATA >0 ; DATA--)
		{
			_delay_ms(1000);
			PORTA= SPI_slave_ReceiveData(DATA);
		}
	}
	return 0 ;
}

