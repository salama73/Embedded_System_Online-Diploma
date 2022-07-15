 #include <stdio.h>
    int main()
    {
        int number [10][10],trans[10][10],row,col;
        int n,i;
        printf("enter number of row\n");
        scanf("%d",&row);
        printf("enter number of col\n");
        scanf("%d",&col);

        for (i=0;i<row;i++)
        {
            for(n=0;n<col;n++)
            {
                printf("enter number%d%d\n",i+1,n+1);
                scanf("%d",&number[i][n]);
            }
        }
//***********************************************
         for (i=0;i<row;i++)
        {
            for(n=0;n<col;n++)
            {
                printf("%d\t",number[i][n]);
            }
            printf("\n\n");
        }
 //*************************************************
         for (i=0;i<col;i++)
        {
            for(n=0;n<row;n++)
            {
                trans[i][n]=number[n][i];
            }
        }
 //****************************************************
         for (i=0;i<col;i++)
        {
            for(n=0;n<row;n++)
            {
                printf("%d\t",trans[i][n]);
            }
            printf("\n\n");
        }
//*******************************************************
    }
