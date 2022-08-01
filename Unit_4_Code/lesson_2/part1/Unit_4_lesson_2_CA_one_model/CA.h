/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : Collision_Avoidance.h
 ============================================================================
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"



// declaration state functions
STATE_define(CA_waiting);
STATE_define(CA_driving);

// state pointer
extern void (*CA_stata)();



#endif /* CA_H_ */

