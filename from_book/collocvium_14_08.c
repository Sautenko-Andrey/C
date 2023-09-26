//решение задач к теме "Дополнительные озможности функций"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

#define LEN_STR 50
#define ARR_LEN 10

/*Напишите функцию, которая: а) принимает переменное количество строк в качестве
аргументов; б) сцепляет строки по порядку в одну длинную строку; в) возвращает указа—
тель на новую строку в основную программу.*/
char* str_concat(int num, ...);

/*Напишите функцию, которая: а) принимает массив чисел любого типа в качестве аргумен-
та; б) находит наименьшее и наибольшее число в массиве; в) возвращает указатели на эти
числа в основную программу. (Подсказка: нужно найти способ сообщить функции коли—
чество элементов в массиве.)*/
void* array_ops(void *array, size_t len_array, char type);

/*Напишите функцию, которая принимает в качестве аргументов строку и символ. Функция
должна найти первое появление символа в строке и возвратить указатель на его местона-
хождение.*/
char* find_symbol(char *text, char symbol);


int main(void)
{   
    //первая задача
    char *new_str = str_concat(3, "I love C!", "Arsenal is a champion!", "Stop war!");
    puts(new_str);
    free(new_str);

    //третья задача
    char *symb = find_symbol("Bear in mind!", 'e');
    printf("symb = %c, adress : %p\n", *symb, symb);

    //вторая задача
    int arr[ARR_LEN] = {5,6,4,7,3,8,2,9,1,10};
    int *ptr_arr = arr;
    void *ptr = array_ops(ptr_arr, ARR_LEN, 'i');

    

    return 0;
}

//ф-я для первой задачи
char* str_concat(int num, ...)
{
    // allocate memory for final string
    char *final_str = malloc((sizeof(char) * LEN_STR) * num);
    if ( final_str == NULL ){
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    //declare pointer on args
    va_list ptr_args;

    //initialize pointer
    va_start(ptr_args, num);
    
    //get attributes from list and concatenate it
    for ( int i = 0; i < num; ++i ){
        strcat(final_str, va_arg(ptr_args, char*));
    }

    va_end(ptr_args);

    return final_str;
}

//ф-я для второй задачи
void* array_ops(void *array, size_t len_array, char type)
{   
    /*printf("first: %d\n", *(int *)array);
    printf("second: %d\n", (*(int *)array) + 1);
    printf("third: %d\n", (*(int *)array) + 2);*/
    putchar('\n');
    int temp_array[len_array];
    for(int i = 0; i < len_array; ++i){
        //printf("#%d\t%d\n", i + 1, (*(int *)array)++);
        temp_array[i] = (*(int *)array)++;
    }

    //посмотрим на временный массив
    printf("temp array: ");
    for(int i = 0; i < len_array; ++i){
        printf("%d ", temp_array[i]);
    }
    putchar('\n');

   /* size_t min_index;
    for(int i = 0; i < len_array - 1; ++i){
        min_index = i;

        for(int j = i + 1; j < len_array; ++j){
            if(temp_array[min_index] > temp_array[j]){
                min_index = j;
            }
        }

        if(min_index!=i){
                int temp = temp_array[i];
                temp_array[i] = temp_array[min_index];
                temp_array[min_index] = temp;
            }
    }

    //минимальное число
    int min_value = temp_array[0];
    //максимальное число
    int max_value = temp_array[len_array - 1];

    printf("Min = %d, Max = %d\n", min_value, max_value);*/
    
    return array;
}

//ф-я для 3-й задачи
char* find_symbol(char *text, char symbol)
{
    return strchr(text, symbol);
}