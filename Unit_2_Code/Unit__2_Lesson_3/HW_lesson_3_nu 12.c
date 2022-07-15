 #include <stdio.h>
    int main()
    {
        char character;
        int i;
        printf("enter a character\n");
        scanf("%c",&character);
        if(character>=65&&character<=122)
            printf("%d is an Alphabet\n",character);
        else
            printf("%c is not an Alphabet\n",character);
    }
