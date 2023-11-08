//Low-level programming

#include<stdio.h>

int main(void)
{   
    //bitwise operators

    //bitwise shift operators
    unsigned short i,j;

    i = 13;         //i is    0000000000001101
    j = i << 2;     // i is now 52    0000000000110100
    j = i >> 2;     //i is now 3    0000000000000011    


    unsigned x, res;
    x = 5;            //0000000000000101

    res = x << 1;   // res = 0000000000001010   = 10
    printf("res = %d\n", res);   //10

    res = x >> 1; //0000000000000010 = 2
    printf("res = %d\n", res);


    return 0;
}