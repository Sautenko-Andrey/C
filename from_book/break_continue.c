#include<stdio.h>
#include<stdlib.h>

void show_cubes(int value);
int* sum_even(int number);

int main(void)
{   
    //show_cubes(15);
    int *total_even = sum_even(115);
    printf("Total sum = %d\n", *total_even);

    free(total_even);

    return 0;
}

void show_cubes(int value)
{
    for (int i = 1; i < value; ++i){
        if(i > 5){
            break;
        }
        printf("%d -> %d\n", i, i*i*i);
    }
}

int* sum_even(int number)
{
    int *ptr_sum = malloc(sizeof(int) * 2);

    for(int i = 1; i <= number; ++i){
        if(i % 2 != 0){
            continue;
        }

        printf("%d is even.\n", i);
        *ptr_sum += i;
    }

    return ptr_sum;
}