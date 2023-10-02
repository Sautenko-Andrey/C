//This is first attempt to write code for eng-ukr vocabulary

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define WORDS_AMOUNT 100

struct data {
    char *eng;
    char *rus;
};

typedef struct data DATA;

//func headers
unsigned short greetings(void);
void app(unsigned short mode, const DATA vocabulary[], size_t len_vocabulary);


int main(void)
{   

    //let's create an array of DATA
    DATA all_words[WORDS_AMOUNT] = {
        {"to restrict", "ограничивать"},
        {"for the convenience","для удобства"},
        {"blackmail","шантаж"},
        {"to stroll", "гулять"}
    };

    unsigned short mode_res = greetings();

    app(mode_res, all_words, 4);
    


    return 0;
}

unsigned short greetings(void)
{   
    unsigned short mode;

    printf("\n\tWelcome to the VocabullaryApp!\n");
    printf("Please choose language verison of the app.\nrus-eng - 0, eng-rus - 1\n");
    scanf("%hd", &mode);

    if(mode != 0 && mode != 1){
        fprintf(stderr, "User argument error. Only two modes: 0 or 1.\n");
        exit(1);
    }

    mode ? puts("You choosen eng-rus mode") : puts("You choosen rus-eng mode");

    return mode;
}

void app(unsigned short mode, const DATA vocabulary[], size_t len_vocabulary)
{   
    puts("Let's start!\n");

    char user_answer[25];
    const DATA *ptr;

    if(mode == 0){
        for(ptr = vocabulary; ptr < vocabulary + 4; ptr++){
            printf("\nTranslate %s : ", ptr->rus);
            fgets(user_answer, sizeof(user_answer), stdin);
        }
    }
    else{
        puts("In progress.");
    }
}