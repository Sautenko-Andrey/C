//СОРТИРОВКА И ПОИСК qsort() bsearch()

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void sort_n_search(void);
int intcmp(const void *first, const void *sec);
void print_arr(int arr[]);



int main(void)
{   
    sort_n_search();
    
    return 0;
}

void sort_n_search(void)
{
    int array[MAX];
    int key;
    int *ptr;

    //заполняем массив
    for (int i = 0; i < MAX; ++i){
        printf("Enter a dig: ");
        scanf("%d", &array[i]);
    }

    //посмотрим на массив
    print_arr(array);

    puts("Press ENTER to sort the array");
    getc(stdin);

    //сортировка массива по возрастанию
    qsort(array, MAX, sizeof(*array), intcmp );

    //печать отсортированного массива
    print_arr(array);

    printf("Press enterto continue:");
    getc(stdin);

    //Ввод ключа поиска
    printf("Enter a value to search for: ");
    scanf("%d", &key);

    //поиска числа в массиве
    ptr = (int *)bsearch(&key, array, MAX, sizeof(*array), intcmp);

    if (ptr != NULL){
        printf("%d found at array[%ld]\n", key, ptr - array);
    }
    else {
        printf("%d was not found.", key);
    }
}

int intcmp(const void *first, const void *sec)
{
    //вернет либо 0, либо отрицательное значение , либо положительное
    return ( *(int *)first - *(int *)sec );
}

void print_arr(int arr[])
{
    for (int i = 0; i < MAX; ++i){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}