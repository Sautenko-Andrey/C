//fibonacchi numbers
//0 1 1 2 3 5 8 13

#include<stdio.h>
#include<stdlib.h>
#include"common.h"

unsigned* fib_generator(size_t till_num);

int main(void)
{   

    unsigned * fibonacchi = fib_generator(10);
    printf_arr(fibonacchi, 10, 'u');

    return 0;
}

unsigned* fib_generator(size_t till_num)
{
    //unsigned fib_numbers[till_num];
    unsigned *fib_numbers = malloc(sizeof(unsigned) * till_num);
    *fib_numbers = 0;
    *(fib_numbers + 1) = 1;

    for (int i = 2; i< till_num; ++i){
        fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
    }

    return fib_numbers;
}