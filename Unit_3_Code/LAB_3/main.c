#include "Platform_Types.h"

#define SYSCTL_RCGC2_R          *(volatile uint32_t *)(0x400fe108)
#define GPIO_PORTF_DIR_R        *(volatile uint32_t *)(0x40025400)
#define GPIO_PORTF_DEN_R        *(volatile uint32_t *)(0x4002551c)
#define GPIO_PORTF_DATA_R       *(volatile uint32_t *)(0x400253fc)

int main(void)
{
	vuint32_t i;
	SYSCTL_RCGC2_R =0x20;
	for(int i=0;i<200;i++);
	GPIO_PORTF_DIR_R |=1<<3;
	GPIO_PORTF_DEN_R |=1<<3;
	while(1)
	{	
		GPIO_PORTF_DATA_R |=1<<3;
		for(int i=0;i<200000;i++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(int i=0;i<200000;i++);
	}
}
