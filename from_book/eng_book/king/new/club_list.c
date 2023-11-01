#include<stdio.h>
#include<stdlib.h>
#include"readline.h"
#include<string.h>

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

struct player *team = NULL;


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

struct player* find_player(char *player_name)
{
    struct player *ptr;

    for( ptr = team; ptr != NULL && ptr->name != player_name; ptr = ptr->next ){
        ;
    }

    if( ptr != NULL && ptr->name == player_name ){
        return ptr;
    }

    return NULL;
}

void insert_player(void)
{
    struct player *current, *previous, *new_player;

    new_player = malloc(sizeof(struct player));

    if(new_player == NULL){
        fprintf(stderr, "Error: memory allocation error in insert_player()\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a player name: ");
    read_line(new_player->name, NAME_LEN);

    for( current = team, previous = NULL; current != NULL && new_player->name > current->name;
    previous = current, current = current->next){
        ;
    }

    if(current != NULL && (strcmp(current->name, new_player->name) == 0)){
        fprintf(stderr, "This player already exists\n");
        free(new_player);
        return;
    }

    printf("Enter player age: ");
    scanf("%d", &new_player->age);

    printf("Enter player number: ");
    scanf("%d", &new_player->number);

    new_player->next = current;
    if(previous == NULL){
        team = new_player;
    }
    else{
        previous->next = new_player;
    }
}

void print_team(void)
{
    struct player *ptr;

    printf("Name\t\t\tAge\tNumber\n");
    for(ptr = team; ptr != NULL; ptr = ptr->next){
        printf("%s\t\t%d\t%d\n", ptr->name, ptr->age, ptr->number);
    }
}