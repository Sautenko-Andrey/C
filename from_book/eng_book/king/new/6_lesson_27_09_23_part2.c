#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"common.h"

#define COLS 5
#define ROWS 5
#define NEXT putchar('\n')

void create_arr(int len);
void create_and_proc_matrix(int rows, int cols);
int sum_array(const int array[], size_t len);
int sum_2Darray(const int array[][5], size_t len);
bool search(const int array[], size_t len, int key);
void store_zeros(int *array, size_t len);
void store_zeros2(int array[], size_t len);
double inner_product(const double *a, const double *b, size_t len);
int find_largest(const int *ptr_arr, size_t len);
int find_largest2(const int array[], size_t len);
void find_two_largest(const int *ptr_arr, size_t len, int *largest, int *sec_largest);

int main(void){

    //pointers and variable-length arrays
    create_arr(10);
    create_and_proc_matrix(10,10);
    int arr[10] = {1,2,3,4,5};
    int total = sum_array(arr,5);
    printf("total = %d\n", total);

    int nums[2][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10}
    };

    int sum_arr = sum_2Darray(nums, 2);
    printf("sum = %d\n", sum_arr);

    int vals[5] = {1,2,3,4,5};
    bool respond = search(vals, 5, 2);
    printf("respond = %d\n", respond);

    int zer[10];
    store_zeros(zer,10);
    printf_arr(zer, 10, 'i');

    int zer2[5];
    store_zeros2(zer2, 5);
    printf_arr(zer2, 5, 'i');

    //inner product
    double price1[3] = {10.00, 20.00, 30.00};
    double price2[3] = {11.00, 22.00, 33.00};

    double tot_sum = inner_product(price1, price2, 3);
    printf("tot_sum = %.2lf\n", tot_sum);

    //find largest
    int simple_array[10] = {1,13,-44,0,55, 100, -12,0,-133};
    int max = find_largest(simple_array, 10);
    printf("max = %d\n", max);

    //find largest 2
    int max2 = find_largest2(simple_array, 10);
    printf("max2 = %d\n", max2);

    //find two largest
    int larg, sec_larg;
    int arr2[10] = {10,20,30,40,55,45,16,17,18,19};
    find_two_largest(arr2, 10, &larg, &sec_larg);
    printf("Largest = %d, second largest = %d\n", larg, sec_larg);

    return 0;
}

void create_arr(int len)
{
    int array[len];
    int *ptr;

    for(ptr = array; ptr < array + len; ptr++){
        *ptr = 1;
    }

    printf_arr(array, len, 'i');
    NEXT;
}


void create_and_proc_matrix(int rows, int cols)
{
    int array[rows][cols];
    int *ptr;

    for(ptr = &array[0][0]; ptr <= &array[rows - 1][cols - 1]; ptr++){
        *ptr = 0;
    }

    printf_matrix(array, rows, cols, 'i');
    NEXT;
}

int sum_array(const int array[], size_t len)
{
    int sum = 0;
    const int *ptr = array;

    for(; ptr < array + len; ptr++){
        sum += *ptr;
    }

    return sum;
}

int sum_2Darray(const int array[][5], size_t len)
{
    int sum = 0;
    const int *ptr;

    for(ptr = &array[0][0]; ptr <= &array[len - 1][5 - 1]; ptr++){
        sum += *ptr;
    }

    return sum;
}

bool search(const int array[], size_t len, int key)
{
    const int *ptr = array;
    bool respond = false;
    for(; ptr < array + len; ptr++){
        printf("%d -- %d\n", *ptr, key);
        if(*ptr == key){
            respond = true;
        }
    }

    return respond;
}

void store_zeros(int *array, size_t len)
{
    for(int i = 0; i < len; ++i){
        *(array++) = 0;
    }
}

void store_zeros2(int array[], size_t len)
{
    int *ptr;
    for(ptr = array; ptr < array + len; ptr++){
        *ptr = 0;
    }
}

double inner_product(const double *a, const double *b, size_t len)
{   
    double res = 0;

    for(int i = 0; i < len; ++i){
        res += *(a + i) * *(b + i);
    }

    return res;
}

int find_largest(const int *ptr_arr, size_t len)
{
    int largest = *ptr_arr;

    for(int i = 1; i < len; ++i){
        if(largest < *(ptr_arr + i)){
            largest = *(ptr_arr + i);
        }
    }

    return largest;
}

int find_largest2(const int array[], size_t len)
{   
    const int *ptr = array;
    int max = *ptr;
    for(;ptr < array + len; ptr++){
        if(max < *ptr){
            max = *ptr;
        }
    }
    return max;
}

void find_two_largest(const int *ptr_arr, size_t len, int *largest, int *sec_largest)
{   
    int min;
    sec_largest = &min;

    *largest = min = *ptr_arr;
    for(int i = 1; i < len; ++i){
        if(*largest < *(ptr_arr + i)){
            *largest = *(ptr_arr + i);
        }
        else if(min > *(ptr_arr + i)){
            min = *(ptr_arr + i);
        }
    }


}