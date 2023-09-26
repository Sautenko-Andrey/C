//Передача структур в функции

#include<stdio.h>

struct footballer
{
    char *name;
    unsigned char number;
};

typedef struct footballer footballer;

//объявляем прототп ф-ии, которая ничего не возвращает, но принимает аргумент типа footballer
void player_info(footballer player);

//такая же ф-я, только принимающая аргумент - указатель на структуру
void player_info_2(footballer *ptr);

int main(void)
{   
    //создадим перменную структуры
    footballer declan_rice = {"Declan Rice", 41};

    //вызовем ф-ию player_info()
    player_info(declan_rice);

    //объявим указатель на структуру
    footballer *ptr_declan_rice = &declan_rice;

    //применим вторую ф-ию
    player_info_2(ptr_declan_rice);

    return 0;
}

void player_info(footballer player)
{
    putchar('\n');
    printf("_____________________\nPlayer: %s\nNumber #%d\n", player.name, player.number);
}

void player_info_2(footballer *ptr)
{
    printf("\n________________\nPlayer: %s\nNumber: #%d\n", ptr->name, ptr->number);
}