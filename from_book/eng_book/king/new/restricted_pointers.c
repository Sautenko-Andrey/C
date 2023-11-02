//Restricted pointers

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{   
    int *restrict ptr;
    int *restrict ptr2;

    ptr = malloc(sizeof(int));

    ptr2 = ptr;

    //*ptr2 = 100;  //causes undefined behavior 
    /* Мы говорим компилятору, что на эту область памяти указыает только один указатель
    при этом вся ответственность падает на нас */

    int array[5] = {1,2,3,4,5};
    memmove(&array[0], &array[1], sizeof(int));

    memmove(&array[4], &array[3], sizeof(int));

    for (int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    putchar('\n');




    return 0;
}