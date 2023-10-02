#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ALPHABET 26
#define MAX_REMINDS 50
#define MSG_LEN 60

int read_line(char text[], int len);

void printf_alphabet(unsigned char letter_amount);

int main(void)
{   
    //strcmp
    char name_1[10] = "Rick";
    char name_2[10] = "Rocky";

    int comp_res = strcmp(name_1, name_2);

    if(comp_res < 0){
        puts("name_1 < name_2");
    }
    else if(comp_res == 0){
        puts("name_1 == name_2");
    }
    else{
        puts("name_1 > name_2");
    }

    printf_alphabet(26);


    return 0;
}

void printf_alphabet(unsigned char letter_amount)
{   
    int start = 97;

    if(letter_amount > MAX_ALPHABET){
        fprintf(stderr, "26 letters in eng alphabet.\n");
        exit(1);
    }

    for(int i = 0; i < letter_amount; ++i){
        printf("%c ", start + i);
    }
    putchar('\n');
}

int read_line(char text[], int len)
{
    int symbol, i = 0;

    while((symbol = getchar()) != '\n'){
        if(i < len){
            text[i++] = symbol;
        }
        text[i] = '\0'; 
    }

    return i;
}