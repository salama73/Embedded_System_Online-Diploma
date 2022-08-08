/*
learn-in-depth
eng.salama
*/


#include "Platform_Types.h"
#define   STACK_Start_sp 0x20001000
extern int main(void);
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
extern unsigned int _E_TEXT;
extern unsigned int _stack_top;
void reset_handler (void);
void default_handler (void)
{
	reset_handler();
}


void nmi_handler (void)__attribute__((weak,alias("default_handler")));;
void h_fault_handler (void)__attribute__((weak,alias("default_handler")));;
void mm_fault_handler (void)__attribute__((weak,alias("default_handler")));;
void bus_fault_handler (void)__attribute__((weak,alias("default_handler")));;
void usage_fault_handler (void)__attribute__((weak,alias("default_handler")));;


uint32_t vectors[] __attribute__((section(".vectors"))) =
{
	(uint32_t) & _stack_top,
	(uint32_t) & reset_handler,
	(uint32_t) & nmi_handler,
	(uint32_t) & h_fault_handler,
	(uint32_t) & mm_fault_handler,
	(uint32_t) & bus_fault_handler,
	(uint32_t) & usage_fault_handler,
};


void reset_handler (void)
{
	//copy data from rom to ram
	unsigned int data_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	unsigned char *p_src = (unsigned char*)&_E_TEXT ;
	unsigned char *p_dst = (unsigned char*)&_S_DATA ;
	for (int i = 0; i < data_size; i++)
	{
		*((unsigned char*)p_dst++) = *((unsigned char*)p_src++) ;
	}

	//init the bss with 0
	unsigned int bss_size = (unsigned char *)&_E_BSS - (unsigned char *)&_S_BSS;
	p_dst = (unsigned char*)&_S_BSS ;
	for (int i = 0; i < bss_size; i++)
	{
		*((unsigned char*)p_dst++) = (unsigned char)0 ;
	}
	main();
}

