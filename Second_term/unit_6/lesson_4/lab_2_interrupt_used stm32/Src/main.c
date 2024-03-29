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

#define AFIO_BASE       0x40010000
#define NVIC_BASE       0xE000E100
#define EXTI_BASE       0x40010400
#define RCC_BASE        0x40021000
#define GPIOA_BASE      0x40010800
#define NVIC_EN         *(volatile uint32_t *)(NVIC_BASE+0x00)
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE+0x18)
#define GPIO_CRH        *(volatile uint32_t *)(GPIOA_BASE+0x04)
#define GPIO_CRL        *(volatile uint32_t *)(GPIOA_BASE+0x00)
#define GPIO_ODR        *(volatile uint32_t *)(GPIOA_BASE+0x0c)
#define EXTI_IMR        *(volatile uint32_t *)(EXTI_BASE+0x00)  //nterrupt mask register
#define EXTI_RTSR       *(volatile uint32_t *)(EXTI_BASE+0x08)  //Rising trigger selection register
#define EXTI_PR         *(volatile uint32_t *)(EXTI_BASE+0x14)  //Pending register
#define AFIO_EXTICR1    *(volatile uint32_t *)(0x40010000+0x08)  //External interrupt configuration register

int main(void)
{
	//Turn on the clock for PORTA
	RCC_APB2ENR |=1<<2;
	//Turn on the clock for AFIO
	RCC_APB2ENR |=1<<0;
    //Make pin 13 PORTA output
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
	// Interrupt request from Line 0 is not masked
	EXTI_IMR |=(1<<0);
	// Rising trigger enabled (for Event and Interrupt) for input line 0.
	EXTI_RTSR |=(1<<0);
	// EXTI 0 configuration pin 0 PORTA TO EXTI 0
	AFIO_EXTICR1 |=0;
	//Make pin 0 PORTA input ( Floating input)
	GPIO_CRL  |=(1<<2);
	//Enable NVIC to EXTI0
	NVIC_EN |=(1<<6);
	while(1);

}
void EXTI0_IRQHandler(void)
{
	//toggle pin 13 PORTA
	GPIO_ODR ^=(1<<13);
	//selected trigger request occurred
	EXTI_PR |=(1<<0);
}
