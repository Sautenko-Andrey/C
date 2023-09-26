#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#define ROBOT_JOEY    "Joey"

//robot intro
char* robot_intro(char *arr)
{
    char user_name[15];
    printf("Hi there! I am a robot and my name is %s !", ROBOT_JOEY);
    puts("I can do some differen actions and execute your commands.");
    printf("But first of all, plese, tell me your name, master : ");
    fgets(user_name, sizeof(user_name), stdin);
    *arr = user_name;
    

    return *arr;
}
