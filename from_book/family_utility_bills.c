#include<stdio.h>
#include<stdlib.h>

#define NEXT putchar('\n');
#define TOTAL


int comp(const void *arg1, const void *arg2);

int main(int argc, char *argv[])
{
    #if defined(TOTAL)
    printf("Program: %s\n", __FILE__);

    float total = 0;

    if (argc > 1){
        for(int i = 1; i < argc; ++i){
            total += (atof(argv[i]));
        }  
    }
    else{
        puts("No arguments on command line.");
    }

    printf("total: %f\n", total);

    #else

    printf("Program: %s\n", __FILE__);

    float all_bills[argc - 1];
    
    for(int i = 0, j = 1; i < argc - 1; ++i, ++j){
        all_bills[i] = atof(argv[j]);
    }

    qsort( all_bills, argc - 1, sizeof(float), comp );

    for(int i = 0; i < argc - 1; ++i){
        printf("%f ", all_bills[i]);
    }
    NEXT;

    #endif

    return 0;
}

int comp(const void *arg1, const void *arg2)
{
    return ( *(float*)arg1 - *(float*)arg2 );
}