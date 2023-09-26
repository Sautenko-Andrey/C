/* Строковые функции sprintf(), atoi(), atol(), atoll() и atof() */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    // sprintf()

    /*пусть у нас имеются габаритные размеры width, height, depth и мы хотим сфоримировать
    эту инфу в виде строки по такому шаблону (width х height х depth)*/

    double width = 100.00, height = 50.00, depth = 25.00;
    char item_name[] = "Rolltop desk";

    //задаем строку, в которой будет храниться результат
    char info[50];

    //далее определим формат этой строки, в виде константной строки
    const char format[] = "(%.12s: %.2f x %.2f x %.2f)"; //.12 ограничивает до 12 символов

    //определяем ф-ю sprintf()
    sprintf(info, format, item_name, width, height, depth);



    //вычислить длины подставляемых строк и сформировать массив нужной длины
    //с помощью malloc() и free().
    //определим размер итоговой строки
    size_t size = sizeof(item_name) + 100;

    //сформируем указатель на область памяти, которую выделим с помощь ф-ии malloc.В ф-ии malloc
    //укажем размер в байтах, который хотим выделить,
    char *info_2 = malloc(size);
    //в итоге указатель *info_2 будет ссылаться н выделенную область памяти и в эту выделенную
    //область памяти будет записана вся необходимая информация
    sprintf(info_2, format, item_name, width, height, depth);
    puts(info_2);

    //в конце мы обязательно должны освободить выделенную под нас память
    free(info_2);


    //на практике ф-ию sprintf() часто используют для преобразования чисел в строки

    int dig = -123;
    //мы хотим представить это число -123 в виде строки: символ "-", символ "1",символ "2",
    //символ "3" и конец строки 0.

    //объявим строку, которая будет хранить результат
    char result[10];
    sprintf(result, "%d", dig);
    
    puts(result);

    //еще парктика
    int number = 99999;
    char str_number[6];
    sprintf(str_number, "%d", number);
    puts(str_number);


    //пример с переводом вещественных чисел в строки
    double f_dig = -33.99781;
    char str_f_dig[10];
    sprintf(str_f_dig, "%.2f", f_dig);
    puts(str_f_dig);



    //перевод чисел из строк в соотвтествующий числовой тип данных
    //для этого имеется набор следующих ф-ий:
    
    // atoi() - для преобразования целых чисел из строк в тип int;
    // atol() - для преобразования целых чисел в тип long;
    // atoll() - для преобразования целых чисел в тип long long;
    // atof() - для преобразования чисел в тип double.

    //примеры использования

    int int_dig = atoi("123");
    long long_dig = atol("1000000");
    long long long_long_dig = atoll("9876543210");
    double doub_dig = atof("4432.789");

    printf("%d\n%ld\n%lld\n%.3f\n", int_dig, long_dig, long_long_dig, doub_dig);

    




    return 0;
}