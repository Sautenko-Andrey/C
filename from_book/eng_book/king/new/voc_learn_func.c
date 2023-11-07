#include"voc_learn_func.h"
#include<stdlib.h>
#include<stdio.h>
#include"readline.h"
#include<string.h>

void start_learning(struct word *vocabulary)
{   
    int user_mode;

    printf("Please choose mode (eng-ukr - 0, ukr_eng - 1): ");

    scanf("%d", &user_mode);

    if (user_mode == 0){
        printf("Welcome to eng - ukr mode!\n");
        
        struct word *ptr;
        char user_word[MAX + 1];

        for(ptr = vocabulary; ptr != NULL; ptr = ptr->next){
            printf("%s -> ", ptr->eng);
            read_line(user_word, MAX);
            if(strncmp(ptr->ukr, user_word, strlen(ptr->ukr)) == 0){
                puts("Right!");
            }
            else{
                puts("Wrong!");
            }
        }
    }
    else if(user_mode == 1){
        printf("Welcome to ukr - eng mode!\n");
        struct word *ptr;
        char user_word[MAX + 1];
        
        for(ptr = vocabulary; ptr != NULL; ptr = ptr->next){
            printf("%s -> ", ptr->ukr);
            read_line(user_word, MAX);
            if(strncmp(ptr->eng, user_word, strlen(ptr->eng)) == 0){
                puts("Right!");
            }
            else{
                puts("Wrong!");
            }
        }
    }
    else{
        fprintf(stderr, "Error: learning mode error in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}