 #include <stdio.h>
 #include<string.h>
    int main()
    {
        char text [30],reverse[30];
        int i,n=0;
        printf("enter a string \n");
        gets(text);
        n=strlen(text);
//****************************************************
        for (i=0;i<n;i++)
        {
          reverse[i]=text[n-i-1];
        }
 //****************************************************
        printf("text is:    %s\n",text);
        printf("reverse is:   %s\n",reverse);
//*******************************************************
    }
