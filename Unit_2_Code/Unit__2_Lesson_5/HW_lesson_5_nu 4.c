#include <stdio.h>
#include<string.h>
int find_power(int number,int power);
int main()
{
	int power,number,result;
    printf("enter number and power\n");
    scanf("%d%d",&number,&power);
    printf("%d ^ %d =%d\n",number,power,find_power(number,power));
}
int find_power(int number,int power)
{
    if (power!=0)
    {
       power--;
       return (number*find_power(number,power));
    }
    else
        return 1;
}
