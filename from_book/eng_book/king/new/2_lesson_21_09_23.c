#include<stdio.h>
#include<stdlib.h>

#define SIZE  10

void printf_2Darray(void *array, size_t rows, size_t cols, char type);

int printf_1Darray(size_t length, int array[length]);

void hold_counter(void);

int main(void)
{   
    int matrix[4][3] = {
        {10,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,112}
    };

    printf_2Darray(matrix, 3,4,'d');

    int my_arr[SIZE] = {1,2,3,4,5};

    printf_1Darray(SIZE, my_arr);


    //working with static variable
    hold_counter();
    hold_counter();
    hold_counter();



    return 0;
}


void printf_2Darray(void *array, size_t rows, size_t cols, char type)
{
    if (type == 'd'){
        for(int i = 0, counter = 0; i < (rows * cols); ++i){
            if(counter == rows){
                putchar('\n');
                counter = 0;
            }
            printf("%d ", *((int*)array + i));
            ++counter;

        }
        putchar('\n');
    }
}

int printf_1Darray(size_t length, int array[length])
{
    for (int i = 0; i < length; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void hold_counter(void)
{
    static int counter = 0;
    
    for(int i = 0; i < 10; ++i){
        printf("i = %d ",i);
        ++counter;
    }
    putchar('\n');
    printf("counter = %5d\n", counter);
}