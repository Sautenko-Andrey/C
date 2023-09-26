//посмотрим как распологаются символы алфавита в ASCII

#include<stdio.h>

int main(void)
{   
    char start = 'a';
    int symb_amount = 26;


    //посмотрим весь алфавит
    for(int i = 1; i <= symb_amount; ++i){
        printf("%c is %d in ASCII\n", start, start);
        start++;
    }

    //начало и конец алфавита в нижнем регистре
    printf("\n\na = %d\n", 'a');
    printf("\n\nz = %d\n", 'z');

    //a = 97 , z = 122

    //посмотрим алфавит в верхнем регистре
    char upper_start = 'A';
    for(int i = 1; i <= symb_amount; ++i){
        printf("%c is %d in ASCII\n", upper_start, upper_start);
        upper_start++;
    }

    //начало и конец
    printf("\n\na = %d\n", 'A');
    printf("\n\nz = %d\n", 'Z');


    //A = 65, Z = 90

    //(если символ меньше 97 или больше 122) И (символ меньше 65 или символ больше 90)

    return 0;
}