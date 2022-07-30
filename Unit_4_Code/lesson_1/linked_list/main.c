/*
 * =================================================
 * File name     : main.c
 * Created on    : 29/7/2020
 * Author        : Salama
 * ==================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//******************************************************************************
//data
struct sdata
{
    int id;
    char name[40];
    float height;
};
//******************************************************************************
//node
struct ssdata
{
  struct sdata student;
  struct ssdata* pnextstudent;
};

struct ssdata* gpfirststudent=NULL;
//******************************************************************************
//APIS

void add_student()
{
    char temp[40];
    struct ssdata* pnewstudent ;
    struct ssdata* plaststudent ;
    //check list is empty -->yes
    if(gpfirststudent==NULL)
    {
        //create new record
        pnewstudent = (struct ssdata*)malloc(sizeof(struct ssdata));
        //assing it to gpfirststudent
        gpfirststudent = pnewstudent ;
    }

    //check list is empty -->no
    else
    {
        plaststudent=gpfirststudent;
        while(plaststudent->pnextstudent)
            plaststudent=plaststudent->pnextstudent;
        //create new record
        pnewstudent = (struct ssdata*)malloc(sizeof(struct ssdata));
        plaststudent->pnextstudent=pnewstudent;
    }
    //fill new record
    printf("\n enter id ");
    gets(temp);
    pnewstudent->student.id=atoi(temp);
    printf("\n enter  name ");
    gets( pnewstudent->student.name);
    printf("\n enter height ");
    gets(temp);
    pnewstudent->student.height=atof(temp);


    // set pnextstudent NULL
    pnewstudent->pnextstudent=NULL;
}
//******************************************************************************
int delete_student()
{
    char temp[40];
    unsigned int slected_id;
    printf("enter the student id to be deleted ");
    gets(temp);
    slected_id=atoi(temp);

    // list is not empty
    if(gpfirststudent)
    {
        struct ssdata* pselectstudent = gpfirststudent ;
        struct ssdata* ppreviousstudent = NULL;
        while(pselectstudent)
        {
            //compare each node with slected_id
            if(pselectstudent->student.id==slected_id)
            {
                //selected id is not firststudent
                if(ppreviousstudent)
                {
                    ppreviousstudent->pnextstudent=pselectstudent->pnextstudent;
                }
                ////selected id is firststudent
                else
                {
                    gpfirststudent=pselectstudent->pnextstudent;
                }
            free(pselectstudent);
            return 1;
            }
            ppreviousstudent=pselectstudent;
            pselectstudent=pselectstudent->pnextstudent;
        }
    printf("\n cannet find selected student");
    return 0;
    }
}
//******************************************************************************
void viwe_student()
{
    struct ssdata* pcurrentstudent = gpfirststudent ;
    int count=0;
    if(gpfirststudent==NULL)
    {
        printf("\n empty list");
    }
    else
    {
        while(pcurrentstudent)
        {
            printf("\n\trecord number %d",count+1);
            printf("\n id: %d",pcurrentstudent->student.id);
            printf("\n name: %s",pcurrentstudent->student.name);
            printf("\n height: %f",pcurrentstudent->student.height);
            count++;
            pcurrentstudent=pcurrentstudent->pnextstudent;
        }
    }
}
//******************************************************************************
void delete_all()
{
    struct ssdata* pcurrentstudent = gpfirststudent ;
    if(gpfirststudent==NULL)
    {
        printf("\n empty list");
    }
    else
    {
        while(pcurrentstudent)
        {
            struct ssdata* ptempstudent = pcurrentstudent;
            pcurrentstudent=pcurrentstudent->pnextstudent;
            free(ptempstudent);
        }
    gpfirststudent=NULL;
    }
}
//******************************************************************************
void find_student()// from number of index
{
    int count=1;
    char temp[40];
    unsigned int slected_index;
    printf("\nenter the slected_index\n ");
    gets(temp);
    slected_index=atoi(temp);
    struct ssdata* pcurrentstudent = gpfirststudent ;
    while(count)
    {
        if(slected_index==count)
        {
            printf("\n\trecord number %d",count);
            printf("\n id: %d",pcurrentstudent->student.id);
            printf("\n name: %s",pcurrentstudent->student.name);
            printf("\n height: %f",pcurrentstudent->student.height);
            count=0;
        }
        else
        {
            pcurrentstudent=pcurrentstudent->pnextstudent;
            count++;
        }
    }
}
//******************************************************************************
int lenght_list()
{
    struct ssdata* pcurrentstudent = gpfirststudent ;
    int count=0;
    while(pcurrentstudent)
    {
        count++;
        pcurrentstudent=pcurrentstudent->pnextstudent;
    }
    return count;
}
//******************************************************************************
void find_student_from_end()// from number of index from end
{
    int count=1,lenght,i;
    char temp[40];
    unsigned int slected_index;
    printf("\nenter the slected_index\n ");
    gets(temp);
    slected_index=atoi(temp);
    struct ssdata* pcurrentstudent = gpfirststudent ;
    lenght=lenght_list();
    pcurrentstudent = gpfirststudent;
    for (i=1;i<(lenght-slected_index+1);i++)
    {
        pcurrentstudent=pcurrentstudent->pnextstudent;
    }
    count=i;
    printf("\n\trecord number %d",count);
    printf("\n id: %d",pcurrentstudent->student.id);
    printf("\n name: %s",pcurrentstudent->student.name);
    printf("\n height: %f",pcurrentstudent->student.height);
}
//******************************************************************************
void middel_list()
{
    if(gpfirststudent==NULL)
    {
        printf("\n empty list");
    }
    else
    {
        struct ssdata* pcurrentstudent = gpfirststudent ;
        int count=1,lenght,i;
        lenght=lenght_list();
        if(lenght%2!=0)// lenght_list is odd number
        {
            lenght=(lenght/2)+1;
            while(count)
            {
                if(lenght==count)
                {
                    printf("\n\trecord number %d",count);
                    printf("\n id: %d",pcurrentstudent->student.id);
                    printf("\n name: %s",pcurrentstudent->student.name);
                    printf("\n height: %f",pcurrentstudent->student.height);
                    count=0;
                }
                else
                {
                    pcurrentstudent=pcurrentstudent->pnextstudent;
                    count++;
                }
            }
        }
        else// lenght_list is even number
        {
            lenght=(lenght/2);
            while(count)
            {
                if(lenght==count)
                {
                    for(i=0;i<2;i++)
                    {
                        printf("\n\trecord number %d",count);
                        printf("\n id: %d",pcurrentstudent->student.id);
                        printf("\n name: %s",pcurrentstudent->student.name);
                        printf("\n height: %f",pcurrentstudent->student.height);
                        pcurrentstudent=pcurrentstudent->pnextstudent;
                        count++;
                    }
                    count=0;
                }
                else
                {
                    pcurrentstudent=pcurrentstudent->pnextstudent;
                    count++;
                }
            }
        }
    }
}
//******************************************************************************
void main (void)
{
    while(1)
    {
        char temp[40];
        printf("\n=======================================\n");
        printf("\nchoose of the folwing option\n");
        printf("\n1 : add_student");
        printf("\n2 : delete_student");
        printf("\n3 : viwe_student");
        printf("\n4 : delete_all");
        printf("\n5 : viwe_student from number of index");
        printf("\n6 : get lenght of list");
        printf("\n7 : viwe_student from number of index from end");
        printf("\n8 : viwe_student in middelof list\n");
        gets(temp);
        printf("\n=======================================\n");

        switch(atoi(temp))
        {
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                viwe_student();
                break;
            case 4:
                delete_all();
                break;
            case 5:
                find_student();
                break;
            case 6:
                printf("\nlenght of list = %d", lenght_list());
                break;
            case 7:
                find_student_from_end();
                break;
            case 8:
                middel_list();
                break;
        }
        }
}
