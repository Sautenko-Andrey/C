// <limits.h>

#include<stdio.h>
#include<limits.h>


#if INT_MAX < 100000
#error int type is too small    //если максимальное число неадекватно, компиляятору будет
#endif                          //сообщено об ошибке

#if INT_MAX >= 100000         //в зависимости от максимума int, мы определяем новый тип
typedef int Quantity;
#else
typedef long int Quantity;
#endif


int main(void)
{   
    


    return 0;
}