//bitwise operations

#include<stdio.h>


int main(void)
{   
    //setting a bit
    unsigned short x = 10;

    int bit_num = 5;

    x |= 1 << bit_num;

    printf("x = %hu\n", x);   //x = 42


    //clearing a bit
    unsigned short x2 = 17;

    x2 &= ~(1 << bit_num);
    printf("x2 = %hu\n", x2);   //x2 = 42


    //testing a bit
    unsigned x3 = 100;
    if( x3 & 1 << bit_num){
        puts("...");
    }


    return 0;
}