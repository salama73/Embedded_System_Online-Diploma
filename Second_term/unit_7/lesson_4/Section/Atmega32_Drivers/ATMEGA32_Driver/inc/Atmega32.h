/*
 * Atmega32.h
 *
 * Created: 30/08/2022 
 * Author: Salama mohamed
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define F_CPU 16000000UL
#include <util/delay.h>

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include <stdlib.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define  GPIOA_Base				0X39

#define  GPIOB_Base				0X36

#define  GPIOC_Base				0X33

#define  GPIOD_Base			    0X30

#define  EXTI_Base				0X54

#define SREG					*((volatile uint8_t*)0X5F)  // Global Interrupt Enable (bit number 7 )

#define GICR					*((volatile uint8_t*)0X5B)  //  Interrupt Enable (bit number 7 and 6 and 5 )


//==============================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	uint8_t  PIN   ;
	uint8_t  DDR   ;
	uint8_t  PORT  ;
}GPIO_TypeDef;


typedef struct
{
	uint8_t  MCUCSR   ;
	uint8_t  MCUCR    ;
}EXTI_TypeDef;

//===============================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA		((GPIO_TypeDef*)GPIOA_Base)
#define GPIOB		((GPIO_TypeDef*)GPIOB_Base)
#define GPIOC		((GPIO_TypeDef*)GPIOC_Base)
#define GPIOD		((GPIO_TypeDef*)GPIOD_Base)

#define EXTI		((EXTI_TypeDef*)EXTI_Base)

//=========================================

//=====================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_GLOBAL_Enable()							(SREG |=1<<7)
#define EXTI_INT1_Enable()								(GICR |=1<<7)
#define EXTI_INT0_Enable()								(GICR |=1<<6)
#define EXTI_INT2_Enable()								(GICR |=1<<5)

//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_GLOBAL_Disable()							(SREG &=~(1<<7))
#define EXTI_INT1_Disable()								(GICR &=~(1<<7))
#define EXTI_INT0_Disable()								(GICR &=~(1<<6))
#define EXTI_INT2_Disable()								(GICR &=~(1<<5))
//======================================================================================================

#endif /* ATMEGA32_H_ */