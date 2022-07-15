#include <stdio.h>
int main() {
	int number,i;
	for(i=0;i<2;i++)
    {
    printf("Enter integer number %d\n",i+1);
	scanf("%d",&number);
	if(number%2==0)
        printf("%d is even\n",number);
    else
        printf("%d is odd\n",number);
    }

}
