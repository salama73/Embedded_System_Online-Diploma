#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth:<salama>";
unsigned char const string_buffer2[100]="rodata section";
void main(void)
{
	uart_send_string(string_buffer);
}
