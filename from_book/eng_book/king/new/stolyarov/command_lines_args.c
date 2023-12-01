#include<stdio.h>


int main(int argc, char *argv[])
{
    printf("Start with: %s\n", argv[0]);
    printf("Firt argument: %s\n", argv[1]);

    char *ptr;
    for(ptr = argv[1]; *ptr; ++ptr){
        printf("%c ", *ptr);
    }
    printf("\n\n");

    printf("Total args: %d\n", argc);

    return 0;
}
