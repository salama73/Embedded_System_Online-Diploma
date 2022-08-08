/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : main.c
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>

#include "pressure_sensor.h"
#include "main_function.h"
#include "alarm_monitor.h"
#include "alarm_sensor.h"

	void setup()
	{
		GPIO_INITIALIZATION();
		pressure_sensor_stata=STATE(ps_init);
		mian_function_stata=STATE(algo_waiting);
		alarm_monitor_stata=STATE(malarm_off);
		alarm_sensor_stata=STATE(alarm_off);
	}

int main ()
{
	setup();
	while (1)
	{
		pressure_sensor_stata();
		mian_function_stata();
		alarm_monitor_stata();
		alarm_sensor_stata();
	}

}
