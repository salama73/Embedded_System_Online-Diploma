
/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : pressure_sensor.c
 ============================================================================
 */

#include "pressure_sensor.h"

//variable
enum
{
	ps_init,
	ps_reading,
	ps_waiting
}ps_state_id;

int pressure_value=0;

//state pointer to function
void (*pressure_sensor_stata)();

STATE_define(ps_init)
{
	pressure_sensor_stata=STATE(ps_reading);
}

STATE_define(ps_reading)
{
    pressure_value=getPressureVal();
    set_pressure_value( pressure_value);
    pressure_sensor_stata=STATE(ps_waiting);

}

STATE_define(ps_waiting)
{
    delay(10000);
    pressure_sensor_stata=STATE(ps_reading);
    pressure_sensor_stata();
}