#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10


int main(void)
{   
    srand(time(NULL));

    char command;

    do
    {
        int dig = rand() % MAX + 1;
        printf("%d\n", dig);
        printf("press y to continue: ");
        scanf(" %c", &command);
    } while (command == 'y');
    

    return 0;
}