 #include <stdio.h>
    int main()
    {
        float number1;
        int i;
        for(i=0;i<2;i++)
        {
             printf("enter a number\n");
             scanf("%f",&number1);
             if(number1>0)
                printf("%f is positive\n",number1);
             else if(number1<0)
                printf("%f is negative\n",number1);
             else
                printf("entered is zero\n");
        }
    }
