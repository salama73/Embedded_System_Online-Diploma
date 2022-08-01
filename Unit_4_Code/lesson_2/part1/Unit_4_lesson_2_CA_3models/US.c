
/*
 ============================================================================
 File Name        : Unit_4_lesson_2.c
 Author           : Salama Mohamed
 Version          :
 Description      : Ultrasonic.c
 ============================================================================
 */
#include "US.h"

//variable

enum
{
	US_busy
}US_state_id;

int US_distance=0;


//state pointer to function
void (*US_stata)();

void US_init()
{
	//init Ultrasonic sensor
	printf("US_INIT-------->Done\n");
}

int distance_random(int l , int r , int count);

// define state functions
STATE_define(US_busy)
{
	// state name
	US_state_id=US_busy;
	//state action
	US_distance = distance_random(45 , 55 , 1);

	printf("US_busy_state   distance = %d \n",US_distance);
	US_set_distance(US_distance);
	US_stata=STATE(US_busy);
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





