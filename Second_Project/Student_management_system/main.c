/*
 ============================================================================
 File Name        : main.c
 Author           : Salama Mohamed
 Version          :
 Description      :  first_term_project_2
 ============================================================================
 */

#include "student.h"
st_puf_t buffer[50];
fifo_buf_t* student;
int main(void)
{
	int start=1;
	char choose[5];
    init_buf(&student,buffer,50);
    while(start)
    {
		DPRINTF("Choose from the following tasks\n");
		DPRINTF("1.  Add the Student Details Manually\n");
		DPRINTF("2.  fine_student_by_roll\n");
		DPRINTF("3.  fine_student_by_first_name\n");
		DPRINTF("4.  fine_student_registered_in_course\n");
		DPRINTF("5.  number_of_student\n");
		DPRINTF("6.  delete_of_student\n");
		DPRINTF("7.  FIFO_dequeue_student\n");
		DPRINTF("8.  update_student\n");
		DPRINTF("9.  print_all_student\n");
		DPRINTF("10. add_student_from_file\n");
		DPRINTF("11. Exit the program\n");
		gets(choose);
		switch(atoi(choose))
		{
		case 1:
		{
	    	add_student_manually(&student);
	    	break;
		}
		case 2:
		{
			fine_student_by_roll(&student);
	    	break;
		}
		case 3:
		{
			fine_student_by_first_name(&student);
	    	break;
		}
		case 4:
		{
			fine_student_registered_in_course(&student);
	    	break;
		}
		case 5:
		{
			number_of_student(&student);
	    	break;
		}
		case 6:
		{
			delete_student(&student);
	    	break;
		}
		case 7:
		{
			FIFO_dequeue_student(&student);
	    	break;
		}
		case 8:
		{
			update_student(&student);
	    	break;
		}
		case 9:
		{
			print_all_student(&student);
	    	break;
		}
		case 10:
		{
			add_student_from_file(&student);
	    	break;
		}
		case 11:
			start=0;
			break;
		}
    	DPRINTF("\n************************************************\n");
    }
}
