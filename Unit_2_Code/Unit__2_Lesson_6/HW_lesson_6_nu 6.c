#include <stdio.h>
#include<string.h>
union x
{
    char arr[32];
    int y;
}xx;
struct y
{
    char arr[32];
    int y,x;
}yy;
int main()
{
    printf("sizeof struct=%d\nsizeof union=%d\n",sizeof(xx),sizeof(yy));
}
