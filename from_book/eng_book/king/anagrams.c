#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define WORD_MAX_SIZE 25

int main(void){

    int alphabet[26] = {0};
    char word_1[WORD_MAX_SIZE];
    char word_2[WORD_MAX_SIZE];

    printf("Enter the first word: ");
    fgets(word_1, WORD_MAX_SIZE, stdin);
    word_1[strlen(word_1) - 1] = '\0';

    printf("Enter the second word: ");
    fgets(word_2, WORD_MAX_SIZE, stdin);
    word_1[strlen(word_2) - 1] = '\0';


    return 0;
}