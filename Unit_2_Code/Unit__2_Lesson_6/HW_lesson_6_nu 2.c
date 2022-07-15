#include <stdio.h>
#include<string.h>
struct add
{
    float feet;
    float inch;
}x,y,sum;

int main()
{
    printf("enter information 1st distance\n ");
    printf("enter feet\n");
    scanf("%f",&x.feet);
    printf("enter inch\n");
    scanf("%f",&x.inch);
    printf("enter information 2st distance\n ");
    printf("enter feet\n");
    scanf("%f",&y.feet);
    printf("enter inch\n");
    scanf("%f",&y.inch);
    sum.feet=x.feet+y.feet;
    sum.inch=x.inch+y.inch;
    if(sum.inch>12)
    {
        sum.inch-=12;
        sum.feet++;
    }
    printf("sum of distance = %f - %.1f\n",sum.feet,sum.inch);
}
