//Регистровые переменные
#include<stdio.h>

int main(void)
{   
    register int x = 100; //просим разместить переменную в регистре процессора для быстроты опреации
    register float y = 33.33;
    register float res;
    res = (float)x * y;

    printf("res = %.2f\n", res); 


    //сделаем счетчик цикла регистровой переменной
    for(register int i = 1; i <= 100; ++i){
        printf("#%d\n", i);
    }


    return 0;
}