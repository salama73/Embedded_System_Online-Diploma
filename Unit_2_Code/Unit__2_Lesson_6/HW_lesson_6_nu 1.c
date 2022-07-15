#include <stdio.h>
#include<string.h>
struct students
{
    char name[20];
    int roll;
    float mark;
}student_1;
int main()
{
    printf("enter student name\n");
    scanf("%s",&student_1.name);
    printf("enter student number roll\n");
    scanf("%d",&student_1.roll);
    printf("enter student mark\n");
    scanf("%f",&student_1.mark);
    printf("name:%s\n",student_1.name);
    printf("roll:%d\n",student_1.roll);
    printf("mark:%f\n",student_1.mark);
}


