#include"popular_input_func.h"
#include<stdio.h>
#include<stdlib.h>


void fill_array(void *ptr_arr, size_t size, char type)
{   
    void *buffer;

    if (type != 'c' && type != 's' && type != 'i' && type != 'f' && type != 'd' && type != 'l'){
        fprintf(stderr, "Type error.\nUse keys such as: c,s,i,f,d,l\n");
        exit(1);
    }

    if ( type == 's' ){
        for (int i = 0; i < size; ++i){
            printf("Enter a %d dig: ", i + 1);
            scanf("%hd", ((short*)ptr_arr + i));
        }
    }
    else {
        puts("To be continued...");
    }

}