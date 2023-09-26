#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{   

    //working with toupper and tolower
    char symbol = 'a';

    //let's make it uppercase
    symbol = toupper(symbol);
    
    //we use putchar instead printf and puts for displaying char type
    putchar(symbol);

    //afterwards let's make this variable lowercase
    symbol = tolower(symbol);
    putchar(symbol);
    putchar('\n');


    //let's read a character and store it in the char variable
    char my_symbol = getchar();

    if(toupper(my_symbol)){
        my_symbol = tolower(my_symbol);
    }
    putchar(my_symbol);
    putchar('\n');


    //type conversion
    int x = 100, y = 4;
    float res = (float)x / y;
    printf("res = %f\n", res);

    long total;
    int t = 10000;
    total = (long)t * t;
    printf("%ld\n", total);

    return 0;
}