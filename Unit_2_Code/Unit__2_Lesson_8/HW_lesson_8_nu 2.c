#include <stdio.h>
int main()
{
    int x=65;
    int* px=&x;
    printf("The Alphabets are :\n");
    for(x;x<=90;x++)
        printf("%c\t",*px);
    printf("\n");
}
