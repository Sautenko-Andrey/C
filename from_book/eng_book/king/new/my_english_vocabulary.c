#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"readline.h"

#define ADD_WORD 'a'
#define UKR_TO_ENG 'u'
#define ENG_TO_UKR 'e'
#define EXIT 'c'
#define PRINT 'p'

#define MAX_LEN 50

struct word {
    char eng[MAX_LEN + 1];
    char ukr[MAX_LEN + 1];
    struct word *next;
};

void add_word(void);
void add_word_V2(void);
void ukr_to_eng(void);
void eng_to_ukr(void);
struct word* find_word(char *eng_word);
void print_vocabulary(void);

struct word *vocabulary = NULL;

int main(void)
{   
    char user_command;

    for(;;){
        printf("Please choose comand:\n"
           "a - add word, u ukr to eng, e - eng to ukr, c - exit, p - print: ");

        scanf(" %c", &user_command);

        switch (user_command)
        {
        case ADD_WORD:
            add_word_V2();
            break;

        case UKR_TO_ENG:
            ukr_to_eng();
            break;

        case ENG_TO_UKR:
            eng_to_ukr();
            break;

        case PRINT:
            print_vocabulary();
            break;

        case EXIT:
            return 0;
        
        default:
        printf("Unsupported command\n");
        }
    }

    return 0;
}

struct word* find_word(char *eng_word)
{
    struct word *ptr;

    for( ptr = vocabulary; ptr != NULL; ptr = ptr->next ){
        ;
    }

    if ( ptr != NULL && ((strcmp(ptr->eng, eng_word) == 0)) ){
        return ptr;
    }

    return NULL;
}

void add_word(void)
{   
    struct word *new_word;
    struct word *current, *previous;

    new_word = malloc(sizeof(struct word));

    if(new_word == NULL){
        fprintf(stderr, "Error: memory allocation failed in add_word()\n");
        exit(EXIT_FAILURE);
    }


    printf("Enter english word: ");
    read_line(new_word->eng, MAX_LEN);

    for( current = vocabulary, previous = NULL;
    current != NULL && ( strncmp(current->eng, new_word->eng, strlen(current->eng)) < 0 );
    previous = current, current = current->next){
        ;
    }

    if((strncmp(current->eng, new_word->eng, strlen(current->eng)) == 0)){
        fprintf(stderr, "Error: word already exists.\n");
        free(new_word);
        return;
    }

    printf("Enter ukrainian translate: ");
    read_line(new_word->ukr, MAX_LEN);

    new_word->next = current;
    if (previous == NULL){
        vocabulary = new_word;
    }
    else{
        previous->next = new_word;
    }
}

void print_vocabulary(void)
{
    struct word *ptr;

    printf("ENG\t\tUKR\n");

    for( ptr = vocabulary; ptr != NULL; ptr = ptr->next ){
        printf("%s\t\t%s\n", ptr->eng, ptr->ukr);
    }
}

void ukr_to_eng(void)
{

}
void eng_to_ukr(void)
{

}

void add_word_V2(void)
{
    struct word *new_word;
    new_word = malloc(sizeof(struct word));
    if (new_word == NULL){
        fprintf(stderr, "Error: memory allocation error in add_word_V2()\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter english word: ");
    read_line(new_word->eng, MAX_LEN);
    
    printf("Enter ukr word: ");
    read_line(new_word->ukr, MAX_LEN);

    new_word->next = vocabulary;
    vocabulary = new_word;
}