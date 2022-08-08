/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : main_function.h
 ============================================================================
 */

#ifndef main_function_h
#define main_function_h

#include "state.h"
#include "driver.h"

//state pointer to function
extern void (*mian_function_stata)();

// declaration state functions
STATE_define(algo_waiting);
STATE_define(alog_detection);


#endif /* DC_H_ */