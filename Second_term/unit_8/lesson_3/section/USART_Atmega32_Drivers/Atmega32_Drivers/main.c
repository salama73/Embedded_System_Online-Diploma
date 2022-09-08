/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022 08:00:04 م
 * Author : salama mohamed
 */ 


#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "LCD.h"
#include "USART_Driver.h"

 char DATA  ;

void USART_CALL(void)
{
	MCAL_USART_ReceiveData(&DATA , Disable) ;
	GOTO_XY(1 , 0 ) ;
	LCD_Character( DATA ) ;
	_delay_ms( 1000);
	lcd_Clear();
}

void USART_init (void)
{
	USART_config_t config ;
	config.BAUDRATE = USART_BAUDRATE_9600 ;
	config.Communication_MODE = USART_Communication_MODE_Asynchronous_Double_Speed ;
	config.IRQ_EN = USART_IRQ_ENABLE_RX ;
	config.MODE = USART_MODE_TX_RX ;
	config.NUM_DATA_BIT = USART_NUM_DATA_BIT_8 ;
	config.NUM_STOP_BIT = USART_NUM_STOP_BIT_1 ;
	config.P_IRQ_CALL = USART_CALL ;
	config.PARITY = USART_PARITY_Disable ;
	MCAL_USART_Init( &config ) ;
}

char number [10]={ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,'8' , '9' } ;
int main(void)
{
	int i =0;
	LCD_init() ;
	USART_init();
    while (1) 
    {
		LCD_Character( number [i] ) ;
		i++ ;
		if(i==10)
			i=0 ;
		_delay_ms( 500) ;
		lcd_Clear();
    }
}

