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
#define NVIC_BASE									0xE000E100UL
#define NVIC_ISER0                                  *(volatile uint32_t*)(NVIC_BASE+0X00)
#define NVIC_ISER1                                  *(volatile uint32_t*)(NVIC_BASE+0X04)
#define NVIC_ICER0                                  *(volatile uint32_t*)(NVIC_BASE+0X80)
#define NVIC_ICER1                                  *(volatile uint32_t*)(NVIC_BASE+0X84)

//================================================================================

//-----------------------------
//Base addresses for BUS AHB Peripherals
//-----------------------------

//RCC
#define RCC_BASE							0X40021000UL

//-----------------------------
//Base addresses for BUS APB2 Peripherals
//-----------------------------

//GPIO
//A,B Fully included in LQFP48 package
#define GPIOA_BASE							0X40010800UL
#define GPIOB_BASE							0X40010C00UL

//C,D Partial included in LQFP48 package
#define GPIOC_BASE							0X40011000UL
#define GPIOD_BASE							0X40011400UL

// E Not included in LQFP48 package
#define GPIOE_BASE							0X40011800UL

// EXTI
#define EXTI_BASE							0X40010400UL

// AFIO
#define AFIO_BASE							0X40010000UL

// USART1
#define USART1_BASE							0X40013800UL

//SPI1
#define SPI1_BASE 							0x40013000UL

//Base addresses for BUS APB1 Peripherals
// USART2
#define USART2_BASE							0X40004400UL
// USART3
#define USART3_BASE							0X40004800UL
//SPI2
#define SPI2_BASE							0x40003800UL
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
	volatile uint32_t EVCR      ;
	volatile uint32_t MAPR      ;
	volatile uint32_t EXTICR[4] ;
	uint32_t RESERVED0          ;
	volatile uint32_t MAPR2     ;

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

typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_TypeDef;

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_TypeDef;
//=========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA		((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef*)GPIOE_BASE)
#define RCC			((RCC_TypeDef*)RCC_BASE)

#define AFIO		((AFIO_TypeDef*)AFIO_BASE)

#define EXTI		((EXTI_TypeDef*)EXTI_BASE)

#define USART1		((USART_TypeDef*)USART1_BASE)
#define USART2		((USART_TypeDef*)USART2_BASE)
#define USART3		((USART_TypeDef*)USART3_BASE)

#define SPI1		((SPI_TypeDef*)SPI1_BASE)
#define SPI2		((SPI_TypeDef*)SPI2_BASE)
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

// USART
#define RCC_USART1_CLK_Enable()	(RCC->APB2ENR |=1<<14)
#define RCC_USART2_CLK_Enable()	(RCC->APB1ENR |=1<<17)
#define RCC_USART3_CLK_Enable()	(RCC->APB1ENR |=1<<18)

#define RCC_USART1_CLK_Disable()	(RCC->APB2RSTR |=1<<14)
#define RCC_USART2_CLK_Disable()	(RCC->APB1RSTR |=1<<17)
#define RCC_USART3_CLK_Disable()	(RCC->APB1RSTR |=1<<18)

//SPI
#define RCC_SPI1_CLK_Enable()	(RCC->APB2ENR |=1<<12)
#define RCC_SPI2_CLK_Enable()	(RCC->APB1ENR |=1<<14)

#define RCC_SPI1_CLK_Disable()	(RCC->APB2RSTR |=1<<12)
#define RCC_SPI2_CLK_Disable()	(RCC->APB1RSTR |=1<<14)
//=============================================================================================

/*
 * *************************************************************
 *         IVT
 * *************************************************************
 *        EXTI
 * *************************************************************
 */
#define EXTI0_IRQ				6
#define EXTI1_IRQ				7
#define EXTI2_IRQ				8
#define EXTI3_IRQ				9
#define EXTI4_IRQ				10
#define EXTI5_IRQ				23
#define EXTI6_IRQ				23
#define EXTI7_IRQ				23
#define EXTI8_TRQ				23
#define EXTI9_IRQ				23
#define EXTI10_IRQ				40
#define EXTI11_IRQ				40
#define EXTI12_IRQ				40
#define EXTI13_IRQ				40
#define EXTI14_IRQ				40
#define EXTI15_IRQ				40
#define USART1_IRQ				37
#define USART2_IRQ				38
#define USART3_IRQ				39
#define SPI1_IRQ				35
#define SPI2_IRQ				36

//=====================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Enable()							(NVIC_ISER0 |=1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Enable()							(NVIC_ISER0 |=1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Enable()							(NVIC_ISER0 |=1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Enable()							(NVIC_ISER0 |=1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Enable()							(NVIC_ISER0 |=1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_to_EXTI9_Enable()					(NVIC_ISER0 |=1<<EXTI5_IRQ)
#define NVIC_IRQ40_EXTI10_to_EXTI15_Enable()				(NVIC_ISER1 |=1<<8) //40-32=8 bit number 8

//usart
#define NVIC_IRQ37_USART1_Enable()							(NVIC_ISER1 |=1<< ( USART1_IRQ - 32) )
#define NVIC_IRQ38_USART2_Enable()							(NVIC_ISER1 |=1<< ( USART2_IRQ - 32) )
#define NVIC_IRQ39_USART3_Enable()							(NVIC_ISER1 |=1<< ( USART3_IRQ - 32) )

//SPI
#define NVIC_IRQ35_SPI1_Enable()							(NVIC_ISER1 |=1<< ( SPI1_IRQ - 32) )
#define NVIC_IRQ36_SPI2_Enable()							(NVIC_ISER1 |=1<< ( SPI2_IRQ - 32) )
//=====================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Disable()						(NVIC_ICER0 |=1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Disable()						(NVIC_ICER0 |=1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Disable()						(NVIC_ICER0 |=1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Disable()						(NVIC_ICER0 |=1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Disable()						(NVIC_ICER0 |=1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_to_EXTI9_Disable()				(NVIC_ICER0 |=1<<EXTI5_IRQ)
#define NVIC_IRQ40_EXTI10_to_EXTI15_Disable()			(NVIC_ICER1 |=1<<8) //40-32=8 bit number 8

//usart
#define NVIC_IRQ37_USART1_Disable()							(NVIC_ICER1 |=1<< ( USART1_IRQ - 32) )
#define NVIC_IRQ38_USART2_Disable()							(NVIC_ICER1 |=1<< ( USART2_IRQ - 32) )
#define NVIC_IRQ39_USART3_Disable()							(NVIC_ICER1 |=1<< ( USART3_IRQ - 32) )

//SPI
#define NVIC_IRQ35_SPI1_Disable()							(NVIC_ICER1 |=1<< ( SPI1_IRQ - 32) )
#define NVIC_IRQ36_SPI2_Disable()							(NVIC_ICER1 |=1<< ( SPI2_IRQ - 32) )
//=====================================================================================================

#endif /* INC_STM32F103X6_H_ */
