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
#include"stm32_f103c6_GPIO.h"
#include"stm32_f103c6_EXTI.h"
#include "stm32f103x6.h"
#include "LCD.h"
#include "Keypad.h"

uint8_t flag=0;

void delay(int x)
{
	uint32_t i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<255;j++);
}

void Clock_INIT(void)
{
	//set on the clock for PORTA
	RCC_GPIOA_CLK_EN();
	//set on the clock for PORTB
	RCC_GPIOB_CLK_EN();
	//set on the clock for AFIO
	RCC_AFIO_CLK_EN();
}

void EXTI_9 (void)
{
	flag=1;
	LCD_String("IRQ EXTI9 is happened");
	delay(1000);
}

int main(void)
{
	Clock_INIT();
	LCD_init();

	EXTI_PinConfig_t Config;
	Config.EXTI_Pin = EXTI9_PB9;
	Config.Trigger_case = EXTI_Trigger_Falling;
	Config.P_IRQ_CALL = EXTI_9;
	Config.IRQ_EN = EXTI_IRQ_Enable ;
	MCAL_EXTI_GPIO_Init(&Config);




	while (1)
	{
		if(flag==1)
		{
			lcd_Clear();
			flag=0;
		}
	}

}

