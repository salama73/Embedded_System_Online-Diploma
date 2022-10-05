/*
 * Atmega32_Drivers.c
 *
 * Created: 30/08/2022
 * Author : salama mohamed
 */ 
//#define I2C_Act_As_Master
#define I2C_Act_As_Slave

#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "LCD.h"
#include "USART_Driver.h"
#include "SPI_Driver.h"
#include "I2C_Driver.h"

unsigned char data =0;

void init(void)
{
	GPIO_Pinconfig_t config ;
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_0 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_1 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_2 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_3 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_4 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_5 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_6 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
	
	config.GPIO_MODE =  GPIO_MODE_OUTPUT ;
	config.pinNumber = GPIO_PIN_7 ;
	MCAL_GPIO_Init( GPIOA , & config ) ;
}

void I2C_CALL (void)
{
	#ifdef I2C_Act_As_Slave
	data++;
	MCAL_I2C_Slave_TX(data) ;
	#endif
}

int main(void)
{
	// init i2c
	I2C_config_t I2C_Config ;
	I2C_Config.IRQ_EN =I2C_IRQ_ENABLE_Enable ;
	I2C_Config.P_IRQ_CALL = I2C_CALL ;
#ifdef I2C_Act_As_Master 
	I2C_Config.Speed_MODE = I2C_Speed_MODE_100 ;
	I2C_Config.Prescaler = I2C_Prescaler_1     ;
#endif
#ifdef I2C_Act_As_Slave
	I2C_Config.Own_Address = 0b11010000 ;
#endif
	MCAL_I2C_Init(&I2C_Config) ;
	// port a act as output
	init();
    while (1) 
    {		
	#ifdef I2C_Act_As_Master
		_delay_ms(500);
		data=MCAL_I2C_Master_RX( 0b11010001  );
		MCAL_GPIO_WritePort(GPIOA , data ) ;
	#endif
	/*
	#ifdef I2C_Act_As_Slave
		data++;
		MCAL_I2C_Slave_TX(data) ;
	#endif
	*/
    }
}

