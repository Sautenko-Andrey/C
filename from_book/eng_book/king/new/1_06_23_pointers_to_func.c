//Pointer to functions

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//в качестве первого аргумента функция принимает указатель на функцию
//которая возвращает тип double и у которой свой собственный аргумент типа double
double integrate( double (*ptr_func)(double), double x, double y );

//к примеру у нас есть группа функций
double sum( double x, double y );
double sub( double x, double y );
double mul( double x, double y );
double dev( double x, double y );

//калькулятор
double calc( double (*ptr_compute)(double, double) , double x, double y);

//pointer on some function
double (*func)(double, double);

//различные варианты сравнения элементов для последующей сортировки
int cmp_int(const void *x, const void *y);
int cmp_str(const void *str1, const void *str2);

void sort_array(void *array, int nums, size_t size_el, int (*compare)(const void *x, const void *y));



int main(void)
{   
    double a = 100.0, b = 5.0;
    double res = calc(mul, a, b); 
    printf("res = %.2f\n", res);     //res = 500.00

    printf("res = %.2f\n", sub(a,b));
    printf("res = %.2f\n", sum(a,b));
    printf("res = %.2f\n", dev(a,b));


    //
    func = sum;
    double res2 = func(10.00, 50.00);
    printf("res2 = %.2f\n", res2);


    //variable that can store a pointer to function
    double (*math_func)(double, double);

    math_func = mul;
    double res3 = math_func(5.0, 6.0);
    printf("res3 = %.2f\n", res3);

    char *str_array[5] = {"Kate","Ann","Max","Jules","El"};
    sort_array(str_array, 5, sizeof(*str_array), cmp_str);
    
  
    return 0;
}

double integrate( double (*ptr_func)(double), double x, double y )
{

}

double sum( double x, double y )
{
    return x + y;
}

double sub( double x, double y )
{
    return x - y;
}

double mul( double x, double y )
{
    return x * y;
}

double dev( double x, double y )
{
    return x / y;
}

double calc( double (*ptr_compute)(double, double), double x, double y )
{
    return ptr_compute(x, y);
}

int cmp_int(const void *x, const void *y)
{
    return *(int*)x - *(int*)x;
}

int cmp_str(const void *str1, const void *str2)
{
    return ( strcmp( (char*)str1, (char*)str2 ) );
}

void sort_array(void *array, int nums, size_t size_el, int (*compare)(const void *x, const void *y))
{
    qsort(array, nums, size_el, compare );
}