 #include <stdio.h>
    int main()
    {
        int i,n,sum=0;
        printf("enter a integer\n");
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            sum+=i;
        }
        printf(" is sum=%d\n",sum);
    }
