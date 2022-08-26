/*
 * LCD_Keypad_Driver.c
 *
 * Created: 24/08/2022 07:57:40 م
 * Author : elmnshawy
 */ 

#include "LCD.h"
#include "Keypad.h"
int main(void)
{
	char key_pressed;
    LCD_init();
	keypad_init();
    while (1) 
    {
		key_pressed=keypad_getkey();
		switch(key_pressed)
		{
			case 'c':
				lcd_Clear();
				break;
			case 'n':
				break;
			default:
				LCD_Character(key_pressed);
				break;
		}
    }
}

