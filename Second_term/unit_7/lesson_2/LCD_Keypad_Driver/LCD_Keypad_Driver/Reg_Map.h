/*
 * Reg_Map.h
 *
 * Created: 22/08/2022 08:09:45 م
 *  Author: elmnshawy
 */ 


#ifndef REG_MAP_H_
#define REG_MAP_H_

#define  PORTA    *((volatile unsigned char*)0X3B)
#define  DDRA     *((volatile unsigned char*)0X3A)
#define  PINA     *((volatile unsigned char*)0X39)

#define  PORTB    *((volatile unsigned char*)0X38)
#define  DDRB     *((volatile unsigned char*)0X37)
#define  PINB     *((volatile unsigned char*)0X36)

#define  PORTC    *((volatile unsigned char*)0X35)
#define  DDRC     *((volatile unsigned char*)0X34)
#define  PINC     *((volatile unsigned char*)0X33)

#define  PORTD    *((volatile unsigned char*)0X32)
#define  DDRD     *((volatile unsigned char*)0X31)
#define  PIND     *((volatile unsigned char*)0X30)

#define  Set_bit(reg,bit)      (reg |=(1<<bit))
#define  Reset_bit(reg,bit)    (reg &=~(1<<bit))
#define  Toggle_bit(reg,bit)   (reg ^=(1<<bit))
#define  Read_bit(reg,bit)     ((reg & (1<<bit))>>bit)


#endif /* REG_MAP_H_ */