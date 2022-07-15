#include <stdio.h>
#include <string.h>
int main()
{
    char arr[15]="w3resource";
    int x=strlen(arr)-1;
    char* px=arr;
    px=px+x;
    for(x;x>=0;x--)
    {
        printf("%c",*px);
        px--;
    }
    printf("\n");
}
