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

#include "Platform_Types.h"
#define RCC_BASE        0x40021000
#define GPIOA_BASE      0x40010800
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE+0x18)
#define GPIO_CRH       *(volatile uint32_t *)(GPIOA_BASE+0x04)
#define RCC_CFGR      *(volatile uint32_t *)(RCC_BASE+0x04)

typedef union
{
	vint32_t all_fieldes;
	struct
	{
		vint32_t reserved:13;
		vint32_t pin_13:1;
	}pin;
}R_ODR_t;
int main(void)
{
	volatile R_ODR_t* R_ODR =(volatile R_ODR_t *)(GPIOA_BASE+0x0c);

	RCC_APB2ENR |=1<<2;  //Turn on the clock for PORTA
	RCC_CFGR |=0b101<<11;  //APB high-speed prescaler (APB2 at 2 MH)
	RCC_CFGR |=0b100<<8;  //APB high-speed prescaler (APB1 at 4 MH)


	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
	while(1)
	{
		R_ODR->pin.pin_13=1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.pin_13=0;
		for(int i=0;i<5000;i++);
	}
}
