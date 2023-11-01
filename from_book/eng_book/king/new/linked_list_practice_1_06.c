#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define NAME_LEN 50
#define NAT_LEN 3

struct player {
    char name[NAME_LEN + 1];
    int number;
    char nationality[NAME_LEN + 1];
    struct player *next;
};

struct player *arsenal = NULL;

void add_data(void);
int read_line(char str[], int n);

int main(void)
{
    add_data();
}

void add_data(void)
{
    struct player *new_player;
    new_player = malloc(sizeof(struct player));

    if(new_player == NULL){
        fprintf(stderr, "Error: memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter player name: ");
    read_line(new_player->name, NAME_LEN);

    printf("Enter player number: ");
    scanf("%d", &new_player->number);

    printf("Enter player nationality: ");
    read_line(new_player->nationality, 3);

    new_player->next = arsenal;
    arsenal = new_player;
}

int read_line(char str[], int n)
{
    int symb;
    int i = 0;
    while(isspace(symb = getchar())){
        ;
    }

    while(symb != '\n' && symb != EOF){
        if( i < n ){
            str[i++] = symb;
        }
        symb = getchar();
    }
    str[i] = '\0';
    return i;
}