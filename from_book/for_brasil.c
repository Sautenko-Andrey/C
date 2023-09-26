#include<stdio.h>

#define LEN 3

struct player {
    char *name;
    char *club;
};

typedef struct player player;

void printf_BRA_squad(void)
{
    player bra_players[LEN] = {
        {"Gabriel Martinelli", "Arsenal FC"},
        {"Marcelo", "Real Madrid"},
        {"Alison", "Liverpool FC"}
    };

    for (int i = 0; i < LEN; ++i){
        printf("Name: %s\nClub: %s\n-----------------\n", bra_players[i].name,\
bra_players[i].club);
    }
}