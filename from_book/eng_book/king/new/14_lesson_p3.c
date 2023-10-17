//the defined operator

#include<stdio.h>
#include<ctype.h>

//#define DEBUGGING

//simple function just for instance
void upper_str(char *str);


int main(void)
{   
    char my_text[] = "this is a simple text in lower-case.";
    upper_str(my_text);

    #if defined(DEBUGGING)    //start debugging
    puts(my_text);
    #endif                    //end debugging


    return 0;
}

void upper_str(char *str)
{
    while(*str){
        *str++ = toupper(*str);
    }
}