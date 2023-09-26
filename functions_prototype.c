/*Прототипы функций*/

#include<stdio.h>
#include "scripts.h"

//функция, вычисляющая периметр прямоугольника
double perim_pr(double height, double width)
{
    if(height < 0 || width < 0){
        return 0;     //периметр равен 0
    }

    return 2*(height+width);
}

//так же программу можем оформить иначе
//запишем заголовок ф-ии
//double get_sqare(double height, double width);

int main(void)
{
    printf("perimetr = %.2f\n", perim_pr(25.0, 17.5));
    
    printf("sqaure = %.2f\n", get_sqare(10.0, 5.0));

    (get_even(50) == 0)?puts("even") : puts("odd");

    return 0;
}