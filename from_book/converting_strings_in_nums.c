//ПРЕОБРАЗОВАНИЕ СТРОК В ЧИСЛА
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{   
    //проеобразование строк в целые числа int atoi()
    //есть строка
    char text[] = "123";
    //преобразуем в число
    int dig = atoi(text);

    printf("We got number: %d\n", dig);

    //еще пример
    char ttt[] = "+3809";
    int ttt_i = atoi(ttt);
    printf("We got number: %d\n", ttt_i);

    //еще пример
    //есть массив строк
    char *strings[] = {
        "123",
        "-99",
        "3496",
        "+0.1"
    };
    
    int count = sizeof(strings)/sizeof(*strings);
    int nums[count];
    
    for(int i = 0; i < count; ++i){
        //printf("%s\n", *(strings + i));
        nums[i] = atoi(*(strings + i));
    }

    for (int i = 0; i < count; ++i){
        printf("%d ", nums[i]);
    }
    putchar('\n');


    //ПРЕОБРАЗОВАНИЕ СТРОК В ДЛИННЫЕ ЦЕЛЫЕ ЧИСЛА long atol()
    char str_num[] = "101010";
    long res = atol(str_num);
    printf("%ld\n", res);


    //ПРЕОБРАЗОВАНИЕ СТРОК в long long atoll()
    char ten_million[] = "10000000";
    long long res_mil = atoll(ten_million);
    printf("%lld\n", res_mil);


    //ПРЕОБРАЗОВАНИЕ СТРОК В ЧИСЛА С ПЛАВАЮЩЕЙ ТОЧКОЙ duble atof()
    char price[] = "99.99";
    double f_price = atof(price);
    printf("%.2f\n", f_price);

    return 0;
}
