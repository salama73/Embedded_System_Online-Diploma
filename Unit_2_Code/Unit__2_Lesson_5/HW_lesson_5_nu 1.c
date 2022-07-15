#include <stdio.h>
#include<string.h>
int prime_number(int number);
int main()
{
	int interval_1,interval_2,i,result;
    printf("enter tow interval number\n");
    scanf("%d%d",&interval_1,&interval_2);
    printf("primer number between %d and %d are:",interval_1,interval_2 );
    for(i=interval_1;i<=interval_2;i++)
    {
        result=prime_number(i);
        if(result==0)
        printf("  %d",i);
    }
}
int prime_number(int number)
{
    int i,check=0;
    for(i=2;i<=number/2;i++)
    {
        if (number%i==0)
        {
            check=1;
            break;
        }
    }
    return check;
}
