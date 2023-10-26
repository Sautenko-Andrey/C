#include<ctype.h>
#include<stdio.h>
#include"readline.h"

int read_line(char str[], int n)
{
    int symbol, i = 0;

    while(isspace(symbol = getchar())){
        ;
    }

    while(symbol != '\n' && symbol != EOF ){
        if(i < n){
            str[i++] = symbol;
        }
        symbol = getchar();
    }
    str[i] = '\0';
    return i;
}