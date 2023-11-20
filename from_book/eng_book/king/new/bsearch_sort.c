// Usage bsearch

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct player {
    char *name;
    char *position;
    unsigned int age:10;
};

static int comp_players(const void *searched_player, const void *db_player);
static struct player* search_player(const char *player_name, const struct player *DB);


int main(void)
{   
    static struct player team_Arsenal[] = {
        {"Aaron Ramsdale", "GK", 23}, {"Ben White", "RB/CD", 26},
        {"William Saliba", "CD", 21}, {"Gabriel", "CD", 26},
        {"Alex Zinchenko", "LB/CM/DCM", 26}, {"Declan Rice", "CM/DCM", 23}
    };

    struct player *player = search_player("Aaron Ramsdale", team_Arsenal);


    return 0;
}

static int comp_players(const void *searched_player, const void *db_player)
{
    return strcmp( (char*)searched_player, (( struct player*)db_player)->name ); 
}

static struct player* search_player(const char *player_name, const struct player *DB)
{
    struct player *ptr;


    ptr = bsearch(player_name, DB, sizeof(DB) / sizeof(*DB), sizeof(*DB), comp_players);

    if(ptr != NULL){
        printf("Searched player:\n"
              "Name: %s\nPosition: %s\nAge: %u\n", ptr->name, ptr->position, ptr->age);
    }
    else{
        printf("%s is not in the team squad.\n", player_name);
    }

    return ptr;
}