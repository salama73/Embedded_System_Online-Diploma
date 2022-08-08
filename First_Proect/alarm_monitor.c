
/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : alarm_monitor.c
 ============================================================================
 */
#include "alarm_monitor.h"

//variable
enum
{
	malarm_off,
	malarm_on,
    malarm_waiting
}algo_state_id;

//state pointer to function
void (*alarm_monitor_stata)();

void high_pressure(void)
{
    alarm_monitor_stata=STATE(malarm_on);
}

STATE_define(malarm_off)
{
    stop_alarm();
}


STATE_define(malarm_on)
{
    start_alarm();
	alarm_monitor_stata=STATE(malarm_waiting);
}

STATE_define(malarm_waiting)
{
    delay(60000);
    alarm_monitor_stata=STATE(malarm_off);
}