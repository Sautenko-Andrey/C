#include"voc_func.h"
#include<stdlib.h>
#include<stdio.h>
#include"readline.h"


static void check_mem(void *ptr)
{
    if(ptr == NULL){
        fprintf(stderr, "Error: memory allocation in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}

void add_word(struct word **vocabulary)
{
    struct word *new_word = malloc(sizeof(struct word));
    check_mem(new_word);

    printf("Enter an english word: ");
    read_line(new_word->eng, MAX);
    printf("Enter an ukrainian word: ");
    read_line(new_word->ukr, MAX);

    new_word->next = *vocabulary;
    *vocabulary = new_word;
}

void show_vocabulary(struct word *vocabulary)
{
    struct word *ptr;

    printf("ENGLISH\t\t\tUKRAINIAN\n-----------------------------------\n");
    for(ptr = vocabulary; ptr != NULL; ptr = ptr->next){
        printf("%-25s   %-25s\n", ptr->eng, ptr->ukr);
    }
}