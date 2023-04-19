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
#include "core_cm3.h"
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
#define OS_SET_PSP(TOP_Add)     __asm("MOV R0,%[in] \t\n MSR PSP,R0": :[in] "r" (TOP_Add))
#define OS_Switch_SP_PSP        __asm("MRS R0,CONTROL \t\n ORR R0,R0,#0x2 \t\n MSR CONTROL,R0")
#define OS_Switch_SP_MSP        __asm("MRS R0,CONTROL \t\n AND R0,R0,#0x5 \t\n MSR CONTROL,R0")
#define OS_Generate_Interrupt   __asm("SVC #0x3")

#define CPU_Access_Level_Unprivileged()     { __asm("MRS R3,CONTROL"); \
                                              __asm("ORR R3,R3,#0x01"); \
                                              __asm("MSR CONTROL,R3"); \
                                             }

#define CPU_Access_Level_Privileged()        {__asm("MRS R3,CONTROL"); \
                                              __asm("LSR R3,R3,#0x01"); \
                                              __asm("LSL R3,R3,#0x01"); \
                                              __asm("MSR CONTROL,R3"); \
                                             }
#define TaskA_Size              100
#define TaskB_Size              100
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
__attribute((naked)) void SVC_Handler (void)
{
    __asm(  "TST LR,#4\n\t"
    		"ITE EQ \n\t"
    		"MRSEQ R0,MSP\n\t"
    		"MRSNE R0,PSP\n\t"
    		"B OS_SV");
}
/*
 **************************************************************
 *************************OS***********************************
 **************************************************************
 */
int OS_SVC_Set(int a,int b,int id)
{
	int return_val;
	switch(id)
	{
	case 0:
		__asm("SVC #0x00");
		break;
	case 1:
		__asm("SVC #0x01");
		break;
	case 2:
		__asm("SVC #0x02");
		break;
	}
	__asm("MOV %[OUT],R0":[OUT] "=r" (return_val));
	return return_val;
}

void OS_SV(int* Stack_Frame)
{
	uint8_t SVC_Number;
	uint32_t Val1;
	uint32_t Val2;
	Val1=Stack_Frame[0];
	Val2=Stack_Frame[1];
	SVC_Number=*((uint8_t*)(((uint8_t*)Stack_Frame[6])-2));
	switch(SVC_Number)
	{
	case 0:
		Stack_Frame[0]=Val1+Val2;
		break;
	case 1:
		Stack_Frame[0]=Val1-Val2;
		break;
	case 2:
		Stack_Frame[0]=Val1*Val2;
		break;
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
    int result;
    result=OS_SVC_Set(3,2,0);
    result=OS_SVC_Set(3,2,1);
    result=OS_SVC_Set(3,2,2);
    while (1)
    {

    }
}
/*
 **************************************************************
 *************************End *********************************
 **************************************************************
 */
