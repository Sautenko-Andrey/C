//Создание структурных типов с помощью typedef
#include<stdio.h>

#define INDOOR  'I'
#define BEACHVOLLEY 'B'

typedef struct player
{
    char *name;
    unsigned char age;
    char *city;
} player;

typedef struct volleyballer
{
    char type;
    union variety{
        char *indoor;
        char *beachvolley;
    } place;

    player user;
} vol_player;

void print_player_info(vol_player x_player);

int main(void)
{   
    vol_player chaus = {
        BEACHVOLLEY,
        "beach voleyball player",
        {
            "Alex Chausov",
            36,
            "Kramatorsk"
        }
    };

    vol_player mlyaviy;
    
    //создадим указатель на эту структуру
    vol_player *ptr = &mlyaviy;
    ptr->type = INDOOR;
    ptr->user.name = "Mlyaviy Ruslan";
    ptr->user.age = 33;

    print_player_info(chaus);
    print_player_info(mlyaviy);

    return 0;
}

void print_player_info(vol_player x_player)
{
    switch (x_player.type)
    {
    case BEACHVOLLEY:
        printf("Name: %s\n", x_player.user.name);
        printf("Age: %d years\n", x_player.user.age);
        printf("City: %s\n", x_player.user.city);
        printf("Occupation: %s\n", x_player.place.beachvolley);
        puts("__________________________");
        break;

    case INDOOR:
        printf("Name: %s\n", x_player.user.name);
        (x_player.user.age == NULL) ? printf("Age: ---\n") : printf("Age: %d years\n", x_player.user.age);
        (x_player.user.city == NULL) ? printf("City: ---\n") : printf("City: %s\n", x_player.user.city);
        (x_player.place.indoor == NULL) ? printf("Occupation: ---\n") : printf("Occupation: %s\n", x_player.place.indoor);
        puts("__________________________");
        break;
    
    default:
    printf("Undefined player.");
        break;
    }
}