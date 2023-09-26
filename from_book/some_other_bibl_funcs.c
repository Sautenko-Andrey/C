//НЕКОТОРЫЕ БИБЛИОТЕЧНЫЕ ФУНКЦИИ С
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(void)
{   
    //МАТЕМАТИЧЕСКИЕ ФУНКЦИИ
    //ТРИГОНОМЕТРИЧЕСКИЕ ФУНКЦИИ
    double res = pow(10, 2);
    printf("%.2f\n", res);

    //все как и у пайтона


    //ОБРАБОТКА ВРЕМЕНИ
    //определим время выполнения программы

    //получение времени начала программы
    //вычисление длительности программы в сотых долях секунды
    printf("Time : 0.%ld c\n", clock());

    int x = 4, y = 6;

    double res2 = (pow(x, y) + pow(y, x));
    printf("Time : 0.%ld c\n", clock());

    return 0;
}

