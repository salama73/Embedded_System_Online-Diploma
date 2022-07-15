    #include <stdio.h>
    int main() {
        char Alphabet,i;
        printf("Enter an Alphabet  \n");
        scanf("%c",&Alphabet);
        if(Alphabet=='a'||Alphabet=='A'||Alphabet=='e'||Alphabet=='E'||Alphabet=='i'||Alphabet=='I'||Alphabet=='o'
        ||Alphabet=='O'||Alphabet=='u'||Alphabet=='U')
            printf("%c is vowel \n",Alphabet);
        else
            printf("%c is constant \n",Alphabet);

    }
