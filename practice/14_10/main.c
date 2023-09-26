#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{   
    char *ptr = malloc(sizeof(char));

    *ptr = 'A';

    printf("ptr = %c\n", *ptr);

    free(ptr);

    int cout_int = 4;

    int *array_int = malloc(cout_int * sizeof(int));

    //помещаем 4 числа типа int в выделенный массив в куче
    for (int i = 0; i < cout_int; ++i){
        array_int[i] = 100;
    }
    //печатаем результат
    printf("New dynamic array: ");
    for (int i = 0; i < cout_int; ++i){
        printf("%d ", array_int[i]);
    }
    puts("");

    free(array_int);

    //char *ptr_text = malloc(10 * sizeof(char));

    //puts("Enter nameL: ");
   // fgets(ptr_text, sizeof(ptr_text), stdin);
    //printf("%s\n", ptr_text);
    //free(ptr_text);
    //char name[] = "Andrey";

    //strcpy(ptr_text, name);

    //printf("%s\n",ptr_text);

    return 0;
}