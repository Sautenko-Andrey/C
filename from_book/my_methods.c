//my funcs
#include"my_funcs.h"
#include<stdio.h>
#include<stdlib.h>


void printf_row(unsigned number)
{
    for (int i = 0; i < number; ++i){
        printf("%d ", i + 1);
    }
    putchar('\n');
}

void *add_XY(void *x, void *y, char type){
    if (type != 'i' && type != 'f' && type != 'd'){
        fprintf(stderr, "Type Error.\n");
        exit(1);
    }

    
    if (type == 'i'){
        int *res = malloc(sizeof(int));
        *res = *(int*)x + *(int*)y;
        return res;
    }
    else if (type == 'f') {
        float *res = malloc(sizeof(float));
        *res = *(float*)x + *(float*)y;
        return res;
    }
    else {
        double *res = malloc(sizeof(double));
        *res = *(double*)x + *(double*)y;
        return res;
    }
}