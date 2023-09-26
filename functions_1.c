/* Объявление и вызов функций  */

#include<stdio.h>

#define USER_NAME   "Andrey"


void say_hi(void)
{
    printf("Hi there, %s !\n", USER_NAME);
}

//объявим ф-ию для вычисления периметра прямоугольника
int get_perimetr(int width, int height)
{
    int perimetr = 2*(width + height);
    return perimetr;
}

int main(void)
{
    say_hi();

    int width = 50, height = 100, result;

    result = get_perimetr(width, height);

    printf("perimetr = %d\n", result);

    return 0;
}