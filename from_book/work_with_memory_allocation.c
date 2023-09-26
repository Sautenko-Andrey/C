//РАБОТА С ПАМЯТЬЮ.

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int* mem_allocation_calloc(void);
int* mem_allocation_malloc(int num_obj);
char* mem_allocation_realloc(void);
char* cat_str(char *str1, char *str2);

int main(void)
{   

    //РАСПРЕДЕЛЕНИЕ ПАМЯТИ С ПОМЩЬЮ ФУНКЦИИ calloc()
    //mem_allocation_calloc();

    //ТОЖЕ САМОЕ С ПОМОЩЬЮ malloc()
    //mem_allocation_malloc(5);

    //РАБОТА С realloc() - изменяет размер блока, ранее созданного с помощью malloc() или
    //calloc()

    //mem_allocation_realloc();

    char *new_string = cat_str("Arsenal", "London");
    puts(new_string);
    free(new_string);

    return 0;
}

int* mem_allocation_calloc(void)
{   
    long amount_obj;
    int *ptr;

    printf("Введи количество объектов int для выделения памяти под них:");
    scanf("%ld", &amount_obj);

    //выделяем память
    ptr = calloc(amount_obj, sizeof(int));

    if ( ptr == NULL ){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    else{
        puts("Memory has been allocated.");
    }

    //посмотрим что за значения у выделенной памяти
    for(int i = 0; i < amount_obj; ++i){
        printf("%d\n", *(ptr + i));   //вернет нули в ячейках размером int
    }

    return ptr;
}

int* mem_allocation_malloc(int num_obj)
{
    int *ptr;
    ptr = malloc(sizeof(int) * num_obj);
    if (ptr == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    else{
        puts("Memory has been allocated.");
    }

    //let's look on values in ptr
    for (int i = 0; i < num_obj; ++i){
        printf("%d\n", *(ptr + i));
    }

    return ptr;
}

char* mem_allocation_realloc(void)
{   
    char buffer[11];
    char message[] = "123";

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    //memeory allocation
    char *ptr = malloc(sizeof(char)* 11);
    if (ptr == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    //copying buffer in ptr
    strcpy(ptr, buffer);

    //extending ptr
    ptr = realloc(ptr, strlen(buffer) + strlen(message));
    if (ptr == NULL){
        fprintf(stderr, "Memory was not extended.\n");
    }

    strcat(ptr, message);

    puts(ptr);

    return ptr;
}

char* cat_str(char *str1, char *str2)
{       
    char separate_symb[] = " ";
    char end_of_sent[] = " is my favourite team!";

    char *two_str = malloc(sizeof(char) * (strlen(str1) + strlen(str2)) + 2);

    strcpy(two_str, str1);
    strcat(two_str, separate_symb);
    strcat(two_str, str2);

    //puts(two_str);

    two_str = realloc(two_str, strlen(str1) + strlen(str2) + strlen(two_str) + 1);
    if (two_str == NULL){
        fprintf(stderr, "Memory was not extended.\n");
    }

    strcat(two_str, end_of_sent);
    //puts(two_str);

    return two_str;
}