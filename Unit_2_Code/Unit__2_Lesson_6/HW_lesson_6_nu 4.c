#include <stdio.h>
#include<string.h>
struct students
{
    char name[20];
    int roll;
    float mark;
};

int main()
{
    struct students data[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("student number %d\n",i+1);
         printf("enter name\n");
         scanf("%s",data[i].name);
         printf("enter roll\n");
         scanf("%d",&data[i].roll);
         printf("enter mark\n");
         scanf("%f",&data[i].mark);
    }
        for(i=0;i<10;i++)
    {
         printf("student number %d\n",i+1);
         printf("name:%s\t\troll:%d\t\tmark:%f\n",data[i].name,data[i].roll,data[i].mark);

    }
}
