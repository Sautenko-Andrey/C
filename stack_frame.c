/* Стековый фрейм. Автоматические переменные */

#include<stdio.h>


int main(void)
{
    int some_value;
    double fl_val;
    short array[100];
    printf("value = %d\nfl_val = %f\n", some_value,fl_val);
    printf("array[7] = %hu\n", array[7]);

    return 0;
}