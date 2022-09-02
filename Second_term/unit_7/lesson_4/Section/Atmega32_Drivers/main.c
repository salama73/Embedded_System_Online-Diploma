/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022 08:00:04 م
 * Author : elmnshawy
 */ 


#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "LCD.h"

int flag =1;
void GPIO_init (void)
{
	GPIO_Pinconfig_t config ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_6 ;
	MCAL_GPIO_Init( GPIOB , & config ) ;
}

void EXTI_0 (void)
{
	flag=1;
	LCD_String(" Learn - In -  ");
	LCD_cmd( Jump_to_second_line );
	LCD_String("    Depth  ");
	_delay_ms(1000);
}

void EXTI_init (void)
{
		EXTI_PinConfig_t Config;
		Config.EXTI_Number = EXTI_INT0 ;
		Config.Trigger_case = EXTI_Trigger_Falling;
		Config.P_IRQ_CALL = EXTI_0;
		Config.EXTI_EN = EXTI_IRQ_Enable ;
		MCAL_EXTI_GPIO_Init(&Config);
}



int main(void)
{

	
    LCD_init() ;
	EXTI_init();
    while (1) 
    {

		if(flag==1)
		{
			lcd_Clear();
			flag=0;
		}
    }
}


