/*
 * stm32f103x6.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Salama Mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include <stdlib.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BAES							0X08000000UL
#define SYSTEM_MEMORY_BAES							0X1FFFF000UL
#define SRAM_MEMORY_BAES							0X20000000UL
#define PERIPHERALS_BAES	  						0X40000000UL
#define CORTEX_M3_INTERNAL _PERIPHERALS_BAES		0XE0000000UL

//================================================================================

//-----------------------------
//Base addresses for BUS AHB Peripherals
//-----------------------------

//RCC
#define RCC_BAES							0X40021000UL

//-----------------------------
//Base addresses for BUS APB2 Peripherals
//-----------------------------

//GPIO
//A,B Fully included in LQFP48 package
#define GPIOA_BAES							0X40010800UL
#define GPIOB_BAES							0X40010C00UL

//C,D Partial included in LQFP48 package
#define GPIOC_BAES							0X40011000UL
#define GPIOD_BAES							0X40011400UL

// E Not included in LQFP48 package
#define GPIOE_BAES							0X40011800UL

// EXTI
#define EXTI_BAES							0X40010400UL

// AFIO
#define AFIO_BAES							0X40010000UL

//Base addresses for BUS APB2 Peripherals

//=========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//Peripheral register:GPIO
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//Peripheral register:AFIO
typedef struct
{
	volatile uint32_t EVCR    ;
	volatile uint32_t MAPR    ;
	volatile uint32_t EXTICR1 ;
	volatile uint32_t EXTICR2 ;
	volatile uint32_t EXTICR3 ;
	volatile uint32_t EXTICR4 ;
	uint32_t RESERVED0        ;
	volatile uint32_t MAPR2   ;

}AFIO_TypeDef;

//Peripheral register:EXTI
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//Peripheral register:RCC
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;
//=========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA		((GPIO_TypeDef*)GPIOA_BAES)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BAES)
#define GPIOC		((GPIO_TypeDef*)GPIOC_BAES)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BAES)
#define GPIOE		((GPIO_TypeDef*)GPIOE_BAES)
#define RCC			((RCC_TypeDef*)RCC_BAES)

#define AFIO		((AFIO_TypeDef*)AFIO_BAES)

#define EXTI		((EXTI_TypeDef*)EXTI_BAES)
//==========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |=1<<6)
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |=1<<0)
//=============================================================================================

#endif /* INC_STM32F103X6_H_ */
