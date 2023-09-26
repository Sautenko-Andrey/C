//ОБРАБОТКА ОШИБОК
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<stdarg.h>
#include<errno.h>
#include<float.h>

#define MAX_SHORT 32767

//#define NDEBUG

//использование assert() для диагностики ошибок
void* sqrt_val(void *value, char type);
double* utiliti_bills(int num, ...);

//использование perror() и errno для диагностики ошибок
void simple_func(char *file_name);
int* month_payroll(int num, ...);


int main(void)
{
    //макрос assert() - для диагностики ошибок в программе
    //запускать программу нужно в режиме отладки!

    double x = 1000.50;
    double *result = sqrt_val(&x, 'd');
    printf("result = %.4lf\n", *result);
    printf("Execution time: 0.%ld s\n", clock());


    //еще один пример диагностики
    //double *total_payroll = utiliti_bills(3, 100, 200, 300);
    //printf("Payroll : %.2lf usd\n", *total_payroll);
    //printf("Time: 0.%ld s\n", clock());

    //free(result);
    //free(total_payroll);

    //ЗАГОЛОВОЧНЫЙ ФАЙЛ errno.h - можедержит несколько макросов для выявления
    //и документирования ошибок в программе + использование ф-ии perror()
    char file_name[] = "data_Andrey.txt";
    simple_func(file_name);

    //еще пример
    int *payroll = month_payroll(3, 2147483647, 200, 300);
    printf("For last month you should pay : %d $\n", *payroll);
    free(payroll);


    return 0;
}

void* sqrt_val(void *value, char type)
{   
    //проверям корректность типа
    if (type != 'i' && type != 'd'){
        fprintf(stderr, "Type Error!\n");
        exit(1);
    }

    if ( type == 'i' ){
        //значение value не должно быть отрицательным
        //проводим диагностику
        assert(*(int *)value > 0);

        //выделяем память
        int *res = malloc(sizeof(int));

        //вычисляем квадрат
        *res = *(int *)value * *(int *)value;

        return res;
    }
    else {
        assert( *(double *)value > 0 );

        double *res = malloc(sizeof(double));

        *res = *(double *)value * *(double *)value;
    }
}

double* utiliti_bills(int num, ...)
{
    va_list ptr_args;
    double *total = malloc(sizeof(double));
    *total = 0.0;

    va_start(ptr_args, num);

    for (int i = 0; i < num; ++i){
        *total += va_arg(ptr_args, double);

        if ( *total > MAX_SHORT ){
            perror("Error");
            printf("errno = %d.\n", errno);
        }
    }

    assert(*total > 1);

    va_end(ptr_args);

    return total;
}

void simple_func(char *file_name)
{   
    //объявляем указатель на файл
    FILE *file_ptr;

    //открываем файл
    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        perror("Error");
        printf("errno = %d.\n", errno);
        if ( errno == 2 ){
            puts("Please check file name!");
        }
        exit(1);
    }
    else {
        printf("File opened for reading!\n");
        fclose(file_ptr);
    }
}

int* month_payroll(int num, ...)
{
    
    int *total = malloc(sizeof(int));
    *total = 0;
    if ( total == NULL ){
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    va_list ptr_args;

    va_start(ptr_args, num);

    for (int i = 0; i < num; ++i){
        *total += va_arg(ptr_args, int);
    }

    if ( *total > __INT_MAX__ ){
            perror("Error");
            printf("errno = %d\n", errno);
        }

    va_end(ptr_args);
    printf("MAX = %d\n", __INT_MAX__);

    return total;
}