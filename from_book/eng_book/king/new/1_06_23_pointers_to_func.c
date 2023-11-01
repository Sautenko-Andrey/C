//Pointer to functions

#include<stdio.h>
#include<stdlib.h>

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



int main(void)
{   
    double a = 100.0, b = 5.0;
    double res = calc(mul, a, b); 
    printf("res = %.2f\n", res);     //res = 500.00

    printf("res = %.2f\n", sub(a,b));
    printf("res = %.2f\n", sum(a,b));
    printf("res = %.2f\n", dev(a,b));
  
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