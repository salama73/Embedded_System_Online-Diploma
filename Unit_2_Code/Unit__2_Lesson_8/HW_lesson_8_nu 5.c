#include <stdio.h>
#include <string.h>
struct employees
{
    char name[15];
    int salary;
};
int main()
{
    int i;
    struct employees employee[2]={{"salama",1000},{"khaled",3000}};
    struct employees *px=employee;
   /* for(i=0;i<2;i++)
    {
        printf("enter data of employee number:%d\n",i+1);
        printf("name?\n");
        scanf("%s",px->name);
        printf("salary?\n");
        scanf("%d",px->salary);
        px++;
    }*/
    for(i=0;i<2;i++)
    {
       printf("data of employee number:%d\n",i+1);
       printf("name:%s\t\tsalary:%d\n",px->name,px->salary);
    }
}
