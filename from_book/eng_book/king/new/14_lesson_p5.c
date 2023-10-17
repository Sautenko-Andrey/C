//#elif #else

#include<stdio.h>

//#define WIN64
//#define MAC_OS
#define LINUX

#ifndef MY_OS             //default definition for the macro MY_OS
#define MY_OS "Linux"
#endif


int main(void)
{   

    #if defined WIN64
    puts("Programming code for Windows begins here.");
    #elif defined MAC_OS
    puts("Programming code for MAC OS begins here.");
    #else
    printf("%s! Thanks God! Let's work!\n", MY_OS);
    #endif


    //conditioning out
    #if 0
    /*printf("MY_OS = %s\n", MY_OS)*/
    #endif

    return 0;
}
