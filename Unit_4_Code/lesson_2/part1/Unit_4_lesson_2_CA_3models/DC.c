
/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : DC_Motor.c
 ============================================================================
 */
#include "DC.h"

//variable
enum
{
	DC_idle,
	DC_busy
}DC_state_id;

int DC_speed=0;

//state pointer to function
void (*DC_stata)();

void DC_init()
{
	//init DC motor
	printf("DC MOTOR INIT -------->DONE\n");
}

void DC_motor(int speed)
{
	DC_speed=speed;
	DC_stata=STATE(DC_busy);
	printf("CA------speed=%d------>DC\n",DC_speed);
}

// define state functions
STATE_define(DC_idle)
{
	// state name
	DC_state_id=DC_idle;
	// call pwm to make speed = DC_speed
	printf("DC_idle_state   speed = %d \n",DC_speed);
}
STATE_define(DC_busy)
{
	// state name
	DC_state_id=DC_busy;
	// call pwm to make speed = DC_speed
	printf("DC_busy_state   speed = %d \n",DC_speed);
	DC_stata=STATE(DC_idle);
}



