//СТАНДАРТНЫЕ МАКРОСЫ __DATE__, __TIME__, __LINE__, __FILE__
#include<stdio.h>
#include<stdlib.h>

#define SQRT(x) ( (x) * (x) )
#define OK puts("Success!")
#define NEXT putchar('\n')
//#define PRINTF_ALL


int main(void)
{   
    printf("Program: %s , error: line - %d - opening file.\n", __FILE__, __LINE__);
    //Program: stnadart_macroses.c , error: line - 7 - opening file.

    printf("Date: %s, time: %s\n", __DATE__, __TIME__);
    //Date: Aug 28 2023, time: 11:45:13 - дата компиляции

    int x = 0;
    if (SQRT(x) == 0){
        fprintf(stderr, "Program: %s, Error in line %d: value = 0.\n", __FILE__, __LINE__ - 1);
    }
    else{
        printf("x**2 = %d\n", SQRT(x));
    }


    double *ptr_d = malloc(sizeof(double) * 3);
    if(ptr_d == NULL){
        fprintf(stderr, "Memory allocation error in %d.\n", __LINE__ - 2);
        exit(1);
    }
    else{
        OK;
    }

    ptr_d = realloc(ptr_d, sizeof(ptr_d) + sizeof(double));
    if (ptr_d == NULL){
        fprintf(stderr, "Memory extension error in %d.\n", __LINE__ - 2);
        exit(1);
    }
    else{
        OK;
    }

    for(int i = 0; i < 4; ++i){
        *(ptr_d + i) = i * i;
    }

    #if defined(PRINTF_ALL)

    for(int i = 0; i < 4; ++i){
        printf("%f ", *(ptr_d ++));
    }
    NEXT;

    #endif
    

    return 0;
}