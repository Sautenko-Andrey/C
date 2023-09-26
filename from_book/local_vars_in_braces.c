//Локальные переменные в блоках
#include<stdio.h>

int main(void)
{   
    //объявим обычную локальную переменную
    int value = 100;

    //объявим локальную переменную в блоке
    {
        int value = 200;
    }

    //распечатаем перемнную regular
    printf("regular should be 100, we've got %d\n", value); //regular should be 100, we've got 100

    {
        char *text = "Local variable in block";
        puts(text);
    }

    //let's try to display text
    //puts(text);  //errro!


    return 0;
}