#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,swap
    printf("Enter value of a \n");
    scanf("%f",&a);
    printf("Enter value of b \n");
    scanf("%f",&b);
    swap=a;
    a=b;
    b=swap;
    printf("After swapping, value of a =%f\n",a);
    printf("After swapping, value of b =%f\n",b);
    return 0;
}
