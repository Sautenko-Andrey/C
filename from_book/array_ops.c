#include<stdio.h>
#include<stdlib.h>

#define LEN 5

/*function which takes to arrays, multiplyes their values and put them into a new array,
afterwards sort it from less to high value*/

//simple sort array function
void sort_array(int array[], size_t len_array);
int* mul_array(int first_arr[], size_t len_first, int second_arr[], size_t len_second);


int main(void)
{   
    int values_1[LEN] = {1,2,3,4,5};
    int values_2[LEN] = {2,2,2,2,2};

    //calling mul_array()
    int *res = mul_array(values_1, LEN, values_2, LEN);

    //print res
    for(int i = 0; i < LEN; ++i){
        printf("%d ", *res++);
    }
    putchar('\n');

    free(res);


    return 0;
}

void sort_array(int array[], size_t len_array)
{
    int min_index;

    for(int i = 0; i < len_array - 1; ++i){
        min_index = i;

        for(int j = i + 1; j < len_array; ++j){
            if(array[min_index] > array[j]){
                min_index = j;
            }
        }

        if(min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int* mul_array(int first_arr[], size_t len_first, int second_arr[], size_t len_second)
{   
    if(len_first == len_second){
        int *new_arr = malloc(sizeof(int) * len_first);

        for (int i = 0; i < len_first; ++i){
            *new_arr++ = first_arr[i] * second_arr[i];
        }

        sort_array(new_arr, len_first);

        return new_arr;
    }
    else{
        puts("Arrays's size must be equal!");
        return NULL;
    }
}