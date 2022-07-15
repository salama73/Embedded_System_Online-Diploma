#include <stdio.h>
#include<string.h>
int factorial(int number);
int main()
{
	int number;
    printf("enter a positive integer\n");
    scanf("%d",&number);
    printf("factorial of %d = %d\n",number,factorial(number));

}
int factorial(int number)
{
    if (number!=1)
    return number* factorial(number-1);
}
