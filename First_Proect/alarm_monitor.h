/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : alarm_monitor.h
 ============================================================================
 */

#ifndef alarm_monitor_h
#define alarm_monitor_h

#include "state.h"
#include "driver.h"

//state pointer to function
extern void (*alarm_monitor_stata)();

// declaration state functions
STATE_define(malarm_off);
STATE_define(malarm_on);
STATE_define(malarm_waiting);

#endif /* alarm_monitor */