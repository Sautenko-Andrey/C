// <ctype.h>


#include<stdio.h>
#include<ctype.h>


int main(void)
{   
    char symb = 'a';
    int num = 66;

    if(!isalnum(symb)){
        printf("Argument %c is not alphanumeric.\n", symb);
    }

    if(!isalnum(num)){
        printf("Argument %d is not alphanumeric.\n", num);
    }


    if(isalpha(num)){
        puts("Digit is alphabetic.");
    }

    if(islower(symb)){
        puts("Symbol is lower-case character.");
    }

    if(isupper('A')){
        puts("Symbol is upper-case character.");
    }

    if(isblank(' ') && isblank('\t')){
        puts("Blank characters both");
    }

    if(isspace(' ')){
        puts("Space character.");
    }

    if(ispunct(',')){
        puts("Punctuation character.");
    }


    return 0;
}