/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

#include <stm32_f103c6_TIM2_3.h>
#include"stm32_f103c6_GPIO.h"
#include"stm32_f103c6_EXTI.h"
#include "stm32f103x6.h"
#include"stm32_f103c6_USART.h"
#include"stm32_f103c6_SPI.h"
#include "stm32_f103c6_I2C.h"
#include "LCD.h"
#include "Keypad.h"
#include "EEPROM.h"
#include "delay.h"
#include "Servo.h"
#include "stm32_f103c6_ADC.h"



void Clock_INIT(void)
{
    //set on the clock for PORTA
    RCC_GPIOA_CLK_EN();
    //set on the clock for PORTB
    RCC_GPIOB_CLK_EN();
    //set on the clock for AFIO
    RCC_GPIOC_CLK_EN();
    RCC_AFIO_CLK_EN();
    RCC_TIM2_CLK_Enable();
    RCC_TIM3_CLK_Enable();
    RCC_TIM4_CLK_Enable();
    RCC_ADC1_CLK_Enable();
}

enum CPU_Access_Level
{
	Privileged,
	Nonprivileged
};

void Switch_CPU_Access_Level(enum CPU_Access_Level Level)
{
	switch(Level)
	{
	case Privileged:
	{
		__asm("MRS R3,CONTROL");
		__asm("LSR R3,R3,#0x01");
		__asm("LSL R3,R3,#0x01");
		__asm("MSR CONTROL,R3");
		break;
	}
	case Nonprivileged:
	{
		__asm("MRS R3,CONTROL");
		__asm("ORR R3,R3,#0x01");
		__asm("MSR CONTROL,R3");
		break;
	}
	}
}

void EXTI_9 (void)
{
	Switch_CPU_Access_Level(Privileged);
}

int main(void)
{
	Clock_INIT();

	EXTI_PinConfig_t Config;
	Config.EXTI_Pin = EXTI9_PB9;
	Config.Trigger_case = EXTI_Trigger_Rising;
	Config.P_IRQ_CALL = EXTI_9;
	Config.IRQ_EN = EXTI_IRQ_Enable ;
	MCAL_EXTI_GPIO_Init(&Config);
	Switch_CPU_Access_Level(Nonprivileged);
	while (1)
	{

	}
}
