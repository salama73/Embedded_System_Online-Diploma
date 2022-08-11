/*
 ============================================================================
 File Name        : student.h
 Author           : Salama Mohamed
 Version          :
 Description      :  first_term_project_2
 ============================================================================
 */

#ifndef STUDENT_H_
#define STUDENT_H_
//#include "Platform_Types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

typedef struct
{
	char first_name[40];
	char last_name[40];
	int roll;
	float GPA;
	int cid[6];
}st_puf_t;

#define element_type st_puf_t

typedef struct
{
	int length;
	unsigned int  count;
	element_type* head;
	element_type* base;
	element_type* tail;

} fifo_buf_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL,
}fifo_statuts_t;

//APIS
fifo_statuts_t init_buf(fifo_buf_t* student,st_puf_t* buf,int length);
int chech_roll(fifo_buf_t* student,st_puf_t* buf,int id);
fifo_statuts_t FIFO_is_full(fifo_buf_t* student );
fifo_statuts_t add_student_manually(fifo_buf_t* student);
fifo_statuts_t fine_student_by_roll(fifo_buf_t* student);
fifo_statuts_t fine_student_by_first_name(fifo_buf_t* student);
fifo_statuts_t fine_student_registered_in_course(fifo_buf_t* student);
fifo_statuts_t number_of_student(fifo_buf_t* student);
fifo_statuts_t delete_student(fifo_buf_t* student);
void rotate(fifo_buf_t* student,st_puf_t* ptr);
fifo_statuts_t FIFO_dequeue_student(fifo_buf_t* fifo_buf );
fifo_statuts_t update_student(fifo_buf_t* student);
fifo_statuts_t print_all_student(fifo_buf_t* student);
fifo_statuts_t add_student_from_file(fifo_buf_t* student);


#endif /* STUDENT_H_ */
