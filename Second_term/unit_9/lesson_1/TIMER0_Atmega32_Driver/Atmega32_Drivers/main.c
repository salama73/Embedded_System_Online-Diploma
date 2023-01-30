/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022
 * Author : salama mohamed
 */ 
// CTC MODE
#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "LCD.h"
#include "USART_Driver.h"
#include "SPI_Driver.h"
#include "I2C_Driver.h"
#include "EEPROM.h"
#include "TIMER0_Driver.h"
#include "PWM_Driver.h"
#include "Servo_Motor.h"


void TIMER0_CALL(void)
{
	MCAL_GPIO_TogglePin(GPIOA , GPIO_PIN_0 );
}
int main(void)
{	
	TIMER0_config_t TIMER0_Config ;
	TIMER0_Config.Clock_Source = TIMER0_Clock_Source_clk_1024 ;
	TIMER0_Config.Compare_Value =255 ;
	TIMER0_Config.OCIE0_EN = TIMER0_OCIE0_ENABLE_Disable;
	TIMER0_Config.Output_Compare_pin = TIMER0_Output_Compare_pin_Toggle ;
	TIMER0_Config.P_OCIE0_CALL = NULL ;
	TIMER0_Config.P_TOIE0_CALL = TIMER0_CALL ;
	TIMER0_Config.Timer0_Mode = TIMER0_MODE_CTC ;
	TIMER0_Config.TOIE0_EN = TIMER0_TOIE0_ENABLE_Enable ;
	MCAL_TIMER0_Init(&TIMER0_Config) ;
	
    while (1) 
    {
		
    }
}

