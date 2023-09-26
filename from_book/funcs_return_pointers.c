//ФУНКЦИИ ВОЗВРАЩАЮЩИЕ УКАЗАТЕЛИ

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int* larger(int *x, int *y);

float* mean_sallary(int num, ...);

void* square(void* width, void* length, char type);

void memory_alloctaion_check(void *ptr, char type);


int main(void)
{   
    //сравним два числа
    int x1 = 100, y1 = 150;
    int *res = larger(&x1, &y1);

    printf("Bigger dig is on adress %p or %p\n", res, &y1);

    //посчитаем среднюю зарплату
    float *median = mean_sallary(3, 10000.00, 20000.00, 25000.00);
    printf("adress: %p, value: %.2f\n", median, *median);

    //посчитаем плозадь поля
    float wid = 100.50, len = 352.75;
    float *sq;
    sq = square(&wid, &len, 'f');
    printf("square = %.2f, adress: %p\n", *sq, sq);

    free(median);
    free(sq);

    


    return 0;
}

int* larger(int *x, int *y)
{
    if ( *x >= *y){
        return x;
    }
    else{
        return y;
    }
}

float* mean_sallary(int num, ...)
{
    float sum = 0;
    float *res = malloc(sizeof(float));
    
    va_list ptr_args;

    va_start(ptr_args, num);

    for (int i = 0; i < num; ++i){
        sum += va_arg(ptr_args, double);
    }

    va_end(ptr_args);

    *res = (float)sum / num;

    return res;
}

void* square(void* width, void* length, char type)
{
    if ( type != 'i' && type != 'f' ){
        fprintf(stderr, "Attribute Error!\n");
        exit(1);
    }

    if ( type == 'i' ){
        int *res = malloc(sizeof(int));
        memory_alloctaion_check(res, 'i');
        *res = (*(int*)width * *(int*)length);
        return res;
    }
    else{
        float *res = malloc(sizeof(float));
        memory_alloctaion_check(res, 'f');
        *res = (*(float*)width * *(float*)length);
        return res;
    }

}

void memory_alloctaion_check(void *ptr, char type)
{   
    if ( type != 'i' && type != 'f' ){
        fprintf(stderr, "Argument error!");
        exit(1);
    }

    if ( type == 'i' ){
        if ( (int *)ptr == NULL) {
            fprintf(stderr, "Memory allocation eror!\n");
            exit(1);
        }
    }
    else{
        if ( (float *)ptr == NULL) {
            fprintf(stderr, "Memory allocation eror!\n");
            exit(1);
        }
    }
}