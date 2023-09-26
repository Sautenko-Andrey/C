//ОТЛАДКА С ПОМОЩЬЮ КОНСТРУКЦИИ #IF #ENDIF

#include<stdio.h>
#include<stdlib.h>
#include"common_funcs.h"

#define NEXT putchar('\n')
#define DEBUG 0
//#define PRINT
//#define FILL

#if !defined(MAX)
#define MAX 10
#endif

int main(void)
{   
    int *ptr_array = malloc(sizeof(int) * MAX);

    #if DEBUG == 1
    if(ptr_array == NULL){
        fprintf(stderr,"Memory allocation error.\n");
        exit(1);
    }
    #endif

    #if defined(FILL)
    for(int i = 0; i < 10; ++i){
        *(ptr_array + i) = i + 1;
    }
    #endif

    #if defined(PRINT)

    for (int i = 0; i < 10; ++i){
        printf("%d ", *(ptr_array++));
    }
    NEXT;
    #endif

    #define LEN_ARR 5

    float all_prices[LEN_ARR] = {10.00, 25.23, -13.59, -0.12, 0};
    printf_arr(all_prices, 5, 'f');

    #undef LEN_ARR

    return 0;
}