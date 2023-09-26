/*tasks from book */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define LEN 10

void display_int_array(int array[], size_t len_array);
int sum_arrays(int first_arr[], int second_arr[], size_t length);
int modern_sum_array(int first_arr[], size_t len_first_arr, int sec_arr[], size_t len_sec_arr);
int* add_arrays(int first_arr[], int sec_arr[], size_t length);

int main(void)
{   
    // first task
    char symbol;
    char *ptr_symbol = &symbol;

    //second task
    int cost;
    int *ptr_cost = &cost;

    //third task
    cost = 100;
    printf("%d\n", cost);
    *ptr_cost = 200;
    printf("%d\n", cost);

    //fourth task
    int data[10] = {0};
    data[2] = 100;

    display_int_array(data, sizeof(data) / sizeof(*data));

    int *ptr_data = data;
    *(ptr_data + 2) = 125;


    display_int_array(data, sizeof(data) / sizeof(*data));

    int digs[LEN] = {1,2,3,4,5,6,7,8,9,10};
    int values[LEN] = {1,2,3,4,5,6,7,8,9,10};

    int total_sum = sum_arrays(digs, values, LEN);
    printf("Sum = %d\n", total_sum);


    //let's try modern_sum_array()
    int first[4] = {1,1,1,1};
    int sec[5] = {1,1,1};
    int sum_ar = modern_sum_array(first,4,sec,3);
    printf("Sum arrays = %d\n", sum_ar);



    //let's try add_arrays()
    int val_1[3] = {1,2,3};
    int val_2[3] = {1,2,3};

    int *new_array = add_arrays(val_1, val_2, 3); 
    display_int_array(new_array, 3);

    //let's try show_dot()
    show_dot();

    return 0;
}

void display_int_array(int array[], size_t len_array)
{
    for(int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int sum_arrays(int first_arr[], int second_arr[], size_t length)
{   
    int sum = 0;

    for(int i = 0; i < length; ++i){
        sum += (first_arr[i] + second_arr[i]);
    }

    return sum;
}

int modern_sum_array(int first_arr[], size_t len_first_arr, int sec_arr[], size_t len_sec_arr)
{
    int sum = 0;

    size_t overall_len;

    if(len_first_arr != len_sec_arr){
        (len_first_arr > len_sec_arr) ? (overall_len = len_first_arr) : (overall_len = len_sec_arr);
    }

    int *ptr = malloc(sizeof(int) * overall_len);

    for(int i = 0; i < overall_len; ++i){
        *(ptr + i) = 0;
    }

    if(len_first_arr > len_sec_arr){
        for(int i = 0; i < len_sec_arr; ++i){
            *(ptr + i) = sec_arr[i];
        }

        //compitng sum
        for (int i = 0; i < overall_len; ++i){
            sum += (first_arr[i] + *(ptr + i));
        }
    }
    else if(len_first_arr < len_sec_arr){
        for(int i = 0; i < len_first_arr; ++i){
            *(ptr + i) = first_arr[i];
        }

        //computing sum
        for(int i = 0; i < overall_len; ++i){
            sum += (sec_arr[i] + *(ptr + i));
        }
    }
    else{
        for(int i = 0; i < len_first_arr; ++i){
            sum += (first_arr[i] + sec_arr[i]);
        }
    }

    free(ptr);

    return sum;
}

int* add_arrays(int first_arr[], int sec_arr[], size_t length)
{   
    int *ptr = malloc(sizeof(int) * length);

    for(int i = 0; i < length; ++i){
        *(ptr + i) = (first_arr[i] + sec_arr[i]);
    }

    return ptr;
}
