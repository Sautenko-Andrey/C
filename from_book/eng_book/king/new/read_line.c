#include<ctype.h>
#include<stdio.h>
#include"readline.h"

int read_line(char str[], int n)
{
    int symb;
    int i = 0;
    while(isspace(symb = getchar())){
        ;
    }

    while(symb != '\n' && symb != EOF){
        if( i < n ){
            str[i++] = symb;
        }
        symb = getchar();
    }
    str[i] = '\0';
    return i;
}