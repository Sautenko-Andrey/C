//Практика с операиями над памятью


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void bit_ops(int digit, size_t size);
void binary_convert(int x);


int main(void)
{   
    /*Предположим, объявлен следующий массив:
    float data[1000];
    Продемонстрируйте два способа инициализации всех элементов этого массива числами 0,
    В одном случае воспользуйтесь циклом и присваиванием, а во втором — функцией
    memset().*/

    clock_t start = clock();

    float data[1000];
    for (int i = 0; i < 1000; ++i){
        data[i] = 0;
    }

    clock_t finish = clock();
    printf("time: %Lf s\n", (long double)(finish - start) / CLOCKS_PER_SEC);//0.000004 s

    clock_t begin = clock();
    float box[1000];
    memset(box, 0, 1000);
    clock_t end = clock();
    printf("time: %Lf s\n", (long double)(end -begin) / CLOCKS_PER_SEC); //0.000002 s
    

    for (int i = 0; i < 100; ++i){
        printf("%.1f ",data[i]);
    }
    putchar('\n');


    /*Напишите программу, использующую все побитовые операции. Программа должна при-
    менять битовую операцию к числу, а затем применять ее еще раз к результату. При этом
    следует наблюдать за значениями данных на экране, чтобы быть в курсе происходящего.*/

    clock_t start1 = clock();
    bit_ops(100, 10);
    clock_t finish1 = clock();
    printf("Time: %Lf s\n", (long double)(finish1 - start1) / CLOCKS_PER_SEC); //Time: 0.000238 s


    /*Напишите программу, выводящую на экран двоичное представление числа. Например, ес-
    ли пользователь введет 3, на экране должно появиться число 00000011. (Подсказка: вам
    обязательно понадобятся побитовые операции.)*/
    binary_convert(5);

    //разборка последнего задания
    printf("\n\n");
    int x = 100;
    for (int i = 0; i < 10; ++i){
        printf("%d\n", x);
        x <<= 1;
    }

    int y = 50;
    int res = (y & 0x80);
    printf("res = %d\n", res);

    return 0;
} 

void bit_ops(int digit, size_t size)
{
    //for move left and move right
    int digit_r, digit_l;
    //for the logic
    int res_AND, res_OR, res_precludeOR, res_Reverse;

    puts("Move to the right and to the left operations.");
    for (int i = 0; i < size; ++i){
        digit_r = digit >> i;
        digit_l = digit << i;
        printf("%d <-- %d --> %d\n", digit_l, digit, digit_r);
    }

    puts("& , |, ^, ~ operations");
    printf("AND\tOR\tXOR\tREV\n---------------------------------\n");
    for(int i = 0; i < size; ++i){
        res_AND = digit & i;
        res_OR = digit | i;
        res_precludeOR = digit ^ i;
        res_Reverse = ~digit;
        printf("%d\t%d\t%d\t%d\n", res_AND, res_OR, res_precludeOR, res_Reverse);
        puts("----------------------------------");
    }
}

void binary_convert(int x)
{
    for (int i = 0; i < 8; i++) {
    printf("%c", (x & 0x80) ? '1' : '0');
    x <<= 1;
  }
  printf("\n");
}