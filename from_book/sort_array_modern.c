//Сортировка  массива в обе стороны

#include<stdio.h>

#define MAX 10

//прототипы функций
void simple_sort(int array[], size_t len_array, int sort_type);
void print_arr(int array[], size_t len_array);
int def_type(void);
int compare_forward(int x, int y);
int compare_reverse(int x, int y);

int main(void)
{   
    //объявим массив
    int digs[MAX] = {5, 3, 1, 6, 2, 7, 9, 4, 8, 10};

    //распечатываем
    print_arr(digs, MAX);

    //выберем метод сортировки
    int sort_type = def_type();


    simple_sort(digs, MAX, sort_type);

    //печатаем результат
    print_arr(digs, MAX);

    return 0;
}

void print_arr(int array[], size_t len_array)
{
    for (int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int straight_sort(int array[], int min_index,int j)
{
    return (array[min_index] > array[j]);
}
int reverse_sort(int array[], int min_index,int j)
{
    return (array[min_index] < array[j]);
}

int def_type(void)
{   
    int type;
    printf("Enter 0 to straight sort and 1 for reverse sort: ");
    scanf("%d", &type);

    return type;
}

void simple_sort(int array[], size_t len_array, int sort_type)
{   
    //объявляем указатель на вариант сравнения для сортировки
    int (*compare)(int x, int y);

    compare = (sort_type) ? compare_forward :compare_reverse;

    int min_index;

    for (int i = 0; i < len_array - 1; ++i){
        min_index = i;

        for (int j = i + 1; j < len_array; ++j){
            //if(array[min_index] > array[j]){
            if(compare(array[min_index], array[j])){    
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

int compare_forward(int x, int y)
{
    return (x > y);
}
int compare_reverse(int x, int y)
{
    return (x < y);
}