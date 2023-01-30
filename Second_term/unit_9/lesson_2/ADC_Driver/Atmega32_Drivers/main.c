/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022
 * Author : salama mohamed
 */ 
//  servo motor
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
#include "LM35.h"

char Data[10] ;
uint16_t data  ;

int main(void)
{
	LM35_Init(CH0);
	_delay_ms(100);
	LCD_init();
	
    while (1) 
    {
		GOTO_XY(0,0);
		// red LM35 sensor
		data=LM35_Get_Tem(CH0);
		itoa(data,Data,10);
		LCD_String(Data);
		if (data<10)
		{
			lcd_Clear();
			LCD_String(Data);
			_delay_ms(500);
		}
    }
}