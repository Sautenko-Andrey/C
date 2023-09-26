//ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ ФУНКЦИЙ
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define LEN 5

//функция, в которой передается адрес переменной как аргумент
void doubble_value(int *x_ptr);

//функция, которой передается значение переменной как аргумент
void tripple_value(int x);

//ф-я с нетипизированным указателем для обработки любых типов данных
void devide_by2(void *value, char type);

int main(void)
{   
    //ПЕРЕДАЧА УКАЗАТЕЛЕЙ В ФУНКЦИИ
    //объявим целочисленную переменную x
    int x = 100;

    //изменим значение этой переменной
    printf("before func x = %d\n", x); //before func x = 100
    doubble_value(&x);
    printf("after func x = %d\n", x);   //before func x = 100

    int y = 55;
    printf("before y = %d\n",y);   //before func x = 100
    tripple_value(y);
    printf("after y = %d\n", y);    //before func x = 100



    //УКАЗАТЕЛИ ТИПА void
    //void можно использовать для создания нетипизированных указателей
    //передав аргументом такой указатель, мы не привязываем себя к типу данных
    //но нужно будет делать приведение типа, иначе не сработает
    int val_i = 100;
    float val_f = 60.00f;
    double val_d = 110000.50;

    printf("\n\nBefore: %d, %.2f, %.2f\n", val_i, val_f, val_d);

    devide_by2(&val_i, 'i');
    devide_by2(&val_f, 'f');
    devide_by2(&val_d, 'd');

    printf("After: %d, %.2f, %.2f\n", val_i, val_f, val_d);

    //попробуем сделать тоже самое с массивом
    int nums[LEN] = {10, 20, 30, 40 , 50};
    for (int i = 0; i < LEN; ++i){
        devide_by2((nums + i), 'i');
    }

    for(int i = 0; i < LEN; ++i){
        printf("%d ", nums[i]);      //5 10 15 20 25
    }
    putchar('\n');    


    return 0;

}

void doubble_value(int *x_ptr)
{
    *x_ptr *= 2;
}

void tripple_value(int x)
{
    x *= 3;
}

void devide_by2(void *value, char type)
{   
    //приведение типа в зависимости от аргумента type
    switch (type)
    {
    case 'i':
        *((int *)value) /= 2;
        break;
    case 'f':
        *((float *)value) /= 2;
        break;
    case 'd':
        *((double *)value) /= 2;
        break;
    default:
        fprintf(stderr, "Type error!\n");
        break;
    }
}