#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define NL '\n'

int main(void)
{   
    char symbol = 'a';

    for (int i = 0; i < 26; ++i){
        printf("%c ", symbol++);
    }
    puts("");

    printf("New line%c", NL);

    char text[] = "I love Arsenal and prefer european chicks.";
    puts(text);
    for(int i = 0; i < strlen(text) - 1; ++i){
        if (text[i] >= 'a' && text[i] <= 'z'){
            text[i] = toupper(text[i]);
        } 
    }

    puts(text);

    

    return 0;
}