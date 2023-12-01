#include<stdio.h>

#ifndef TEST
#define TEST
#endif

#define NO_TEST


int main(void)
{
    #if defined PETROV
    puts("Here we doing some logic for customer Petrov");
    #elif defined CHAUSOV
    puts("Code for Chausov");
    #else
    puts("Code for reamining customers");
    #endif


    #undef NO_TEST

    #if defined NO_TEST
    #undef TEST
    #endif
    
    #ifndef TEST
    #error "Please define TEST"
    #endif
    

    puts("Doing some code...");

    return 0;
}
