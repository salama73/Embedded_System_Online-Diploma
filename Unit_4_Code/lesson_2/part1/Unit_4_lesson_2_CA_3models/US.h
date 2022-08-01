/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : Ultrasonic.h
 ============================================================================
 */

#ifndef US_H_
#define US_H_
#include "state.h"


// declaration state functions
STATE_define(US_busy);

// state pointer
extern void (*US_stata)();

void US_init();

#endif /* US_H_ */

