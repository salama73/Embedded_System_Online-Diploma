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

 char DATA[100]  ;



void USART_init (void)
{
	USART_config_t config ;
	config.BAUDRATE = USART_BAUDRATE_2400 ;
	config.Communication_MODE = USART_Communication_MODE_Asynchronous_Double_Speed ;
	config.IRQ_EN = USART_IRQ_ENABLE_Disable ;
	config.MODE = USART_MODE_TX_RX ;
	config.NUM_DATA_BIT = USART_NUM_DATA_BIT_8 ;
	config.NUM_STOP_BIT = USART_NUM_STOP_BIT_1 ;
	config.P_IRQ_CALL = NULL ;
	config.PARITY = USART_PARITY_Disable ;
	MCAL_USART_Init( &config ) ;
}


int main(void)
{


	USART_init();
    while (1) 
    {
		MCAL_USART_Receive_String( &DATA , Enable ) ;
		MCAL_USART_Send_String( &DATA , Enable);
    }
}

