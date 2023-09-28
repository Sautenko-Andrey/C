#include<stdio.h>
#include"common.h"

int main(void)
{   
    printf("I love football."
    "Please let me watch it.\n");


    char text[] = "abc";

    printf("items = %ld\n", sizeof(text)/sizeof(*text));  //4

    char empty[] = "";
    printf("items = %ld\n", sizeof(empty)/sizeof(*empty));  //1

    char *ptr = "Andrey Sautenko";
    puts(ptr);

    return 0;
}