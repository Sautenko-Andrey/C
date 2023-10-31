#include<stdio.h>
#include<stdlib.h>
#include"readline.h"

#define NAME_LEN 50
#define INSERT 'i'
#define FIND 'f'
#define PRINT 'p'
#define NEXT putchar('\n')

struct player {
    char name[NAME_LEN + 1];
    int age;
    int number;
    struct player *next;
};

void insert_player(void);
struct player* find_player(char *player_name);
void print_team(void);


int main(void)
{   
    char user_command;

    for(;;){
        printf("Enter a command (i, f, p): ");
        scanf(" %c", &user_command);

        switch (user_command)
        {
        case INSERT:
            insert_player();
            break;

        case PRINT:
            print_team();
            break;
        
        default:
            fprintf(stderr, "Unsupported command.\n");
        }
    }

    NEXT;
    

    return 0;
}