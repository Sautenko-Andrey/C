//Практика сортировки массивов чисел и строк

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 10

void sort_int_array(int array[], size_t len_array, char type_sort);
int forward_compare(int x, int y);
int reverse_compare(int x, int y);
void print_array(int array[], size_t len_array);
void print_str(char *strings[], size_t num);

//for strings
void sort_str(char *strings[], size_t amount, char type_sort);
int forward(char *x, char *y);
int reverse(char *x, char *y);


int main(void)
{   
    //declearing and assigning array of int
    int numbers[MAX_LEN] = {9,1,8,2,7,3,6,4,5,10};

    //printing array of int
    print_array(numbers, MAX_LEN);

    //sorting this array
    sort_int_array(numbers, MAX_LEN, 1);

    //printing sorted array
    print_array(numbers, MAX_LEN);

    //declearing array of pointers on strings
    char *names[MAX_LEN] = {
        "Andrey",
        "Danil",
        "Alex",
        "Kate",
        "Chaus",
        "Sergei",
        "Yuriy",
        "Ann",
        "Denis",
        "Max"
    };

    //let's print it
    print_str(names, MAX_LEN);
    puts("----------------------------");
    //let's sort it
    sort_str(names, MAX_LEN, 1);

    //let's display sorted array of pointers on strings
    print_str(names, MAX_LEN);

    return 0;
}

void sort_int_array(int array[], size_t len_array, char type_sort)
{   
    
    //проверка длині массива
    if(len_array < 0){
        puts("Lenght of array can't be less then 0.");
        exit(-1);
    }
    else if (len_array == 1){
        exit(0);
    }

    //создаем указатель на функцию сравнения
    int (*compare)(int x, int y);

    compare = (type_sort) ? forward_compare : reverse_compare;

    //прописіваем сортировку

    int min_index;

    for (int i = 0; i < len_array - 1; ++i){
        min_index = i;

        for (int j = i + 1; j < len_array; ++j){
            if (compare(array[min_index], array[j])){
                min_index = j;
            }
        }

        if (min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int forward_compare(int x, int y)
{
    return (x > y);
}
int reverse_compare(int x, int y)
{
    return (x < y);
}
void print_array(int array[], size_t len_array)
{   
    //проверка длинны массива
    if (len_array < 0){
        puts("Length of array has to be greater then 0.");
        exit(-1);
        }
    

    for (int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }

    putchar('\n');
}

void sort_str(char *strings[], size_t amount, char type_sort)
{   
    int (*compare)(char *x, char *y);

    compare = (type_sort) ? forward : reverse;


    for (int i = 0; i < amount - 1; ++i){
        for (int j = i + 1; j < amount; ++j){
            if(compare(strings[i], strings[j]) > 0){
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int forward(char *x, char *y)
{
    return (strcmp(x,y));
}
int reverse(char *x, char *y)
{
    return (strcmp(y,x));
}

void print_str(char *strings[], size_t num)
{
    for (int i = 0; i < num; ++i){
        printf("%s\n", strings[i]);
    }
}