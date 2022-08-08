/*
 ============================================================================
 File Name        : project_1
 Author           : Salama Mohamed
 Version          :
 Description      : state.h
 ============================================================================
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_statefun_)    void ST_##_statefun_()
#define STATE(_statefun_)           ST_##_statefun_

void high_pressure(void);
void stop_alarm(void);
void start_alarm(void);
void set_pressure_value(int pressure_value);

#endif /* STATE_H_ */