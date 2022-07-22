#include "Platform_Types.h"
#define RCC_BASE        0x40021000
#define GPIOA_BASE      0x40010800
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE+0x18)
#define GPIO_CRH       *(volatile uint32_t *)(GPIOA_BASE+0x04)
//#define GPIO_ODR       *(volatile uint32_t *)(GPIOA_BASE+0x0c)
unsigned char g_variable[3]={1,2,3};
unsigned char const const_variable[3]={1,2,3};

typedef union
{
	vint32_t all_fieldes;
	struct
	{
		vint32_t reserved:13;
		vint32_t pin_13:1;
	}pin;
}R_ODR_t;
volatile R_ODR_t* R_ODR =(volatile R_ODR_t *)(GPIOA_BASE+0x0c);
int main(void)
{
	RCC_APB2ENR |=1<<2;
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
	while(1)
	{
		R_ODR->pin.pin_13=1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.pin_13=0;
		for(int i=0;i<5000;i++);
	}
}
