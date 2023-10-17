//#ifdef #ifndef

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define DEBUG

int normaliz_str(char *str);

int main(void)
{   
    char my_text[] = "i have been expecting this since 1999.it must be happened.";
    normaliz_str(my_text);

    #ifdef DEBUG
    puts(my_text);
    #endif

    #ifndef DEBUG
    puts("No debugging.");
    #endif

    return 0;
}

int normaliz_str(char *str)
{   
    int counter = 0;

    while(*str++){

        if (*str == '.'){
            *++str = toupper(*++str);
            counter++;
        }

        *str = tolower(*str);
        counter++;

        return counter;
    }
}