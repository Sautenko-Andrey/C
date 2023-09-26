#include<stdlib.h>
#include<stdio.h>

#define NEXT putchar('\n');


void printf_arr(void *ptr_arr, size_t size, char type)
{
    if (type != 'i' && type != 'f'){
        fprintf(stderr, "Innapropriate type!\n");
        exit(1);
    }

    if (type == 'i'){
        for (int i = 0; i < size; ++i){
            printf("%d ", *((int*)ptr_arr + i));
        }
    }
    else{
        for (int i = 0; i < size; ++i){
            printf("%f ", *((float*)ptr_arr +i));
        }
    }
    NEXT;
}