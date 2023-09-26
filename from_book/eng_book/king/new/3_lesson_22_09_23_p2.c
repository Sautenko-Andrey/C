#include<stdio.h>
#include<stdlib.h>

void merely_print_value(const int *x);

//function which returns larger value using pointers
int* larger(int *x, int *y);

//function returns middle value of the array
int* middle_value(int array[], size_t len);

//function receive an array and returns first, last and middle values
void get_three_vals(int array[], size_t len, int *first, int *mid, int *last);

//function compute sum and average of arrays's values
void get_sum_and_avg(int array[], size_t len, int *sum_el, int *avg_el);




int main(void)
{   
    int some_x = 123;

    merely_print_value(&some_x);

    //comparing two integer values and return larger
    int val1 = 100, val2 = 200;
    //presumably should return 200
    int *biggest = larger(&val1, &val2); 

    printf("biggest = %d\n", *biggest);

    //receive array and get meiddle value
    int numbers[6] = {1,2,999,3,4,5};
    int *mid_val = middle_value(numbers, 5);
    printf("Middle value is %d\n", *mid_val);

    //receive an array an get three values
    int first, middle, last, array[10] = {123,23,55,34,89,12,1,7,889,100};
    get_three_vals(array, 10, &first, &middle, &last);

    printf("Start: %d\nMiddle: %d\nLast: %d\n", first, middle, last);

    //sum and average of the array
    int digs[5] = {1,2,3,4,5};
    int sum, avg;
    get_sum_and_avg(digs, 5, &sum, &avg);
    printf("sum = %d, avg = %d\n", sum, avg);


    return 0;
}

void merely_print_value(const int *x)
{
    //merely printing value of x and don't change value of x
    printf("x = %d\n", *x);
}

int* larger(int *x, int *y)
{
    if(*x > *y){
        return x;
    }
    else{
        return y;
    }
}

int* middle_value(int array[], size_t len)
{
    size_t middle_index = len / 2;

    return &array[middle_index];
}

void get_three_vals(int array[], size_t len, int *first, int *mid, int *last)
{
    *first = array[0];
    *mid = array[len/2];
    *last = array[len - 1];
}

void get_sum_and_avg(int array[], size_t len, int *sum_el, int *avg_el)
{
    //computing sum of elements
    for(int i = 0; i < len; ++i){
        *sum_el += array[i];
    }

    //computing average
    *avg_el = *sum_el / len;
}