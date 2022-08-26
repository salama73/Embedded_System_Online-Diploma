/*
 * Keypad.h
 *
 * Created: 25/08/2022 01:25:31 ص
 *  Author: elmnshawy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 1000000UL
#include <util/delay.h>
#include "Reg_Map.h"

#define R0    0
#define R1    1
#define R2    2
#define R3    3
#define C0    4
#define C1    5
#define C2    6
#define C3    7
 
#define Keypad_port         PORTD
#define Keypad_pin          PIND
#define Keypad_port_DDR     DDRD

void keypad_init(void);
char keypad_getkey(void);

#endif /* KEYPAD_H_ */