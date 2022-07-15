 #include <stdio.h>
    int main()
    {
        int number [10],row;
        int i,n;
        printf("enter number of element\n");
        scanf("%d",&row);
        for (i=0;i<row;i++)
        {
                printf("enter number%d\n",i+1);
                scanf("%d",&number[i]);
            }
//****************************************************
        printf("enter value of element to be searched\n");
        scanf("%d",&n);
 //*************************************************
        for (i=0;i<row;i++)
        {
          if (n==number[i])
          {
              printf("number found at the location  %d\n\n",i+1);
              break;
          }
          else if (i==(row-1))
              printf("number not found\n");

        }
 //****************************************************
        for (i=0;i<row;i++)
        {
           printf("%d\t",number[i]);
        }
        printf("\n");
//*******************************************************
    }
