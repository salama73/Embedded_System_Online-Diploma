/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Salama Mohamed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

/*
 **************************************************************
 *************************Include File ************************
 **************************************************************
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
/*
 **************************************************************
 *************************External Symbol *********************
 **************************************************************
 */
extern _estack;
/*
 **************************************************************
 *************************Macro********************************
 **************************************************************
 */
#define OS_SET_PSP(TOP_Add) 	__asm("MOV R0,%[in] \t\n MSR PSP,R0": :[in] "r" (TOP_Add))
#define OS_Switch_SP_PSP		__asm("MRS R0,CONTROL \t\n ORR R0,R0,#0x2 \t\n MSR CONTROL,R0")
#define OS_Switch_SP_MSP		__asm("MRS R0,CONTROL \t\n AND R0,R0,#0x5 \t\n MSR CONTROL,R0")
#define OS_Generate_Interrupt   __asm("SVC #0x3")

#define CPU_Access_Level_Unprivileged() 	{ __asm("MRS R3,CONTROL"); \
											  __asm("ORR R3,R3,#0x01"); \
											  __asm("MSR CONTROL,R3"); \
                                             }

#define CPU_Access_Level_Privileged()        {__asm("MRS R3,CONTROL"); \
											  __asm("LSR R3,R3,#0x01"); \
											  __asm("LSL R3,R3,#0x01"); \
											  __asm("MSR CONTROL,R3"); \
											 }
#define TaskA_Size 				100
#define TaskB_Size 				100
/*
 **************************************************************
 *************************Global Variable **********************
 **************************************************************
 */
uint32_t _S_MSP=&_estack;
uint32_t _E_MSP;
//Stack pointer task A
uint32_t _S_PSP_TA;
uint32_t _E_PSP_TA;
//Stack pointer task B
uint32_t _S_PSP_TB;
uint32_t _E_PSP_TB;
//flag
uint8_t Flag_Task_A=0;
uint8_t Flag_Task_B=0;
uint8_t Flag=0;
/*
 **************************************************************
 *************************Init Functions **********************
 **************************************************************
 */
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
/*
 **************************************************************
 *************************ISR *********************************
 **************************************************************
 */
void SVC_Handler (void)
{
	CPU_Access_Level_Privileged();
}

void EXTI_9 (void)
{
	if(Flag==0)
	{
		Flag_Task_A=1;
		Flag=1;
	}
	else if(Flag==1)
	{
		Flag_Task_B=1;
		Flag=0;
	}
}
/*
 **************************************************************
 *************************Tasks********************************
 **************************************************************
 */
uint8_t Task_A(uint8_t x,uint8_t y)
{
	uint8_t sum=x+y;
	return sum;
}

uint8_t Task_B(uint8_t x,uint8_t y)
{
	uint8_t sub=x-y;
	return sub;
}
/*
 **************************************************************
 *************************OS***********************************
 **************************************************************
 */
void main_os(void)
{
	//init main stack pointer
	_E_MSP=_S_MSP-512;
	//init PSP Task A
	_S_PSP_TA=_E_MSP-8;
	_E_PSP_TA=_S_PSP_TA-TaskA_Size;
	//init PSP Task B
	_S_PSP_TB=_E_PSP_TA-8;
	_E_PSP_TB=_S_PSP_TB-TaskB_Size;
	while(1)
	{
		if(Flag_Task_A==1)
		{
			uint8_t sum;
			Flag_Task_A=0;
			//set PSP
			OS_SET_PSP(_S_PSP_TA);
			//switch to PSP
			OS_Switch_SP_PSP;
			// switch to unprivileged mode
			CPU_Access_Level_Unprivileged();
			sum=Task_A(5, 10);
			//Generate Interrupt to switch to privileged mode
			OS_Generate_Interrupt;
			//set MSP
			OS_Switch_SP_MSP;
		}
		else if(Flag_Task_B==1)
		{
			uint8_t sub;
			Flag_Task_B=0;
			//set PSP
			OS_SET_PSP(_S_PSP_TB);
			//switch to PSP
			OS_Switch_SP_PSP;
			// switch to unprivileged mode
			CPU_Access_Level_Unprivileged();
			sub=Task_B(50, 10);
			//Generate Interrupt to switch to privileged mode
			OS_Generate_Interrupt;
			//set MSP
			OS_Switch_SP_MSP;
		}
	}
}
/*
 **************************************************************
 *************************Main *********************************
 **************************************************************
 */
int main(void)
{
	Clock_INIT();

	EXTI_PinConfig_t Config;
	Config.EXTI_Pin = EXTI9_PB9;
	Config.Trigger_case = EXTI_Trigger_Rising;
	Config.P_IRQ_CALL = EXTI_9;
	Config.IRQ_EN = EXTI_IRQ_Enable ;
	MCAL_EXTI_GPIO_Init(&Config);

	main_os();
	while (1)
	{

	}
}
/*
 **************************************************************
 *************************End *********************************
 **************************************************************
 */
