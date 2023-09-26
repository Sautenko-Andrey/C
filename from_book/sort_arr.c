#include<stdio.h>

void sort_arr(int array[], size_t len_arr);

void* min_dig(int array[], size_t len_arr);

int main(void)
{   
    //we've got array with integers
    int digits[] = {10,1,9,2,8,3,7,4,6,5};

    //let's compute its length
    size_t length_array = sizeof(digits) / sizeof(*digits);

    //let's sort array
    sort_arr(digits, length_array);

    //let's display what we got
    for(int i = 0; i < length_array; ++i){
        printf("%d ", digits[i]);
    }
    
    puts("");

    //we've got array with integers
    int numbers[] = {100, 34, 432, 0, -11, 23, 1090};

    //let's get size of it
    size_t len_numbers = sizeof(numbers) / sizeof(*numbers);

    //let's find minimum number in this array
    int *min_number = min_dig(numbers, len_numbers);

    //let's display minimum value
    printf("Minimum number is : %d\n", *min_number);


    return 0;
}

void sort_arr(int array[], size_t len_arr)
{
    int minimum_index;

    for (int i = 0; i < len_arr - 1; ++i){
        minimum_index = i;

        for(int j = i + 1; j < len_arr; ++j){
            if (array[minimum_index] > array[j]){
                minimum_index = j;
            }
        }

        if(minimum_index != i){
            int temp = array[i];
            array[i] = array[minimum_index];
            array[minimum_index] = temp;
        }
    }
}

void* min_dig(int array[], size_t len_arr)
{
    int minimum_index;

    for (int i = 0; i < len_arr - 1; ++i){
        minimum_index = i;

        for(int j = i + 1; j < len_arr; ++j){
            if (array[minimum_index] > array[j]){
                minimum_index = j;
            }
        }

        if(minimum_index != i){
            int temp = array[i];
            array[i] = array[minimum_index];
            array[minimum_index] = temp;
        }
    }

    int *ptr = array;

    return ptr;
}