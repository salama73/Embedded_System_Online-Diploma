 #include <stdio.h>
    int main()
    {
        char text [30],character;
        int i,n=0;
        printf("enter a string \n");
        gets(text);
//****************************************************
        printf("enter a character  to find frequency\n");
        scanf("%c",&character);
 //*************************************************
        for (i=0;text[i]!=0;i++)
        {
          if (character>=65&&character<97)
          {
              if (text[i]==character||text[i]==(character+32))
              n++;
          }
          else if (character>=97&&character<=122)
          {
              if (text[i]==character||text[i]==(character-32))
              n++;
          }
          else
          {
              if (text[i]==character)
              n++;
          }

        }
 //****************************************************
        printf(" text is: %s\n",text);
        printf("frequency =  %d\n",n);
//*******************************************************
    }
