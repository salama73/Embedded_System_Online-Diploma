/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
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

#endif /* STATE_H_ */

