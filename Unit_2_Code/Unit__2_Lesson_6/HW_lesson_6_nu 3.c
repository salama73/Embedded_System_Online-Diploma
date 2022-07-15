#include <stdio.h>
#include<string.h>
struct number
{
    float real;
    float imag;
}x,y,sum;
void add (struct number x,struct number y,struct number sum )
{
    sum.imag=x.imag+y.imag;
    sum.real=x.real+y.real;
    printf("sum=%.1f+%.1f i\n",sum.real,sum.imag);
}
int main()
{
    printf("enter real of number_1\n");
    scanf("%f",&x.real);
    printf("enter imag on number_1\n");
    scanf("%f",&x.imag);
    printf("enter real of number_2\n");
    scanf("%f",&y.real);
    printf("enter imag on number_2\n");
    scanf("%f",&y.imag);
    add(x,y,sum);
}
