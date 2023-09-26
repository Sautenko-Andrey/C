//Выполнение команд ОС

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *command = "ls -l ../../";
    system(command);
    puts("____________________________________________________");
    char *next_command = "ls -l ../../grocery_data/ALL_TEXT_VARIANTS | grep beer";
    puts("____________________________________________________");
    system(next_command);
    putchar('\n');


    
    return 0;
}