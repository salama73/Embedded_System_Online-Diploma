#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("Enter value of a \n");
    scanf("%f",&a);
    printf("Enter value of b \n");
    scanf("%f",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After swapping, value of a =%f\n",a);
    printf("After swapping, value of b =%f\n",b);
    return 0;
}
