#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"popular_func.h"


void printf_array(void *ptr_array, char type, size_t size)
{
    if (type != 'i' && type != 'f' && type != 'c' && type != 'd' && type != 's' && type != 'l'){
        fprintf(stderr, "Type error.\nUse keys such as: c, s, i, f, d, l .\n");
        exit(1);
    }

    //variations
    if (type == 'i'){
        for(int i = 0; i < size; ++i){
            printf("%d ", *((int*)ptr_array + i));
        }
        putchar('\n');
    }
    else if(type == 'f'){
        for(int i = 0; i < size; ++i){
            printf("%.2f ", *((float*)ptr_array + i));
        }
        putchar('\n');
    }
    else if(type == 'c'){
        for(int i = 0; i < size; ++i){
            printf("%c ", *((char*)ptr_array + i));
        }
        putchar('\n');
    }
    else if(type == 'd'){
        for(int i = 0; i < size; ++i){
            printf("%f ", *((double*)ptr_array + i));
        }
        putchar('\n');
    }
    else if(type == 's'){
        for(int i = 0; i < size; ++i){
            printf("%u ", *((short*)ptr_array + i));
        }
        putchar('\n');
    }
    else{
        for(int i = 0; i < size; ++i){
            printf("%Lf ", *((long double*)ptr_array + i));
        }
        putchar('\n');
    }   
}

void memory_allocation_check(void *pointer)
{
    if ( pointer == NULL ){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
}