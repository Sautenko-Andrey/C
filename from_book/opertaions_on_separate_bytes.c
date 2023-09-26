//ОПРЕАЦИИ НАД ОТДЕЛЬНЫМИ БИТАМИ

#include<stdio.h>
#include<stdlib.h>

void left_right(int dig, size_t size);
char bit_ops(char x, char y, char ops);

int main(void)
{   
    //ОПЕРАЦИИ ПОРАЗРЯДНОГО СДВИГА
    //>>  -сдвиг вправо, <<  - сдвиг влево
    left_right(75, 10);

    //еще пример с int
    int x = 3;
    int res_r = x >> 1;
    int res_l = x << 1;
    printf("res_r = %d\n", res_r);   // res_r = 1. 3 / 2 = 1
    printf("res_l = %d\n", res_l);   //res_l = 6.   3 * 2 = 6

    //пример с char
    char w = 5;
    char res_r_w = w >> 1;
    printf("res_r_w = %d\n", res_r_w);  // 5 /2 = 2
    char res_l_w = w << 1;
    printf("res_r_l = %d\n", res_l_w);  // 5 *2 = 10


    //ПОРАЗРЯДНЫЕ ЛОГИЧЕСКИЕ ОПЕРАЦИИ

    // ПОРАЗРЯДНОЕ И &  - возвращает 1 если оба бита 1, иначе 0
    printf("res = %d\n", bit_ops(4, 6, '&'));   //res = 4
    printf("res = %d\n", bit_ops(11, 8, '&'));  //res = 8
    printf("res = %d\n", bit_ops(101, 32, '&'));  //32

    //ПОРАЗРЯДНОЕ ИЛИ | - возвращает 0 если оба 0, иначе 1
    printf("res = %d\n", bit_ops(2, 7, '|'));   //7
    printf("res = %d\n", bit_ops(33, 15, '|'));  //47

    //ПОРАЗРЯДНОГО ИСКЛЮЧАЮЩЕГО ИЛИ ^ - 1 когда разные биты, 0 когда одинаковые
    printf("res = %d\n", bit_ops(7, 10, '^'));   //13

    //ОПЕРАЦИЯ ДОПОЛНЕНИЯ ~  - меняет 0 на 1 , 1 на 0
    printf("res = %d\n", bit_ops(10, 1, '~'));   // -11




    return 0;
}

void left_right(int dig, size_t size)
{   
    int x_dig, y_dig;

    for (int i = 0; i < size; ++i){
        
        //свдинем вправо  (эквивалентно делению на 2 с отбросом дробной части)
        x_dig = dig >> i;

        //сдвиг влево  (умножение на 2)
        y_dig = dig << i;

        printf("%d<--- %d --->> %d\n", y_dig, dig, x_dig);
    }
}

char bit_ops(char x, char y, char ops)
{   
    if (ops != '&' && ops != '|' && ops != '^' && ops != '~'){
        fprintf(stderr, "ops error.\n");
        exit(1);
    }

    switch (ops)
    {
    case '&':
        return x & y;
        break;

    case '|':
        return x | y;
        break;

    case '^':
        return x ^ y;
        break;

    case '~':
        return ~x;
        break;
    
    default:
        break;
    }
}