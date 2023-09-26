#include<stdio.h>

#define LEN 3

struct player {
    char *name;
    char *club;
};

typedef struct player player;

void printf_ENG_squad(void)
{
    player eng_players[LEN] = {
        {"Bukayo Saka", "Arsenal FC"},
        {"Kyle Walker", "Manchester City"},
        {"Rhys James", "Chelsea FC"}
    };

    for (int i = 0; i < LEN; ++i){
        printf("Name: %s\nClub: %s\n-----------------\n", eng_players[i].name,\
eng_players[i].club);
    }
}
