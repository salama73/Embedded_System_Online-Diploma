 #include <stdio.h>
    int main()
    {
        int number1,factorial=1,i,j;
        for(i=0;i<2;i++)
        {
             printf("enter a integer\n");
             scanf("%d",&number1);
             if(number1>0)
             {
                 for(j=1;j<=number1;j++)
                    factorial*=j;
                 printf("factorial=%d\n",factorial);
             }

             else
                printf("factorial of negative number does not axite \n");
        }
    }
