//ПОИСК В СТРОКАХ

//strchr, strrchr, strcspn, strspn, strpbrk, strstr

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void find_symb_in_str(char *string, char symbol);

//общая ф-я для поиска либо первого, либо последнего вхождения символа в строке
int seek_sumb(char *string, char symb, char mode);

//проверка на совпадение символа одной строки в другой
int math_symb(char *str1, char *str2);

//поиск отсутствующего символа
int orig_symb(char *text_1, char *text_2);

//проверять до какого символа совпадают две строки
int strings_match_till(char *str1, char *str2);

//найдем одну строку в другой
int string_in_string(char *str1, char *str2);



int main(void)
{   
    //strchr() - обнаруживает первое вхождение заданного символа в заданной строке
    //поиск выполняется слева-направо
    char text[] = "I supposed to be honest and polite with people";
    char seek_symb = 's';
    find_symb_in_str(text, seek_symb);  //Sybol s stays in position 2


    //strrchr() - рызыскивает справа-налево, то есть последнее вхождение 
    //символа в строке
    //применим универсальную ф-ию
    int res_index = seek_sumb(text, 'b', 'l');
    printf("Symbol %c stays in index %d\n", 'b', res_index); //ищем слева-направо

    //ищем самый последний
    int res_r = seek_sumb(text, 'e', 'r');
    printf("Symbol %c stays in index %d\n", 'e', res_r);

    /*//посмотрим индексы всех символов
    for (int i = 0; i < sizeof(text) / sizeof(*text); ++i){
        printf("[%d] - %c\n", i, text[i]);
    }*/


    //strcspn() - разыскивает в строке первое вхождение любого символа из второй строки
    char text_1[] = "ABCDEF";
    char text_2[] = "GHIF";
    int match_pos = math_symb(text_1, text_2);
    printf("Match in index %d\n", match_pos);


    //strspn() - ищет в первой строке символ, которого нет во второй строке
    char stroka[] = "ABCxDEF";
    char sec_stroka[] = "ABCDEF";
    orig_symb(stroka, sec_stroka);

    //с помощбю этой функции можем узать до какого символа совпадают строки
    char letter[] = "This was an excellent day, i did a lot of tasks.";
    char letter2[] = "This was";
    strings_match_till(letter, letter2);


    //strbrk() - то же самое strcspn , но не включает завершающий символ

    //strstr() - ищет первое появление одной строки внутри другой, причем всей строки сразу
    char file_path[] = "https://www.football.ua";
    char file_path2[] = "football.ua";
    string_in_string(file_path, file_path2);




    return 0;
}

void find_symb_in_str(char *string, char symbol)
{   
    //указатель на символ,который найдем
    char *symb_pos;

    symb_pos = strchr(string, symbol);

    if(symb_pos == NULL){
        fprintf(stderr, "Symbol %c was not found!\n", symbol);
    }

    //вычислим позицию в которой стоит искомый символ
    int pos = symb_pos - string;

    printf("Sybol %c stays in position %d\n", symbol, pos);
}

int seek_sumb(char *string, char symb, char mode)
{   
    //объявим указатель на будущий символ
    char *ptr;


    //определеяем что за режим (mode)
    if (mode != 'l' && mode != 'r'){
        fprintf(stderr, "Undefined mode. Chose 'l' or 'r'!\n");
        exit(1);
    }

    else if(mode == 'l'){
        ptr = strchr(string, symb);

        //проверка
        if (ptr == NULL){
            fprintf(stderr, "Symbol %c was not found.\n", symb);
            exit(1);
        }
    }
    else{
        ptr = strrchr(string, symb);

        //проверка
        if(ptr == NULL){
            fprintf(stderr, "Symbol %c was notfound!\n", symb);
            exit(1);
        }
    }
    
    //вычислим индекс символа в строке
    int index = ptr - string;

    return index;
}

int math_symb(char *str1, char *str2)
{
    int res = strcspn(str1, str2);

    if(res == strlen(str1)){
        puts("No match!");
        exit(1);
    }

    return res;
}

int orig_symb(char *text_1, char *text_2)
{
    int res = strspn(text_1, text_2);
    
    if (res ==strlen(text_1)){
        puts("Orig symbol was not found!");
    }

    printf("Orig symbol is in index %d\n", res);
    return res;
}

int strings_match_till(char *str1, char *str2)
{
    int last_index_match = strspn(str1, str2);

    if (last_index_match == strlen(str1)){
        puts("Both text fully matched!");
    }

    printf("Texts matched till index %d\n", last_index_match);
    return last_index_match - 1;
}

int string_in_string(char *str1, char *str2)
{   
    char *ptr_match = strstr(str1, str2);
    if( ptr_match == NULL ){
        fprintf(stderr, "str2 is not in str1\n");
        exit(1);
    }

    printf("str2 begins in str1 in symbol %c\n", *ptr_match);

    //найдем индекс
    int index_match = ptr_match - str1;
    printf("Match index = %d\n", index_match);
    return index_match;
}