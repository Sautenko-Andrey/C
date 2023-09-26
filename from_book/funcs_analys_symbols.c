//ФУНКЦИИ АНАЛИЗА СИМВОЛОВ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void true_false(int value);

int main(void)
{   
    // isalnum() - символ буква или цифра
    char symb = 'A';
    char symb2 = '8';

    int res = isalnum(symb);
    int res2 = isalnum(symb2);

    (res) ? puts("True") : puts("False");   //True
    (res2) ? puts("True") : puts("False");  //True


    // isalpha() - буква
    char x = 'F';
    int res_x = isalpha(x);
    (res_x) ? puts("True") : puts("False");   //True

    char y = '2';
    int res_y = isalpha(res_y);
    (res_y) ? puts("True") : puts("False");   //False


    // isblank() - пустой символ
    char empty = ' ';
    int res_empty = isblank(empty);
    true_false(res_empty);    //True


    // iscntrl() - управляющий символ
    char rule = '+';
    int res_rule = iscntrl(rule);
    true_false(res_rule);  


    //isdigit() - цифра
    char num = '8';
    true_false(isdigit(num)); //True


    //islower() - буква в нижнем регистре
    char a = 'a';
    true_false(islower(a)); //True

    //isupper() - буква в верхнем регистре
    char X = 'X';
    true_false(isupper(X));  //True


    // ispunct() - знак препинания
    char coma = ',';
    true_false(ispunct(coma));  //True

    // isspace() - символ свободного простарнства
    char tab = '\t';
    true_false(isspace(tab));   //True


    // isxdigit() - шестнадцатиричная цифра
    char xec = '9a';
    true_false(isxdigit(xec));   //True


    return 0;
}

void true_false(int value)
{
    (value) ? puts("True") : puts("False");
}