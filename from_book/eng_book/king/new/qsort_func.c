//The qsort function

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define MAX_NAME 25
#define NUMBER_LEN 13

struct player {
    char name[MAX_NAME + 1];
    int number;
    struct player *next;
};

struct phone_contact {
    char name[MAX_NAME + 1];
    char number[NUMBER_LEN + 1];
};

int compare_int(const void *x, const void *y);
void add_player(struct player **data_base, char *new_name, int new_number);
void print_data(struct player *data_base);
int compare_players(const void *player_1, const void *player_2);
int compare_players2(const void *player_1, const void *player_2);
int compare_by_name(const void *player_1, const void *player_2);
int cmp_name(const void *cont1, const void *cont2);


int main(void)
{   
    int array_i[MAX] = {9,3,2,5,6,1,4,7,10,8};
    qsort(array_i, MAX, sizeof(int), compare_int);

    for(int i = 0; i < MAX; ++i){
        printf("%d ", array_i[i]);
    }
    putchar('\n');

    struct player *arsenal = NULL;
    add_player(&arsenal, "Bukayo Saka", 7);
    add_player(&arsenal, "Aaron Ramsdale", 1);
    add_player(&arsenal, "Ben White", 4);
    add_player(&arsenal, "Leandro Trossard", 19);
    add_player(&arsenal, "Gabriel Jesus", 9);

    print_data(arsenal);
    
    qsort(arsenal, 5, sizeof(struct player), compare_by_name);
    print_data(arsenal);


    struct phone_contact phone_book[4] = {
        {"Chausov Alex", "+380663214523"},
        {"Ann", "+380956452312"},
        {"Klaptenko Igor", "+380991112369"},
        {"Marchenko Max", "+380977412369"}
    };

    qsort(phone_book, 4, sizeof(struct phone_contact), cmp_name);

    for(int i = 0; i < 4; i++){
        printf("%-25s\t%s\n", phone_book[i].name, phone_book[i].number);
    }
    putchar('\n');








    return 0;
}

int compare_int(const void *x, const void *y)
{
    if ( *(int*)x < *(int*)y ){
        return -1;
    }
    else if( *(int*)x == *(int*)y ){
        return 0;
    }
    else{
        return 1;
    }
}

void add_player(struct player **data_base, char *new_name, int new_number)
{
    struct player *new_player = malloc(sizeof(struct player));
    if (new_player == NULL){
        fprintf(stderr, "Error: memory allocation memory.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_player->name, new_name);
    new_player->number = new_number;

    new_player->next = *data_base;
    *data_base = new_player; 
}

void print_data(struct player *data_base)
{
    struct player *ptr;

    printf("Name\t\t\t  Number\n-------------------------------\n");
    for(ptr = data_base; ptr != NULL; ptr = ptr->next){
        printf("%-25s    %d\n", ptr->name, ptr->number);
    }
}

int compare_players(const void *player_1, const void *player_2)
{
    return  ((struct player*)player_1)->number - ((struct player*)player_2)->number;
}

int compare_players2(const void *player_1, const void *player_2)
{
    if( ((struct player*)player_1)->number < ((struct player*)player_2)->number ){
        return -1;
    }
    else if( ((struct player*)player_1)->number == ((struct player*)player_2)->number ){
        return 0;
    }
    else{
        return 1;
    }
}

int compare_by_name(const void *player_1, const void *player_2)
{
    return strcmp( ((struct player*)player_1)->name, ((struct player*)player_2)->name );
}

int cmp_name(const void *cont1, const void *cont2)
{
    return strcmp( (char*)cont1, (char*)cont2 );
}