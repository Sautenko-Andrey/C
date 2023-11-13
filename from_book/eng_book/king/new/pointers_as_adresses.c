//Using pointers as adresses

#include<stdio.h>

typedef unsigned char BYTE;


int main(void)
{   
    //decalring a pointer to type BYTE (1 byte)
    BYTE *ptr;

    ptr = (BYTE*)0x1000;  //ptr contains adress 0x1000

    printf("ptr = %p\n", ptr);   //ptr = 0x1000




    return 0;
}