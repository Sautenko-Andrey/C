//СОВЕРШЕНСТВОВАНИЕ ОРГАНИЗАЦИИ ПРОГРАММ

//ПРОГРАММЫ СОСТОЯЩИЕ ИЗ НЕСКОЛЬКИХ МОДУЛЕЙ ИСХОДНОГО КОДА

#include<stdio.h>
#include"my_funcs.h"

int main(void)
{   
    //воспользуемся ф-ей printf_row()
    printf_row(10);

    //воспользуемся ф-ей add_XY()
    float x = 10, y = 18;
    float *res = add_XY(&x, &y, 'f');
    printf("res = %.1f\n", *res);
    puts("----------");

    return 0;
}