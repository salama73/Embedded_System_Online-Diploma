 #include <stdio.h>
    int main()
    {
        char text [30],character;
        int i,n=0;
        printf("enter a string \n");
        gets(text);
//****************************************************
        for (i=0;text[i]!=0;i++)
        {
          n++;
        }
 //****************************************************
        printf(" text is: %s\n",text);
        printf("length =  %d\n",n);
//*******************************************************
    }
