#include<stdio.h>

int biggest_int(int array[], size_t len_array);
int lowest_int(int array[], size_t len_array);


int main(void)
{   

    int numbers[10] = {5, -4500, 400, 0, 12, 1, -21, 1001, -99, -1};
    
    int max_num = biggest_int(numbers, 10);

    printf("Biggest value = %d\n", max_num);

    int min_num = lowest_int(numbers, sizeof(numbers) / sizeof(*numbers));
    printf("Lowest dig = %d\n", min_num);


    return 0;
}

int biggest_int(int array[], size_t len_array)
{
    int big = -10000;

    for (int i = 0; i < len_array; ++i){
        if(array[i] > big){
            big = array[i];
        }
    }

    return big;
}

int lowest_int(int array[], size_t len_array)
{
    int small = 100000;

    for (int i = 0; i < len_array; ++i){
        if(array[i] < small){
            small = array[i];
        }
    }

    return small;
}