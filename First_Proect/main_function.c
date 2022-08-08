
/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : main_function.c
 ============================================================================
 */
#include "main_function.h"

//variable
enum
{
	algo_waiting,
	alog_detection
}algo_state_id;

//state pointer to function
void (*mian_function_stata)();

int receive_pressure_value=0;
int pressure_threshold=20;

void set_pressure_value(int pressure_value)
{
    receive_pressure_value=pressure_value;
    mian_function_stata=STATE(alog_detection);
}

STATE_define(algo_waiting)
{
	mian_function_stata=STATE(alog_detection);
}

STATE_define(alog_detection)
{
    if(receive_pressure_value>pressure_threshold)
        high_pressure();
	mian_function_stata=STATE(algo_waiting);
}
