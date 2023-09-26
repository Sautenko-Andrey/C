/*Опреации над строками символов
ОПРЕДЕЛЕНИЕ ДЛИНЫ, КОПИРОВАНИЕ СТРОК*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//ф-я определения длины строки strlen
unsigned get_str_length(char *text);

//ф-и копирования строк strcpy, strncpy
char* copy_str(char *orig_text);
char* copy_str_n(char *orig_text, size_t length);

//ф-я копирования не ANCII strdup()
char *copy_str_customize(char *orig_text);

int main(void)
{   
    //определение длины строки
    //объявим и инициализируем строку
    char my_text[] = "1234567";
    char empty_text[] = "";

    //определим ее длину(количество символов)

    get_str_length(my_text);    //Length of the string is 7
    get_str_length(empty_text);  //Length of the string is 0

    //////////////////////////////////////////////////////////////////////////

    //КОПИРОВАНИЕ СТРОК
    char text_1[] = "Please, don't scoff her and be polite.";

    //копируем
    char *new_string = copy_str(text_1);
    //печатаем результат
    puts(new_string);

    //а теперь скопируем без всяких доп/методов
    char str_1[] = "I prefer pull-ups to regular exercices.";
    char str_2[MAX];
    strcpy(str_2, str_1);
    puts(str_2);

    //воспользуемся вторым методом
    char sub[] = "Who wants to relocate? Are you ready for getting out from here?";
    char *copy_sub = copy_str_n(sub, sizeof(sub) / sizeof(*sub));
    puts(copy_sub);

    //добавим символ конца строки
    copy_sub[strlen(copy_sub)] = '\0';
    //распечатаем посимвольно
    for (int i = 0; i < sizeof(sub) / sizeof(*sub); ++i){
        printf("#%d %c\n", i + 1, *(copy_sub++));
    }


    //скопируем строку просто посредством стандартной функции
    char string_1[] = "12345";
    char string_2[6];
    strncpy(string_2, string_1, 5);
    puts(string_2);

    for (int i = 0; i < strlen(string_2); ++i){
        printf("#%d\t%c\n", i + 1, string_2[i]);
    }

    //скопируем строку через stdrdup()
    char some_text[] = "My aim is to relocate to the EU.";
    char *new_p = copy_str_customize(some_text);
    puts(new_p);

    return 0;
}

unsigned get_str_length(char *text)
{   
    /*ф-я определения длины строки*/

    unsigned count = strlen(text);

    printf("Length of the string is %u\n", count);

    return count;
}

char* copy_str(char *orig_text)
{
    /* Копирование строк с помощью ф-ии strcpy */

    //выделим память для новой строки
    char *copy_text = malloc(sizeof(char) * MAX);

    //проверка выделения памяти
    if(!copy_text){
        fprintf(stderr, "Allocation is not success!");
        exit(1);
    }

    //копируем строку
    if( strcpy(copy_text, orig_text) == NULL ){
        fprintf(stderr,"Copying error!!!");
        exit(1);
    }

    return copy_text;
}

char* copy_str_n(char *orig_text, size_t length)
{
    //выделяем память под новую строку
    char *ptr = malloc(sizeof(char) * length);

    //проверка выделения памяти
    if(!ptr){
        fprintf(stderr, "Allocation is not success!");
        exit(1);
    }

    //копируем
    if ( strncpy(ptr, orig_text, length) == NULL ){
        fprintf(stderr,"Copying error!");
        exit(1);
    }

    //добавим завершающий символ в конец строки
    size_t index = strlen(ptr);
    printf("len ptr = %lu\n", index);

    *(ptr + index) = '\0';

    return ptr;
}

char *copy_str_customize(char *orig_text)
{
    char *ptr;

    if ((ptr = strdup(orig_text)) == NULL){
        fprintf(stderr, "Copy error!");
        exit(1);
    }

    return ptr;
}