//Declarations

#include<stdio.h>

char digit_to_hex(int digit);   //slow version
char digit_to_hexFast(int digit);   //fast version

void call_me(void);

static int counter = 0;

int main(void)
{   
    extern int x;  //will define somewhere later

    
    call_me();
    call_me();
    call_me();


    
    


    return 0;
}

char digit_to_hex(int digit)
{
    const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}

char digit_to_hexFast(int digit)
{
    static const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}

void call_me(void)
{
    puts("Hi!");
    ++counter;
    printf("You called me %d times!\n", counter);
}