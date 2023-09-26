//СОРТИРОВКА И ПОИСК СТРОК

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define COL 5

void sort_str(char *strings[], size_t len);
void printf_str(char *strings[], size_t len);
int comp(const void *str1, const void *str2);
char* search_string(char *strings[], size_t len, char *key_str);


int main(void)
{   
    //определим массив строк
    char *my_friends[COL] = {
        "Alex Tereshyk",
        "Danil Makogon",
        "Yuriy Bayborodin",
        "Rodion Jila",
        "Alex Chausov"
    };

    //остсортируем строки
    sort_str(my_friends, COL);

    //ищем строку
    char *ptr = search_string(my_friends, COL, "Alex Chausov");


    return 0;
}

void printf_str(char *strings[], size_t len)
{
    for (int i = 0; i < len; ++i){
        printf("#%d\t%s\n", i + 1, strings[i]);
    }
    putchar('\n');
}

int comp(const void *str1, const void *str2)
{
    return ( strcmp(*(char **)str1, *(char**)str2) );
}

void sort_str(char *strings[], size_t len)
{
    //распечатаем полученные строки
    printf_str(strings, len);

    //отсортируем их по возрастанию
    qsort(strings, len, sizeof(*strings),comp);

    //распечатаем результат
    printf_str(strings, len);
}

char* search_string(char *strings[], size_t len, char *key_str)
{
    char *ptr;
    char **key1;
    key1 = &key_str;

    ptr = bsearch(key1, strings, len, sizeof(*strings), comp);

    if(ptr == NULL){
        printf("String <%s> was not found.\n", key_str);
    }
    else {
        printf("String <%s> was found.\n", key_str);
    }

    return ptr;
}