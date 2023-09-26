#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{   
    char *strings[3];

    //strings[0] = "aaaaa";
    //strings[1] = "bbbbbb";
    //strings[2] = "ccc";

    char text[50];
    for (int i = 0; i < 3; ++i){
        fgets(text, 49, stdin);
    }

    printf("%s\n", text);

    for(int i = 0; i < 3; ++i){
        printf("%s\n", strings[i]);
    }

    return 0;
}