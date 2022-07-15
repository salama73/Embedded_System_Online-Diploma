#include <stdio.h>
#include<string.h>
void reverse(char text[],int size);
int main()
{
	char text[100];
	int size;
    printf("enter text\n");
    gets(text);
    size=strlen(text);
    reverse(text,size);

}
void reverse(char text[],int size)
{
    if (size>=0)
    {
        printf("%c",text[--size]);
        reverse(text,size);
    }
}
