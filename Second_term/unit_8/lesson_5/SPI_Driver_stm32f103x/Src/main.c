/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
//#define SPI_ACT_AS_Master
#define SPI_ACT_AS_Slave
#include"stm32_f103c6_GPIO.h"
#include"stm32_f103c6_EXTI.h"
#include "stm32f103x6.h"
#include"stm32_f103c6_USART.h"
#include"stm32_f103c6_SPI.h"
#include "LCD.h"
#include "Keypad.h"

unsigned char DATA  ;
unsigned char DATA1;
void Clock_INIT(void)
{
	//set on the clock for PORTA
	RCC_GPIOA_CLK_EN();
	//set on the clock for PORTB
	RCC_GPIOB_CLK_EN();
	//set on the clock for AFIO
	RCC_AFIO_CLK_EN();
}

void SPI1_IRQ_Call (struct S_IRQ_SRC IRQ_SRC)
{
	if( IRQ_SRC.RXNE)
	{
		DATA1=0XF;
		MCAL_SPI_Receive_Send_Data(SPI1, &DATA1, Enabled);
		MCAL_USART_SendData(USART1, &DATA1, Enable);
	}
}

 void USART1_IRQ_Call (void)
 {
#ifdef SPI_ACT_AS_Master
	MCAL_USART_ReceiveData(USART1, &DATA, Disable);
	MCAL_USART_SendData(USART1, &DATA, Enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	MCAL_SPI_Receive_Send_Data(SPI1, &DATA, Enabled);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif

 }

int main(void)
{
	Clock_INIT();

	USART_config_t Config;
	Config.BAUDRATE=USART_BAUDRATE_115200 ;
	Config.HWFLOWCTL=USART_HWFLOWCTL_Disable;
	Config.IRQ_EN=USART_IRQ_ENABLE_RXNE;
	Config.MODE=USART_MODE_TX_RX;
	Config.NUM_DATA_BIT=USART_NUM_DATA_BIT_8;
	Config.NUM_STOP_BIT=USART_NUM_STOP_BIT_1;
	Config.PARITY=USART_PARITY_Disable;
	Config.P_IRQ_CALL=USART1_IRQ_Call;
	MCAL_USART_Init(USART1, &Config);
	MCAL_USART_Set_Pin(USART1);

	SPI_config_t SPI_Config;
	SPI_Config.Data_Order=SPI_Data_Order_MSB_Transmitted_First;
	SPI_Config.MODE_Communication=SPI_MODE_Communication_Full_Duplex;
	SPI_Config.NUM_DATA_BIT=SPI_NUM_DATA_BIT_8_Bit_Data_Frame;
	SPI_Config.Phase=SPI_Phase_Data_Latched_On_Second_Clock;
	SPI_Config.Polarity=SPI_Polarity_High_level_idle_state;
	SPI_Config.BaudRate_Prescalers=SPI_BaudRate_Prescalers_8;
#ifdef SPI_ACT_AS_Master
	SPI_Config.MODE=SPI_MODE_Master;
	SPI_Config.IRQ_EN=SPI_IRQ_ENABLE_Disable;
	SPI_Config.NSS_Management=SPI_NSS_Management_Soft_Enternal_Set;
	SPI_Config.P_IRQ_CALL=NULL;
	// SET PA4 SS
	GPIO_Pinconfig_t pinconf;
	pinconf.pinNumber = GPIO_PIN_4 ;
	pinconf.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	pinconf.GPIO_OUTPUT_Speed= GPIO_speed_10M;
	MCAL_GPIO_Init(GPIOA, &pinconf) ;
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif

#ifdef SPI_ACT_AS_Slave

	SPI_Config.MODE=SPI_MODE_Slave;
	SPI_Config.IRQ_EN=SPI_IRQ_ENABLE_RX_Buffer_Not_Empty;
	SPI_Config.NSS_Management=SPI_NSS_Management_Hard_Slave;
	SPI_Config.P_IRQ_CALL=SPI1_IRQ_Call;
#endif
	MCAL_SPI_Init(SPI1, &SPI_Config);
	MCAL_SPI_Set_Pin(SPI1);

	while (1)
	{

	}

}
