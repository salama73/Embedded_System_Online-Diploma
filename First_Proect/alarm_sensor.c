/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : alarm_sensor.c
 ============================================================================
 */
#include "alarm_sensor.h"

//variable
enum
{
	alarm_init,
	alarm_off,
	alarm_on,
	alarm_waiting
}alarm_state_id;

int i=0;

//state pointer to function
void (*alarm_sensor_stata)();

void stop_alarm(void)
{
	i=1;
	alarm_sensor_stata=STATE(alarm_off);
}

void start_alarm(void)
{
	i=0;
	alarm_sensor_stata=STATE(alarm_on);
}

STATE_define(alarm_init)
{
	alarm_sensor_stata=STATE(alarm_off);
}

STATE_define(alarm_waiting)
{
	alarm_sensor_stata=STATE(alarm_off);
}

STATE_define(alarm_off)
{
	Set_Alarm_actuator(i);
	alarm_sensor_stata=STATE(alarm_waiting);
}

STATE_define(alarm_on)
{
	Set_Alarm_actuator(i);
	alarm_sensor_stata=STATE(alarm_waiting);
}




