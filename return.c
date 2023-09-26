/*Оператор return. Вызов функций в аргументах*/

#include<stdio.h>
#include<math.h>


double get_kub(double number)
//ф-я, вычисляющая куб
{
    if(number < 0){
        return NAN;
    }
    return number*number*number;
}

void show_even_only(int value)
{
    if (value % 2 != 0 ){
        return;  //завершает работу ф-ии
    }
    printf("%d - is even!\n", value);
}

double minimum_value_2(double first_value, double second_value)
//ф-я, возвращающая минимальное из двух значений
{
    return (first_value < second_value) ? first_value : second_value;
}

double minimum_value_3(double first, double second, double third)
{
    double min_first_second = minimum_value_2(first, second);
    return (min_first_second < third)?min_first_second:third;
}

int main(void)
{
    printf("result = %.2f\n", get_kub(16));
    
    show_even_only(330);

    int x = 15, y = 20, z = 35;

    double result;
    result = minimum_value_3(x,y,z);
    printf("Minimum = %.2f\n", result);

    double res = minimum_value_3(minimum_value_2(x,y),y,z);
    printf("res = %.2f\n", res);


    return 0;
}