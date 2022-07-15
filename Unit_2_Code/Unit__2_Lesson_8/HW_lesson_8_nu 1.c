#include <stdio.h>
int main()
{
    int x=29;
    int* px=&x;
    printf("adress of x:%x\tvalue of x:%d\n",px,*px);
    x=34;
    printf("adress of x:%x\tvalue of x:%d\n",px,*px);
    x=7;
    printf("adress of x:%x\tvalue of x:%d\n",px,*px);
    return 0;
}
