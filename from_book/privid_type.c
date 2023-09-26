#include<stdlib.h>
#include<stdio.h>

void* sumXY(void *x, void *y, char type);


int main(void)
{   
    float x = 10.55, y = 28.078;
    float *res = sumXY(&x, &y, 'f');
    printf("res = %.3f\n", *res);
    free(res);
    
    return 0;
}

void* sumXY(void *x, void *y, char type)
{
    if (type != 'i' && type != 'f'){
        fprintf(stderr, "Type Error.\n");
        exit(1);
    }

    if (type == 'i'){
        int *res = malloc(sizeof(int));
        *res = *(int*)x + *(int*)y;
        return res;
    }
    else {
        float *res = malloc(sizeof(float));
        *res = *(float*)x + *(float*)y;
        return res;
    }
}