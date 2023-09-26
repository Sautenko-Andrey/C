//АРГУМЕНТЫ КОМАНДНОЙ СТРОКИ

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{   
    printf("Program: %s\n", __FILE__);

    if(argc > 1){
        for(int i = 1; i < argc; ++i){
            printf("%s\n", argv[i]);
        }
    }
    else{
        puts("No command line arguments entered.");
    }

    return 0;
}