//ПРАКТИКА С ПОИСКОМ И СОРТИРОВКОЙ ИСПОЛЬЗУЯ БИБЛИОТЕЧНЫЕ ФУНКЦИИ qsort() bsearch()

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 6

#define CONT_MAX 5

struct phone_book {
    char *name;
    char *phone;
};

typedef struct phone_book phone_book;

void sort_by_alphabet(char array[], size_t length);  //собственная сортировка
void printf_chr(char array[], size_t length);

//отсортируем цены типа float
int float_cmp(const void *f1, const void *f2);
void float_sort(float array[], size_t len_array);


//сортировка телефонной книги (структуры)
void phone_book_sort(phone_book array[], size_t count_contacts);
int name_cmp(const void *name1, const void *name2);


int main(void)
{
    /*Сделаем так, чтобы буквы были упорядочены по алфавиту*/
    char symbols[MAX] = {
        'c', 'b', 'a', 'd', 'f', 'e'
    };

    //распечатаем символы массива
    printf_chr(symbols, MAX);

    //остортируем массив символов по алфавиту
    sort_by_alphabet(symbols, MAX);

    //распечатаем символы массива
    printf_chr(symbols, MAX);


    //теперь поиграемся с библиотечными функциями сортировки и поиска
    float prices[MAX] = {45.50, 122.99, 75.80, 99.99, 10.10, 0.99};

    for(int i = 0; i < sizeof(prices) / sizeof(*prices); ++i){
        printf("%.3f ", prices[i]);
    }
    putchar('\n');

    float_sort(prices, MAX);

    for(int i = 0; i < sizeof(prices) / sizeof(*prices); ++i){
        printf("%.2f ", prices[i]);
    }
    putchar('\n');

    //отсортируем телефонную книгу
    //заведем сначла ее
    phone_book contacts[CONT_MAX] = {
    {"Segei Jarchinckiy", "+380999632147"},
    {"Anna Chausova", "+80951324569"},
    {"Maxim Serobaba", "+80501236547"},
    {"Leonid Budyak", "+30631477412"},
    {"Alexiy Nazdrachov", "+80679854136"}
    };

    phone_book_sort(contacts, CONT_MAX);


    return 0;
}

void printf_chr(char array[], size_t length)
{
    for (int i = 0; i < length; ++i){
        printf("%c ", array[i]);
    }
    putchar('\n');
}

void sort_by_alphabet(char array[], size_t length)
{
    //сортировка
    size_t min_index;

    for (int i = 0; i < length - 1; ++i){
        min_index = i;
        for (int j = i + 1; j < length; ++j){
            if ( array[min_index] > array[j] ){
                min_index = j;
            }
        }

        if(min_index != i){
            char temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int float_cmp(const void *f1, const void *f2)
{
    return ( *(float*)f1 - *(float*)f2 );
}

void float_sort(float array[], size_t len_array)
{
    qsort(array, MAX, sizeof(*array), float_cmp);
}

int name_cmp(const void *name1, const void *name2)
{
    return ( strcmp( (char*)name1, (char*)name2 ) );
}

void phone_book_sort(phone_book array[], size_t count_contacts)
{
    //распечатаем начальное состояние телефонной книги
    puts("__________________________________");
    for ( int i = 0; i < count_contacts; ++i ){
        printf("\nName: %s\nTel: %s\n_______________________\n", array[i].name, array[i].phone);
    }

    //отсортируем по именам
    qsort(array,CONT_MAX, sizeof(*array), name_cmp);

    //распечатаем отсортированную книгу
    printf("\n\n\n");
    puts("After sorting:");
    puts("__________________________________");
    for ( int i = 0; i < count_contacts; ++i ){
        printf("\nName: %s\nTel: %s\n_______________________\n", array[i].name, array[i].phone);
    }

}