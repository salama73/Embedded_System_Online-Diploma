
/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : Collision_Avoidance.c
 ============================================================================
 */
#include "CA.h"

//variable
enum
{
	CA_waiting,
	CA_driving
}CA_state_id;

int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

//state pointer to function
void (*CA_stata)();

void US_set_distance(int distance)
{
	CA_distance=distance;
	(CA_distance<=CA_threshold)?(CA_stata=STATE(CA_waiting)) : (CA_stata= STATE(CA_driving));
	printf("Ultrasonic------distance=%d------>CA\n",CA_distance);
}


// define state functions
STATE_define(CA_waiting)
{
	// state name
	CA_state_id=CA_waiting;
	printf("CA_watinig_state   distance = %d    speed = %d \n",CA_distance,CA_speed);
	//state action
	CA_speed=0;
	DC_motor(CA_speed);
}
STATE_define(CA_driving)
{
	// state name
	CA_state_id=CA_driving;
	printf("CA_driving_state   distance = %d    speed = %d \n",CA_distance,CA_speed);
	//state action
	CA_speed=30;
	DC_motor(CA_speed);
}

