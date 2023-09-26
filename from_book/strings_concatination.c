//КОНКАТЕНАЦИЯ strcat(), strncat()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//via strcat()
void simple_concat(char *text_1, size_t size_text_1, char *text_2, size_t size_text_2);
//via strncat()
void modern_concat(char *text_1, size_t size_1, char *text_2, size_t count);

int main(void)
{   
    //воспользуемся ф-ей simple_concat()
    char text_1[60] = "I love women with tan.";
    size_t size_1 = sizeof(text_1);
    char text_2[] = "They are hot!";
    size_t size_2 = sizeof(text_2);

    simple_concat(text_1, size_1, text_2, size_2);

    puts(text_1);

    //воспользуемся модернизированной ф-ей
    char orig[100] = "Sometimes i feel grudge of nothing and i become mad apropus of nothing.";
    char new[] = "It bothers me.";
    modern_concat(orig,sizeof(orig), new, 10);
    puts(orig);

    return 0;
}

void simple_concat(char *text_1, size_t size_text_1, char *text_2, size_t size_text_2)
{   
    if ( (size_text_1 - strlen(text_1) - 1) < size_text_2 ){
        fprintf(stderr, "Size is short!\n");
        exit(1);
    }

    //сцепляем строки
    if( strcat(text_1, text_2) == NULL){
        fprintf(stderr, "I can't concatenate these two strings!");
        exit(1);
    }
}

void modern_concat(char *text_1, size_t size_1, char *text_2, size_t count)
{
    if ( (size_1 - strlen(text_1) - 1) < count ){
        fprintf(stderr, "Out of size!\n");
        exit(1);
    }

    //сцепляем строки
    if(strncat(text_1, text_2, count) == NULL){
        fprintf(stderr, "I can't concatenate these two strings!");
        exit(1);
    }

}