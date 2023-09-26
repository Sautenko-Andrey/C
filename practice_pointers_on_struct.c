#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum sizes {len_name = 15};

typedef struct footballer_info {
    char name[len_name];
    int number;
    int age;
    
} FOOTBALLER;


int main(void)
{   

    FOOTBALLER player = {"Saka", 7, 23};
    printf("%s, %d, %d\n",player.name, player.number, player.age);
    

    return 0;
}