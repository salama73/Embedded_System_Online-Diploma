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
#include "Scheduler.h"

/*
 **************************************************************
 *************************Global Variable **********************
 **************************************************************
 */

Semaphore_Ref Sem1;
Mutex_Ref MUT1;
int flag=0;
uint8_t data;
uint8_t Task1LED,Task2LED,Task3LED,Task4LED,Task5LED,Task6LED,Task7LED,Task8LED;

Task_Ref Task1,Task2,Task3,Task4,Task5,Task6,Task7,Task8;

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

void GPIO_Init(void)
{

	GPIO_Pinconfig_t PIN;
	PIN.GPIO_MODE=GPIO_MODE_OUTPUT_OD;
	PIN.GPIO_OUTPUT_Speed=GPIO_speed_2M;
	PIN.pinNumber=GPIO_PIN_13;
	MCAL_GPIO_Init(GPIOC, &PIN);

	PIN.pinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOA, &PIN);
	PIN.pinNumber=GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOA, &PIN);

	PIN.GPIO_MODE=GPIO_MODE_INPUT_PU;
	PIN.pinNumber=GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA, &PIN);
}
/*
 **************************************************************
 *************************ISR *********************************
 **************************************************************
 */


/*
 **************************************************************
 *************************Task***********************************
 **************************************************************
 */

void task1()
{
	int pr_flag=0;
	while (1)
	{
		MYRTOS_AcquireMutex(&MUT1,&Task1);
		flag=MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		if(flag != pr_flag)
		{
			MYRTOS_ReleaseMutex(&MUT1,&Task1);
		}
		Task1LED ^= 1;
		pr_flag=flag;
		MYRTOS_TaskWait(500,&Task1);
	}
}
void task2()
{
	while (1)
	{
		MYRTOS_AcquireMutex(&MUT1,&Task2);
		MCAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
		Task2LED ^= 1;
		MYRTOS_ReleaseMutex(&MUT1,&Task2);
	}
}
void task3()
{
	int count = 0;
	while(1)
	{
		Task3LED ^= 1;
		count++;
		if(count == 100)
		{
			MYRTOS_AcquireMutex(&MUT1,&Task3);
			MYRTOS_ActivateTask(&Task4);
		}
		if(count == 200)
		{
			count = 0;
			MYRTOS_ReleaseMutex(&MUT1,&Task3);
		}
	}
}

void task4()
{
	int count = 0;
	while(1)
	{
		Task4LED ^= 1;
		count++;
		if(count == 100)
		{
			MYRTOS_ActivateTask(&Task5);
		}
		if(count == 200)
		{
			count = 0;
			MYRTOS_TerminateTask(&Task4);
		}
	}
}

void task5()
{
	int count = 0;
	while(1){
		Task5LED ^= 1;
		count++;
		if(count == 3)
		{
			MYRTOS_AcquireMutex(&MUT1,&Task5);
		}
		if(count == 200)
		{
			count = 0;
			MYRTOS_ReleaseMutex(&MUT1,&Task5);
			MYRTOS_TerminateTask(&Task5);
		}
	}
}

void task6()
{
	int pr_flag=0;
	while (1)
	{
		MYRTOS_AcquireSemaphore(&Sem1, &Task6);
		flag=MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		if(flag != pr_flag)
		{
			MYRTOS_ReleaseSemaphore(&Sem1);
		}
		Task6LED ^= 1;
		pr_flag=flag;
		MYRTOS_TaskWait(500,&Task6);
	}
}

void task7()
{
	while (1)
	{
		MYRTOS_AcquireSemaphore(&Sem1, &Task7);
		MCAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
		Task7LED ^= 1;
		MYRTOS_ReleaseSemaphore(&Sem1);
	}
}

void task8()
{
	while (1)
	{
		MCAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
		Task8LED ^= 1;
		MYRTOS_TaskWait(500,&Task8);
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
    GPIO_Init();
    HW_init();

    MUT1.PayloadSize=1;
    MUT1.Ppayload=&flag;
    strcpy(MUT1.MutexName,"flag");

    Sem1.Ppayload=&flag;
    strcpy(Sem1.SemaphoreName,"flag");

	MY_RTOS_ErrorID Error;

	if (MYRTOS_Init() != NO_ERROR)
		while (1);


	Task1.P_TaskEntry=task1;
	Task1.Stack_Size=512;
	Task1.Auto_Start=Task_Start;
	strcpy(Task1.TaskName,"task1");
	Task1.priority=1;

	Task2.P_TaskEntry=task2;
	Task2.Stack_Size=512;
	Task2.Auto_Start=Task_Start;
	strcpy(Task2.TaskName,"task2");
	Task2.priority=2;
/*
	Error=MYRTOS_CreateTask(&Task1);
	Error=MYRTOS_CreateTask(&Task2);

	Task3.P_TaskEntry=task3;
	Task3.Stack_Size=512;
	Task3.Auto_Start=Task_Start;
	strcpy(Task3.TaskName,"task3");
	Task3.priority=5;

	Task4.P_TaskEntry=task4;
	Task4.Stack_Size=512;
	Task4.Auto_Start=Task_Suspend;
	strcpy(Task4.TaskName,"task4");
	Task4.priority=4;

	Task5.P_TaskEntry=task5;
	Task5.Stack_Size=512;
	Task5.Auto_Start=Task_Suspend;
	strcpy(Task5.TaskName,"task5");
	Task5.priority=3;

	Task6.P_TaskEntry=task6;
	Task6.Stack_Size=512;
	Task6.Auto_Start=Task_Start;
	strcpy(Task6.TaskName,"task6");
	Task6.priority=2;

	Task7.P_TaskEntry=task7;
	Task7.Stack_Size=512;
	Task7.Auto_Start=Task_Start;
	strcpy(Task7.TaskName,"task7");
	Task7.priority=3;

	Task8.P_TaskEntry=task8;
	Task8.Stack_Size=512;
	Task8.Auto_Start=Task_Start;
	strcpy(Task8.TaskName,"task8");
	Task8.priority=3;
*/

	Error=MYRTOS_CreateTask(&Task1);
	Error=MYRTOS_CreateTask(&Task2);

	MYRTOS_STARTOS();



	/*
	Error=MYRTOS_CreateTask(&Task6);
	Error=MYRTOS_CreateTask(&Task5);
	Error=MYRTOS_CreateTask(&Task6);
	Error=MYRTOS_CreateTask(&Task7);
	Error=MYRTOS_CreateTask(&Task8);
*/




    while (1)
    {

    }
}
/*
 **************************************************************
 *************************End *********************************
 **************************************************************
 */
