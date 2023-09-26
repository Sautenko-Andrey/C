//РАБОТА  С ПАМЯТЬЮ.
#include<stdio.h>
#include<stdlib.h>


void* mul_XY(void *x, void *y, char type);
//для выделения памяти и проверки 
void memCheck(void *ptr);

//ПРЕОБРАЗОВАНИЕ ТИПОВ.

int main(void)
{   
    //НЕЯВНЫЕ ПРЕОБРАЗОВАНИЯ и РСШИРЕНИЯ ТИПОВ (выполняются компилятором автоматически)
    float res;
    int x = 10, y = 20;
    res = x + y;
    printf("%f\n", res);   //30.000000

    double res2;
    int x2 = 100;
    short y2 = 25;
    res2 = x2 * y2;
    printf("%f\n", res2);   //2500.000000


    //ЯВНЫЕ ПРЕОБРАЗОВАНИЯ ТИПОВ (приведение выполняется не автоматически, а под твоим контролем)

    double div_res;
    int x3 = 100;
    int y3 = 3;
    div_res = x3 / y3;
    printf("res = %f\n", div_res);  //res = 33.000000

    //но если сделать приведение типа к double 
    double res_div;
    int x4 = 100;
    int y4 = 3;
    res_div = (float)x4 / y4;
    printf("res = %f\n", res_div);   //res = 33.333332

    //или вот так
    double result;
    short attempts = 125;
    short days = 11;
    result = (double)attempts / (double)days;
    printf("result = %f\n", result);  //result = 11.363636


    //ПРИВЕДЕНИЕ УКАЗАТЕЛЕЙ
    int dig1 = 10, dig2 = 33;
    int *mul_res = mul_XY(&dig1, &dig2, 'i');
    printf("%d * %d = %d\n", dig1, dig2, *mul_res);



    return 0;
}

void* mul_XY(void *x, void *y, char type)
{
    //ЗДЕСЬ РАССМАТРИВАЕТСЯ ПРИВЕДЕНЕИЕ УКАЗАТЕЛЕЙ
    if ( type != 'i' && type != 'u' && type != 'l' && type != 'f' && type != 'd' ){
        fprintf(stderr, "Type error.\n");
        exit(1);
    }
    
    if ( type == 'i' ){
        int *res = malloc(sizeof(int));
        
        memCheck(res);

        *res = *(int *)x * *(int*)y;
        return res;
    }
    else if ( type == 'u' ){
        unsigned *res = malloc(sizeof(unsigned));
        
        memCheck(res);

        *res = *(unsigned*)x * *(unsigned*)y;
        return res;
    }
}

void memCheck(void *ptr)
{
    if ( ptr == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
}
