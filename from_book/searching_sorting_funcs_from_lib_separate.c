//ПОТРЕНЕРУЕМСЯ С БИБЛИОТЕЧНЫМИ ФУНКЦИЯМИ СОРТИРОВКИ И ПОИСКА

#include<stdio.h>
#include<stdlib.h>

#define LEN 10

void sort_lib(int array[], size_t len_array);
void printf_arr(int array[], size_t len_array);
int int_cmp(const void *val_1, const void *val_2);
int * search_int(int array[], size_t len, int key);

int main(void)
{   
    //остортируем массив чисел типа int
    int my_array[LEN] = {7,8,6,9,4,2,3,1,10,5};

    sort_lib(my_array, LEN);

    //найдем число в массиве
    int searched_int = 3;

    int *pos = search_int(my_array, LEN, searched_int);

    return 0;
}

void sort_lib(int array[], size_t len_array)
{
    //распечатаем массив
    printf_arr(array, len_array);

    //отсортируем его
    qsort(array, LEN, sizeof(*array), int_cmp);

    //посмортим на отсортированный массив
    printf_arr(array, len_array);   
}

void printf_arr(int array[], size_t len_array)
{
    for (int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int int_cmp(const void *val_1, const void *val_2)
{
    return ( *(int *)val_1 - *(int *)val_2 );
}

int * search_int(int array[], size_t len, int key)
{
    //начинаем поиск в отсортированном массиве
    //определим указатель, который будет возвращать позицию искомого числа
    int *ptr;

    ptr = (int*)bsearch(&key, array, len, sizeof(*array), int_cmp);

    //проверка
    if (ptr == NULL){
        printf("I didn't find number %d.\n", key);
    }
    else {
        printf("Searched %d is in position %ld.\n", key, ptr - array);
    }
    //printf("%p\n", ptr);
    return ptr;
}