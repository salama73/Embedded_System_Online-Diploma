/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022
 * Author : salama mohamed
 */ 

//#define SPI_Act_As_Master
#define SPI_Act_As_Slave

#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "LCD.h"
#include "USART_Driver.h"
#include "SPI_Driver.h"

void USART_init (void)
{
	USART_config_t config ;
	config.BAUDRATE = USART_BAUDRATE_9600 ;
	config.Communication_MODE = USART_Communication_MODE_Asynchronous_Double_Speed ;
	config.IRQ_EN = USART_IRQ_ENABLE_Disable ;
	config.MODE = USART_MODE_TX_RX ;
	config.NUM_DATA_BIT = USART_NUM_DATA_BIT_8 ;
	config.NUM_STOP_BIT = USART_NUM_STOP_BIT_1 ;
	config.P_IRQ_CALL = NULL ;
	config.PARITY = USART_PARITY_Disable ;
	MCAL_USART_Init( &config ) ;
}

unsigned char data ;

void SPI_Call_INIT(void)
{
#ifdef SPI_Act_As_Slave
	MCAL_SPI_ReceiveData(&data,Enabled);
	MCAL_USART_SendData( &data , Enable);
#endif
}

int main(void)
{
	SPI_config_t SPI_Conf ;
	SPI_Conf.BaudRate_Prescalers = SPI_BaudRate_Prescalers_4 ;
	SPI_Conf.Data_Order = SPI_Data_Order_MSB_Transmitted_First ;
	SPI_Conf.IRQ_EN = SPI_IRQ_ENABLE_Enable ;
	SPI_Conf.P_IRQ_CALL = SPI_Call_INIT ;
	SPI_Conf.Phase = SPI_Phase_Data_Latched_On_First_Clock ;
	SPI_Conf.Polarity = SPI_Polarity_Low_level_idle_state ;
	SPI_Conf.Speed_Communication = SPI_Speed_Communication_Normal ;
#ifdef SPI_Act_As_Master
	SPI_Conf.MODE = SPI_MODE_Master ;
	MCAL_SPI_Set_Master_Pin();
#endif
#ifdef SPI_Act_As_Slave
	SPI_Conf.MODE = SPI_MODE_Slave ;
	MCAL_SPI_Set_Slave_Pin() ;
#endif
	MCAL_SPI_Init(&SPI_Conf) ;
	USART_init ();
	MCAL_SPI_Init(&SPI_Conf) ;
	
    while (1) 
    {
	#ifdef SPI_Act_As_Master
		MCAL_USART_ReceiveData(&data , Enable) ;
		MCAL_USART_SendData( &data , Enable);
		MCAL_SPI_SendData( &data ,Enabled);
	#endif
    }
}

