/*
 * Keypad.c
 *
 * Created: 25/08/2022 01:25:49 ص
 *  Author: elmnshawy
 */ 

#include "Keypad.h"
char keypad[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};
int Keypad_Row[]={R0,R1,R2,R3};
int Keypad_Col[]={C0,C1,C2,C3};
	
void keypad_init(void)
{
	Keypad_port_DDR=0xf0;  // pin{0,1,2,3} connected with row as input , pin{4,5,6,7} connected whit columns as output
	Keypad_port=0xff ;      // pull_up active with  input and output pins is high
}

char keypad_getkey(void)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		Keypad_port |=(0b1111<<4);// set all columns as high signal
		Keypad_port &=~(1<<Keypad_Col[i]);// set a column number i as low signal
		for(j=0;j<4;j++)
		{
			if(!(Keypad_pin & (1<<Keypad_Row[j])))
			{
				while(!(Keypad_pin & (1<<Keypad_Row[j])));
				return keypad[j][i];
			}
		}
	}
	return 'n';
}