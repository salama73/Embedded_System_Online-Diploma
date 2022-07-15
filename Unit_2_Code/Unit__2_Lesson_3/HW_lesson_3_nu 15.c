 #include <stdio.h>
    int main()
    {
        float number [100],average=0,sum=0;
        int n,i;
        printf("enter number of data\n");
        scanf("%d",&n);
        while(n>=100||n<=0)
        {
            printf("please enter number in rang 1 to 100\n");
            scanf("%d",&n);
        }

        for (i=0;i<=n;i++)
        {
            printf("enter number\n");
            scanf("%f",&number[i]);
            sum+=number[i];
        }
        average=sum/n;
        printf("average = %f",&average);
    }
