#include<stdio.h>
#include<string.h>

#define NEXT putchar('\n')

int main(int argc, char *argv[])
{   
    char *friends[] = {
        "Chandler","Joey","Ross",
        "Monika","Phibs","Rachel"
    };

    for(int i = 0; i < sizeof(friends) / sizeof(*friends); ++i){
        printf("%s\n", friends[i]);
    }
    NEXT;

    //get names which start with R
    for(int i = 0; i < sizeof(friends) / sizeof(*friends); ++i){
        if(friends[i][0] == 'R'){
            printf("%s\n",friends[i]);
        }
    }
    NEXT;

    for(int i = 1; i < argc; ++i){
        printf("%s\n", argv[i]);
    }



    return 0;
}