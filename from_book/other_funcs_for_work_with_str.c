//РАЗНЫЕ ФУНКЦИИ ДЛЯ РАБОТЫ СО СТРОКАМИ strrev(), strset(), strnset(), strlwr(), strupr()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//ф-я реверса строки вместо strrev()
void reverse_str(char *text);

//ф-я возведения всех символов в верхний или нижний регистр вместо strlwr(), strupr()
void low_or_up(char *text, char mode);

//замена для strset
void set_all_symbols(char *text, char symbol);

//замена для strnset()
void set_n_symb(char *text, char symb, size_t num);

int main(void)
{   
    //strrev() - изменяет порядок символов в строке на противоположный
    
    //ЭТИ ФУНКЦИИ НЕ ПОДДЕРЖИВАЮТСЯ
    //я написал свой метод вместо strrev()
    char my_text[] = "Asr";
    reverse_str(my_text);
    puts(my_text);

    //еще один текст 
    char name[] = "Andrey Sautenko";
    reverse_str(name);
    puts(name);


    //поиграемся с регистрами(я написал свой метод вместо strlwr(), strupr())
    char random_text[] = "I am considering relocation to UK.";
    low_or_up(random_text, 'u');
    puts(random_text);


    // замена для strset(), strnset()
    //strset - заменяет все символы строки на один и тот же заданный символ
    //strnset() - заменяемт указанное кол-во символов строки на указанный символ
    char string[] = "You've got an attitide problem.";
    set_all_symbols(string, 'X');
    puts(string);

    //
    char str1[] = "Keep pushing!";
    set_n_symb(str1, 'I', 4);
    puts(str1);

    return 0;
}

void reverse_str(char *text)
{

    size_t length = strlen(text);

    //находим середину
    int middle = length / 2;

    for (int i = 0; i < middle; ++i){
        char start = text[i];
        char end = text[strlen(text) - 1 - i];

        text[i] = end;
        text[strlen(text) - 1 - i] = start;
    } 
}

void low_or_up(char *text, char mode)
{   
    //verification mode
    if(mode != 'l' && mode != 'u'){
        fprintf(stderr, "Innapropriate mode!\n");
        exit(1);
    }

    //get length of text
    size_t length = strlen(text);

    //depends of mode
    if(mode == 'l'){
        for(int i = 0; i < length; ++i){
            if(toupper(text[i])){
                text[i] = tolower(text[i]);
            }
        }
    }
    else{
        for(int i = 0; i < length; ++i){
            if(tolower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
    }
}

void set_all_symbols(char *text, char symbol)
{
    //get length
    size_t length = strlen(text);

    //set symbols
    for(int i = 0; i < length; ++i){
        text[i] = symbol;
    }
}

void set_n_symb(char *text, char symb, size_t num)
{
    //verify
    if(num > strlen(text)){
        fprintf(stderr, "decrease num. Its oversize!\n");
        exit(1);
    }

    for(int i = 0; i < num; ++i){
        text[i] = symb;
    }
}