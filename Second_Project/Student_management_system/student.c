/*
 ============================================================================
 File Name        : student.c
 Author           : Salama Mohamed
 Version          :
 Description      :  first_term_project_2
 ============================================================================
 */

#include "student.h"
char temp[40];
//*************************************************************************************
fifo_statuts_t init_buf(fifo_buf_t* student,st_puf_t* buf,int length)
{
	student->base=buf;
	student->head=buf;
	student->tail=buf;
	student->count=0;
	student->length=length;
	if(student->base && student->length)
		return FIFO_NO_ERROR;
	else
		return FIFO_NULL;
}
//***************************************************************************************
fifo_statuts_t add_student_manually(fifo_buf_t* student)
{
	if(FIFO_is_full(student )==FIFO_NO_ERROR)
	{
		int m=1,i;
		DPRINTF("Enter student information\n");
		DPRINTF("Enter roll \n");
		gets(temp);
		//h=distance_random(1 , 10 , 1);
		m=chech_roll(student,student->base,atoi(temp));
		if(m==1)
		{
			student->head->roll=atoi(temp);
			DPRINTF("Enter first name \n");
			gets(student->head->first_name);
			DPRINTF("Enter last name \n");
			gets(student->head->last_name);
			DPRINTF("Enter GPA \n");
			gets(temp);
			student->head->GPA=atof(temp);
			DPRINTF("Mathematics----->>120\t\tEnglish----->>121\t\t----->>Chemistry----->>122\nPhysics----->>123\t\tThermodynamics----->>124\t\tProgramming----->>125\nCommunication----->>126\t\tProbability----->>127\n");
			DPRINTF("Enter course id \n");
			for(i=0;i<6;i++)
			{
				gets(temp);
				student->head->cid[i]=atoi(temp);
			}
			student->count++;
			m=student->length-student->count;
			DPRINTF("number of student=%d is successful\n",50-m);
			if(student->head==(student->base+(student->length * sizeof(st_puf_t))))
				student->head=student->base;
			else
				student->head++;
		}
		else
			DPRINTF("the roll is already taken \n");
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is failed\n");
		return (FIFO_is_full(student));
	}
}
//******************************************************************************
int chech_roll(fifo_buf_t* student,st_puf_t* buf,int id)
{

	st_puf_t* ptr_student=buf;
	int check=1,i;
	int vv=student->count;
	for(i=0;i<vv;i++)
	{
		if(ptr_student->roll==id)
		{
			check=0;
			return check;
		}
		else
			check=1;
		ptr_student++;
	}
	return check;
}
//********************************************************************************
fifo_statuts_t FIFO_is_full(fifo_buf_t* student )
{
	//fifo valid
	if (! student->head || ! student->base || ! student->tail)
		return FIFO_NULL;

	// fifo is full
	if (student->count >= student->length)
	{
		DPRINTF("fifo is full\n");
		return FIFO_FULL;
	}
	return FIFO_NO_ERROR;
}
//*******************************************************************************
fifo_statuts_t fine_student_by_roll(fifo_buf_t* student)
{
	if(student->count!=0)
	{
		int id,i;
		st_puf_t* ptr_student=student->base;
		DPRINTF("Enter roll \n");
		gets(temp);
		id=atoi(temp);
		for(i=1;i<=student->count;i++)
		{
			if(ptr_student->roll==id)
			{
				DPRINTF("student number  %d\n",i);
				DPRINTF(" first name------>>\t%s \n",ptr_student->first_name);
				DPRINTF(" last name------>>\t%s \n",ptr_student->last_name);
				DPRINTF(" roll------>>\t%d \n",ptr_student->roll);
				DPRINTF(" GPA ------>>\t%f \n",ptr_student->GPA);
				for(i=0;i<6;i++)
					DPRINTF("course id number %d------->>\t%d\n",i,ptr_student->cid[i]);
				return FIFO_NO_ERROR;
			}
			ptr_student++;
		}
		DPRINTF(" the number of roll not found\n");
	}
	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//*****************************************************************************
fifo_statuts_t fine_student_by_first_name(fifo_buf_t* student)
{
	if(student->count!=0)
	{
		int i,j;
		st_puf_t* ptr_student=student->base;
		DPRINTF("Enter first name \n");
		gets(temp);
		for(i=1;i<=student->count;i++)
		{
			if (stricmp(temp, ptr_student->first_name)==0)
			{
				DPRINTF("student number  %d\n",i);
				DPRINTF(" first name------>>\t%s \n",ptr_student->first_name);
				DPRINTF(" last name------>>\t%s \n",ptr_student->last_name);
				DPRINTF(" roll------>>\t%d \n",ptr_student->roll);
				DPRINTF(" GPA ------>>\t%f \n",ptr_student->GPA);
				for(j=0;j<6;j++)
					DPRINTF("course id number %d------->>\t%d\n",i,ptr_student->cid[j]);
			}
			ptr_student++;
		}
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//******************************************************
fifo_statuts_t fine_student_registered_in_course(fifo_buf_t* student)
{
	int i,j,id;
	st_puf_t* ptr_student=student->base;
	DPRINTF("Enter id course \n");
	gets(temp);
	id=atoi(temp);
	if(student->count!=0)
	{
		for(i=1;i<=student->count;i++)
		{
			for(j=0;j<6;j++)
			{
				if(ptr_student->cid[j]==id)
				{
					DPRINTF(" first name------>>\t%s \n",ptr_student->first_name);
					DPRINTF(" roll------>>\t%d \n",ptr_student->roll);
				}
			}
			ptr_student++;
		}
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//***********************************************************************
fifo_statuts_t number_of_student(fifo_buf_t* student)
{
	if(student->count==0)
	{
		DPRINTF("FIFO is empty\n");
		return FIFO_EMPTY;
	}
	else if(student->count==50)
	{
		DPRINTF("FIFO is Full\n");
		return FIFO_FULL;
	}
	else
	{
		DPRINTF("number of student= %d \n",student->count);
		return FIFO_NO_ERROR;
	}
}
//****************************************************************************
fifo_statuts_t delete_student(fifo_buf_t* student)
{
	if(student->count!=0)
	{
		st_puf_t swap={0};
		int id,i;
		st_puf_t* ptr_student=student->base;
		DPRINTF("Enter roll \n");
		gets(temp);
		id=atoi(temp);
		for(i=1;i<=student->count;i++)
		{
			if(ptr_student->roll==id)
			{
				rotate(student,ptr_student);
				student->head--;
				*(student->head)=swap;
				student->count--;
				return FIFO_NO_ERROR;
			}
			ptr_student++;
		}
		DPRINTF("the student not found \n");
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//***********************************************************************************
void rotate(fifo_buf_t* student,st_puf_t* ptr)
{
	st_puf_t swap;
	while(student->head!=ptr)
	{
		swap=*ptr;
		*ptr=*(ptr+1);
		*(ptr+1)=swap;
		ptr++;
	}
}
//************************************************************************************
fifo_statuts_t FIFO_dequeue_student(fifo_buf_t* fifo_buf )
{
	static int i=0;
	int j;
	//fifo valid
	if (! fifo_buf->head || ! fifo_buf->base || ! fifo_buf->tail)
		return FIFO_NULL;

	//fifo is empty
	if(fifo_buf->count==0)
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
	DPRINTF("student number  %d\n",++i);
	DPRINTF(" first name------>>\t%s \n",fifo_buf->tail->first_name);
	DPRINTF(" last name------>>\t%s \n",fifo_buf->tail->last_name);
	DPRINTF(" roll------>>\t%d \n",fifo_buf->tail->roll);
	DPRINTF(" GPA ------>>\t%f \n",fifo_buf->tail->GPA);
	for(j=0;j<6;j++)
		DPRINTF("course id number %d------->>\t%d\n",i,fifo_buf->tail->cid[j]);

	fifo_buf->count--;
	//circler fifo
	if(fifo_buf->tail==(fifo_buf->base+(fifo_buf->length * sizeof(element_type))))
		fifo_buf->tail=fifo_buf->base;
	else
		fifo_buf->tail++;

	return FIFO_NO_ERROR;
}
//*******************************************************
fifo_statuts_t update_student(fifo_buf_t* student)
{
	if(student->count!=0)
	{
		int id,i;
		st_puf_t* ptr_student=student->tail;
		DPRINTF("Enter roll \n");
		gets(temp);
		id=atoi(temp);
		for(i=1;i<=student->count;i++)
		{
			if(ptr_student->roll==id)
			{
				i=1000;
				break;
			}
			ptr_student++;
		}
		// i=1000 at the program found the roll
		if(i==1000)
		{
			int start=1;
			while(start)
			{
				DPRINTF("1: first_name\t\t2: last_name\t\t3: roll\t\t4: id course\t\t5: GPA\t\t6:Exit\n")
				gets(temp);
				id=atoi(temp);
				switch(id)
				{
				case 1:
				{
					DPRINTF("Enter new first name \n");
					gets(ptr_student->first_name);
					break;
				}
				case 2:
				{
					DPRINTF("Enter new last name \n");
					gets(ptr_student->last_name);
					break;
				}
				case 3:
				{
					DPRINTF("enter new roll\n");
					gets(temp);
					if(chech_roll(student, student->base, atoi(temp)))
					ptr_student->roll=atoi(temp);
					else
						DPRINTF("The Roll Number %d is already taken \n",atoi(temp));
					break;
				}
				case 4:
				{
					DPRINTF("Mathematics----->>120\t\tEnglish----->>121\t\t----->>Chemistry----->>122\nPhysics----->>123\t\tThermodynamics----->>124\t\tProgramming----->>125\nCommunication----->>126\t\tProbability----->>127\n");
					DPRINTF("Enter new course id \n");
					for(i=0;i<6;i++)
					{
						gets(temp);
						ptr_student->cid[i]=atoi(temp);
					}
					break;
				}
				case 5:
				{
					DPRINTF("Enter new GPA \n");
					gets(temp);
					ptr_student->GPA=atof(temp);
					break;
				}
				case 6:
					start=0;
					break;
				}
			}
		}
		else
			DPRINTF("the student not found \n");
		return FIFO_NO_ERROR;
	}

	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//****************************************************************
fifo_statuts_t print_all_student(fifo_buf_t* student)
{
	int j,i;
	//fifo valid
	if (! student->head || ! student->base || ! student->tail)
		return FIFO_NULL;
	if(student->count!=0)
	{
		st_puf_t* ptr_student=student->tail;
		for(i=1;i<=student->count;i++)
		{
			DPRINTF("student number  %d\n",i);
			DPRINTF(" first name------>>\t%s \n",ptr_student->first_name);
			DPRINTF(" last name------>>\t%s \n",ptr_student->last_name);
			DPRINTF(" roll------>>\t%d \n",ptr_student->roll);
			DPRINTF(" GPA ------>>\t%f \n",ptr_student->GPA);
			for(j=0;j<6;j++)
				DPRINTF("course id number %d------->>\t%d\n",i,ptr_student->cid[j]);
			//circler fifo
			if(ptr_student==(student->base+(student->length * sizeof(st_puf_t))))
				ptr_student=student->base;
			else
				ptr_student++;
		}
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is empty\n");
		return FIFO_EMPTY;
	}
}
//**********************************************************
fifo_statuts_t add_student_from_file(fifo_buf_t* student)
{
	if(FIFO_is_full(student )==FIFO_NO_ERROR)
	{
		int flag=0;
	    FILE * infile;
	    infile=fopen("inputs.txt","r");
	    char line[100];
	    const char* part;
	    int Number_Lines = 0 , Number_Parts = 0 ;
		// the file is opened or not
		if(!infile)
		{
			DPRINTF("The file can not be opened \n");
		}
		else
		{
			while(fgets(line ,sizeof(line),infile ))
			{
				Number_Lines++;
				part = strtok(line ," ");
				Number_Parts = 0 ;
				// looping untill the line end
				while(part != NULL)
				{
					++Number_Parts;
					switch(Number_Parts)
					{
					case 1:
					{
						if(chech_roll(student,student->base,atoi(part)) == 1)
						{
							flag=0;
							student->head->roll = atoi(part);
						}
						else
						{
							DPRINTF("The Roll Number %d is already taken \n",atoi(part));
							flag=1;
						}
						break;
					}
					case 2:
						strcpy(student->head->first_name,part);
						break;
					case 3:
						strcpy(student->head->last_name,part);
						break;
					case 4:
						student->head->GPA= atof(part);
						break;
					case 5:
						student->head->cid[0] = atoi(part);
						break;
					case 6:
						student->head->cid[1] = atoi(part);
						break;
					case 7:
						student->head->cid[2] = atoi(part);
						break;
					case 8:
						student->head->cid[3] = atoi(part);
						break;
					case 9:
						student->head->cid[4] = atoi(part);
						break;
					case 10:
						student->head->cid[5] = atoi(part);
						break;
					}
					part = strtok(NULL ," ");
				}
				if(flag==1)
					continue;
				student->count++;
				DPRINTF("the roll number: =%d is successful\n",student->head->roll);
				DPRINTF("---------------------->>>>>%d\n",student->count);
				if(student->head==(student->base+(student->length * sizeof(st_puf_t))))
					student->head=student->base;
				else
					student->head++;
			}
		}
	    fclose(infile);
		return FIFO_NO_ERROR;
	}
	else
	{
		DPRINTF("fifo is failed\n");
		return (FIFO_is_full(student));
	}
}
//***********************************************************
