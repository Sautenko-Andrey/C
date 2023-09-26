#include<stdio.h>

int main(void)
{   
    size_t length = sizeof(unsigned long long);
    printf("%zu\n", length);

    int x = 100;
    printf("Octal = %o\nHex = %x\n", x, x);


    return 0;
}