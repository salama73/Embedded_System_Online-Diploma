/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : DC_Motor.h
 ============================================================================
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"




// declaration state functions
STATE_define(DC_idle);
STATE_define(DC_busy);

// state pointer
extern void (*DC_stata)();

void DC_init();

#endif /* DC_H_ */

