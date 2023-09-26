#include<stdio.h>
#include"common.h"
#include<time.h>

#define MAX 10
//#define MANUAL_SORT
#define BIBL_SORT

int main(void)
{   
    int digits[MAX] = {5, 6, 1, 3, 7, 9, 4, 2, 8, 10};

    clock_t start = clock();

    #if defined(MANUAL_SORT)
    sort_int(digits, MAX);
    printf_arr(digits, MAX, 'i');  //done 0.000063

    #else

    sort_library(digits, MAX);
    printf_arr(digits, MAX, 'i');

    #endif

    clock_t finish = clock();
    execution_time(start, finish);   //done 0.000078

    return 0;
}