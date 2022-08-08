/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : alarm_sensor.h
 ============================================================================
 */

#ifndef alarm_sensor_h
#define alarm_sensor_h

#include "state.h"
#include "driver.h"

// declaration state functions
STATE_define(alarm_init);
STATE_define(alarm_off);
STATE_define(alarm_on);
STATE_define(alarm_waiting);
    
// state pointer
extern void (*alarm_sensor_stata)();

#endif /* alarm_sensor */