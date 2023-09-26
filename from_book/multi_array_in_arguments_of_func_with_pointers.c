//Передача многомерного массива в функцию через указатель
#include<stdio.h>

void print_array(int(*ptr)[4], int n);
void show_prices(float(*ptr)[9], int items);
void show_num(int (*ptr)[3], int col);


int main(void)
{   
    //объявим многомерный массив
    int multi[3][4] = {
        {11,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    //указатель на массив из четырех чисел типа int
    int (*ptr)[4];
    //объявим указатель на этот многомерный массив.Устанавливаем ptr на первый элемент массива multi
    ptr = multi;


    //распечатаем этот массив построчно
    putchar('\n');
    print_array(ptr, 3);
    printf("\n\n");
    
    //объявим еще один многомерны массив
    float prices[2][9] = {
        {10.11, 10.99, 11.00, 10.50, 10.65, 10.25, 10.80, 10.10, 11.35},
        {25.00, 25.01, 25.5, 25.65, 26.00, 26.10, 25.99, 25.70, 26.55}
    };

    //объявим указатель на массив из 9 цен
    float (*ptr_prices)[9];

    //присвоим этому указателю адрес первой цены в первом массиве многомерного массива
    ptr_prices = prices;

    show_prices(ptr_prices, 2);

    //объявим еще один многомерный массив
    int numbers[3][3] = {
        {1,1,1},
        {2,2,2},
        {3,3,3}
    };

    //объявим указатель на массив из трех int
    int (*p_numbers)[3];
    p_numbers = numbers;

    show_num(p_numbers, 3);


    return 0;
}

void print_array(int(*ptr)[4], int n)
{
    //объявим простой указатель на тип int
    int *p;
    //присовим указателю p адрес ptr и сделаем приведение типа
    //так как эти два указателя указывают на разные типы данных
    //тут мы говорим, компилятору считать ptr как указатель просто на int, а не на многомер.массив
    p = (int*)ptr;
    for(int i = 0; i < n * 4; ++i){
        printf("%d ", *p++);
    }

    putchar('\n');
}

void show_prices(float(*ptr)[9], int items)
{
    //объявим просто указатель для обхода всех цен в многомерном массиве
    float *f_ptr;
    //присвоим этому указателю адрес самого первого значения самого превого массива
    //в многомерном массиве
    f_ptr = (float*)ptr;  //приведение к обычному указателю, во избежании конфликта

    //обходим все цены через простой указатель
    for(int i = 0; i < items * 9; ++i){
        printf("%.2f $ ", *f_ptr++);
    }
    putchar('\n');
}

void show_num(int (*ptr)[3], int col)
{
    //объявим простой указатель для дальнейшего перебора чисел
    int *pointer;

    //передадим этому указателю адрес самого первого значения и сделаем приведение типов
    //указателей
    pointer = (int*)ptr;

    for(int i = 0; i < col; ++i){
        for(int j = 0; j < 3; ++j){
            printf("%d ", *pointer++);
        }
        putchar('\n');
    }
    putchar('\n');
}
