#include<stdio.h>
#include<stdlib.h>

#define NAME_LEN 25
#define POS_LEN 2

struct player {
    char name[NAME_LEN + 1];
    unsigned number;
    char pos[POS_LEN + 1];
    struct player *next;
};

struct player* create_team(int num_players);

int main(void)
{   

    struct player *team = create_team(3);
    printf("Name: %s\n", team->name);

    free(team);        

    return 0;
}


struct player* create_team(int num_players)
{
    struct player *first = NULL, *new_player;
    int i, sc_num;    

    for( i = 0; i < num_players; i++ ){
        new_player = malloc(sizeof(struct player));
        if(new_player == NULL){
            fprintf(stderr,"Error: memory allocation failed for new_player\n");
            exit(EXIT_FAILURE);
        }

        /* Filling data */
        /* Getting a name */
        printf("Enter a name and press ENTER: ");
        fgets(new_player->name, NAME_LEN, stdin);
        new_player->name[NAME_LEN] = '\0';

        /* Getting a number */
        printf("Enter a number and press ENTER: ");
        sc_num = scanf("%d", &new_player->number);
        if(sc_num != 1){
            fprintf(stderr, "scanf error: too many arguments\n");
            exit(EXIT_FAILURE);
        }
        
        /* Getting a position */
        printf("Enter a position and press ENTER: ");
        fgets(new_player->pos, POS_LEN, stdin);
        new_player->pos[POS_LEN + 1] = '\0';
        
        /*########################################*/
        /* Node positioning */
        new_player->next = first;
        first = new_player;
    }

    return first;
}
