
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

int distance_random(int l , int r , int count);

// define state functions
STATE_define(CA_waiting)
{
	// state name
	CA_state_id=CA_waiting;
	//state action
	CA_speed=0;
	//state check
	//get_distance(CA_distance)
	CA_distance = distance_random(45 , 55 , 1);
	(CA_distance<=CA_threshold)?(CA_stata=STATE(CA_waiting)) : (CA_stata= STATE(CA_driving));
	printf("CA_watinig_state   distance = %d    speed = %d \n",CA_distance,CA_speed);
}
STATE_define(CA_driving)
{
	// state name
	CA_state_id=CA_driving;
	//state action
	CA_speed=30;
	//state check
	//get_distance(CA_distance)
	CA_distance = distance_random(45 , 55 , 1);
	(CA_distance<= CA_threshold)?(CA_stata=STATE(CA_waiting)) : (CA_stata= STATE(CA_driving));
	printf("CA_driving_state   distance = %d    speed = %d \n",CA_distance,CA_speed);
}

int distance_random(int l , int r , int count)
{
	int i;
	for(i=0 ; i<count ; i++)
	{
		int random_number = (rand() %(r-l-1)+l);
		return random_number;

	}
	return 0 ;
}
