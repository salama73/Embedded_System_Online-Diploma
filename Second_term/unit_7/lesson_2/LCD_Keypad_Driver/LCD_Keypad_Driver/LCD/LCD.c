/*
 * LCD.c
 *
 * Created: 24/08/2022 07:58:21 م
 *  Author: elmnshawy
 */ 

#include "LCD.h"

#define _4_bit_mode
/*void LCD_check_busy (void)
{
	lcd_Data_Direction =0x00;              //input
	lcd_control_Port |= (1<<RW);             // read
	lcd_control_Port &= ~ (1<<rs);	       // rs=0 i.e select command reg
	while((lcd_Data_Port & (1<<7))>>7);
	lcd_Data_Direction =0xff;           //output
	lcd_control_Port &= ~(1<<RW);         // write
	_delay_ms(2);
}
*/
void LCD_init(void)
{
	lcd_control_Direction=0xff;
	lcd_Data_Direction=0xff;
	_delay_ms(20);
#ifdef _8_bit_mode
	LCD_cmd(_2L_8b);                              // 2 line 5*7 matrix in 4-bit mode
	LCD_cmd(Display_on_Cursor_off);              // Display on cursor off
	LCD_cmd(Entry_Mode);                        // take cursor to next position "shift cursor to right"
	LCD_cmd(Clear_Display);                    // Clear display screen
	_delay_ms(2);
#endif
#ifdef _4_bit_mode
	LCD_cmd(0x02);                // send for 4 bit initialization of LCD "shift cursor to left"
	LCD_cmd(_2L_4b);                              // 2 line 5*7 matrix in 4-bit mode
	LCD_cmd(Entry_Mode);                        // take cursor to next position "shift cursor to right"
	LCD_cmd(beginning_of_the_first_line);
	LCD_cmd(Display_on_Cursor_blinking);              // Display on cursor off
	LCD_cmd(Clear_Display);                    // Clear display screen
	_delay_ms(2);
#endif
}

void LCD_cmd( unsigned char cmd )
{
#ifdef _8_bit_mode
	lcd_Data_Port = cmd                                         // send command
	lcd_control_Port &= ~ (1<<rs);	
	lcd_control_Port &= ~ (1<<RW);							 // R/W=0 i.e MODE Write
	lcd_control_Port |= (1<<en);									// give high pulse to enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);							  // give low pulse to enable pin
	_delay_us(200);
#endif
#ifdef _4_bit_mode
	lcd_Data_Port = (lcd_Data_Port & 0x0F) | (cmd & 0xF0);            // send upper nibble of 8 bit
	lcd_control_Port &= ~ (1<<RW);							 // R/W=0 i.e MODE Write
	lcd_control_Port &= ~ (1<<rs);								 // rs=0 i.e select command reg
	lcd_control_Port |= (1<<en);									// give high pulse to enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);							  // give low pulse to enable pin
	_delay_us(200);
	lcd_Data_Port = (lcd_Data_Port & 0x0F) | (cmd << 4);		// sending lower nibble of 8 bit i.e 1byte
	lcd_control_Port |= (1<<en);							   // give high pulse to enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);						// give low pulse to enable pin
	_delay_ms(2);
#endif
}

void lcd_Clear()
{
	LCD_cmd (0x01);                   // send hex 01 to Clear display
	_delay_ms(2);
	LCD_cmd(0x80);                   // send hex 80 to Force Cursor to beginning of 1st line
}

void GOTO_XY(unsigned char line , unsigned char posision)
{
	if (line==0)
	{
		if(posision>=0 && posision<16)
			LCD_cmd(0X80+posision);
	}
	else if (line==1)
	{
		if(posision>=0 && posision<16)
			LCD_cmd(0XC0+posision);
	}
}

void LCD_Character( unsigned char character )
{
#ifdef _8_bit_mode
	lcd_Data_Port = character;    
	lcd_control_Port &= ~ (1<<RW);							 // R/W=0 i.e MODE Write                                     // send character
	lcd_control_Port &= ~ (1<<rs);								 // rs=0 i.e select command reg
	lcd_control_Port |= (1<<en);									// give high pulse to enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);							  // give low pulse to enable pin
	_delay_us(200);
#endif
#ifdef _4_bit_mode
	lcd_Data_Port = (lcd_Data_Port & 0x0F) | (character & 0xF0);			// send upper nibble of character
	lcd_control_Port &= ~ (1<<RW);							 // R/W=0 i.e MODE Write
	lcd_control_Port |= (1<<rs);										   //  set rs to select data register
	lcd_control_Port|= (1<<en);										  // set enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);									// reset enable pin
	_delay_us(200);
	lcd_Data_Port = (lcd_Data_Port & 0x0F) | (character << 4);         //send lower nibble
	lcd_control_Port |= (1<<en);                                   // set enable pin
	_delay_us(1);
	lcd_control_Port &= ~ (1<<en);                               // reset enable pin
	_delay_ms(2);
#endif
}

void LCD_String (char *string)
{
	int count=0;
	while(*string)
	{
		count++;
		LCD_Character(*string++);
		if (count==16)
		{
			GOTO_XY(1,0);
		}
		else if(count==32)
		{
			_delay_ms(500);
			lcd_Clear();
			GOTO_XY(0,0);
			count=0;
		}
	}
}