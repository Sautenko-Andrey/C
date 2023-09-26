//НЕКОТОРЫЕ ИНТЕРЕСНЫЕ МОМЕНТЫ РАБОТЫ С ФУНКИЦЯМИ
#include<stdio.h>
#include<stdlib.h>
#include"common.h"

/*ф-я принимает в качестве пргумента массив и его длину
и мы делаем так, чтобы эта указанная длина соответстовала реальной длине массива*/
void display_arr(size_t length, int array[length]);

void sort_arr_here(size_t len, int array[len]);
int matrix_sum(unsigned rows, unsigned cols, int matrix[rows][cols]);
int mul_arr_elem(size_t len, const int array[len]);

void display_positive_nums(size_t len, int array[len]);
int display_negative(size_t len, int array[len]);

void* create_cust_array(size_t length, char type);

int main(void)
{   
    //let's call display_arr
    int my_arr[10] = {1,2,3,4,5};
    int num = 5;
    display_arr(num, my_arr);

    //let's sort array
    int numbers[] = {54, 2, -34, 0, 11, -2, 100};
    printf_arr(numbers, 7, 'i');

    sort_arr_here(7, numbers);
    printf_arr(numbers, 7, 'i');

    //using matrix_sum
    int data[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int res = matrix_sum(3,4,data);
    printf("matrix sum = %d\n", res);


    //ALSO WE CAN BUILD ARRAYS ON THE FLY AND EXPLOUT IT IN FUNCTIONS
    sort_arr_here(5, (int[]){1,2,3,4,5});  //using explisit conversion to type int[]


    //using mul_arr_elem
    const int digits[] = {1,2,3,4,5};
    int x = digits[0] + digits[1];
    printf("x = %d\n", x);
    int res_mul = mul_arr_elem(5, digits);
    printf("res_mul = %d\n", res_mul);

    //other way
    int res_mul2 = mul_arr_elem(5,(const int[]){-3, 100, 2, 14, 7});
    printf("res_mul2 = %d\n", res_mul2);


    //using display_positive_nums
    int pos_nums[] = {1,13,15,11,100};
    int mix_nums[] = {100, 2, -51, 99};

    display_positive_nums(5, pos_nums);
    display_positive_nums(4, mix_nums);


    //let's create a custom array
    size_t custom_len = 5;
    int *my_custom_arr = create_cust_array(custom_len,'i');
    printf_arr(my_custom_arr, custom_len, 'i');
    



    return 0;
}

void display_arr(size_t length, int array[length])
{
    for (int i = 0; i < length; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void sort_arr_here(size_t len, int array[len])
{
    size_t min_index;

    for (int i = 0; i < len -1; ++i){
        min_index = i;

        for(int j = i + 1; j < len; ++j){
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

int matrix_sum(unsigned rows, unsigned cols, int matrix[rows][cols])
{   
    int total_sum = 0;

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            total_sum += matrix[i][j];
        }
    }

    return total_sum;
}

int mul_arr_elem(size_t len, const int array[len])
{
    int total_mul = 1;
    for (int i = 0; i < len; ++i){
        total_mul *= array[i];
    }

    printf("mul = %d\n", total_mul);

    return total_mul;
}

void display_positive_nums(size_t len, int array[len])
{
    for (int i = 0; i < len; ++i){
        if (array[i] < 0){
            putchar('\n');
            return;   //сразу выходит из цикла и возвращает управление main
        }
        printf("%d ", array[i]);
    }
}

int display_negative(size_t len, int array[len])
{   
    int counter = 0;

    for(int i = 0; i < len; ++i){

        ++counter;

        if (array[i] > 0){
            //return;                  error appears
            return 0;
        }
        printf("%d ", array[i]);
    }
    putchar('\n');

    return counter;
}

void* create_cust_array(size_t length, char type)
{
    if (type != 'i'){
        puts("Only int is correct.");
        exit(EXIT_FAILURE);
    }
    
    int *array = malloc(sizeof(int) * length);
    if(array == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; ++i){
        printf("Enter %d value: ", i + 1);
        scanf("%d", array + i);
    }

    return array;
}