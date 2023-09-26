#include<stdio.h>
#include"popular_func.h"
#include"popular_input_func.h"

#define SIZE 10

int main(void){

    //let's try our first function from "popular_func.h" printf_array
    int my_array[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    float fl_arr[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
    char symbols[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    short sh_ar[3] = {28, 89, 34};
    double koef_arr[4] = {0.00001, 0.00002, 0.00003, 0.00004};
    long double low_koef[2] = {0.000001, 0.000002};
    printf_array(my_array, 'i', SIZE);
    printf_array(fl_arr, 'f', sizeof(fl_arr) / sizeof(*fl_arr));
    printf_array(symbols, 'c', sizeof(symbols) / sizeof(*symbols));
    printf_array(sh_ar, 's', sizeof(sh_ar) / sizeof(*sh_ar));
    printf_array(koef_arr, 'd', sizeof(koef_arr) / sizeof(*koef_arr));
    printf_array(low_koef, 'l', sizeof(low_koef) / sizeof(*low_koef));

    //let's try memory_allocation_check()
    int *ptr_i = malloc(sizeof(int));
    memory_allocation_check(ptr_i);

    //let's try functions from  "popular_input_func.h"
    //fill_array
    short my_short_digs[SIZE];
    fill_array(my_short_digs, SIZE, 's');
    putchar('\n');
    printf("my_short_digs : ");
    printf_array(my_short_digs, 's', SIZE);


    return 0;
}