#include<stdio.h>
#include"voc_func.h"
#include"voc_learn_func.h"


int greetings(void);

int main(void)
{   
    static int user_command;
    static struct word *my_vocabulary = NULL;

    for(;;){
        
        user_command = greetings();
        switch (user_command)
        {
        case 0:
            puts("Good bye!");
            break;

        case 1:
            start_learning(my_vocabulary);
            break;

        case 2:
            add_word(&my_vocabulary);
            break;

        case 3:
            show_vocabulary(my_vocabulary);
            break;
        
        default:
            puts("Unknown command.");
        }
    }


    return 0;
}

int greetings(void)
{   
    int user_command;

    printf("Hi there!\nMenu command\n------------\n"
          "EXIT - 0\nSTART LEARNING - 1\nADD A NEW WORD - 2\n"
          "SHOW ALL WORDS - 3\n"
          "-------------------\nSELECT A COMMAND: ");

    scanf("%d", &user_command);

    return user_command;
}