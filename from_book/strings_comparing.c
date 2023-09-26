//СРАВНЕНИЕ СТРОК
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 5

void compare_str(char *str1, char *str2);
void compare_str_modern(char *str1, char *str2, size_t length);


int main(void)
{   
    //сравнение двух целых строк strcmp()
    char name[] = "Vicky";
    char name_2[] = "Willy";

    compare_str(name, name_2);

    //сравнение фрагментов двух строк
    compare_str_modern(name, name_2, LEN);


    return 0;
}

void compare_str(char *str1, char *str2)
{
    //сравнение целых строк
    int res = strcmp(str1, str2);

    if (res == 0){
        printf("str1 == str2\n");
    }
    else if (res < 0){
        printf("str1 < str2\n");
    }
    else{
        printf("str1 > str2\n");
    }
}

void compare_str_modern(char *str1, char *str2, size_t length)
{   
    if (length <= 0){
        fprintf(stderr, "Error!Length must be > 0!\n");
        exit(1);
    }

    //сравнение фрагментов строк
    int res = strncmp(str1, str2, length);

    if (res == 0){
        printf("str1 == str2\n");
    }
    else if (res < 0){
        printf("str1 < str2\n");
    }
    else{
        printf("str1 > str2\n");
    }  
}