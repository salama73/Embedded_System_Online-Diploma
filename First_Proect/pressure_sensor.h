/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : pressure_sensor.h
 ============================================================================
 */

#ifndef pressure_sensor_h
#define pressure_sensor_h

#include "state.h"
#include "driver.h"

// declaration state functions
STATE_define(ps_init);
STATE_define(ps_reading);
STATE_define(ps_waiting);

// state pointer
extern void (*pressure_sensor_stata)();

#endif /* pressure_sensor_ */