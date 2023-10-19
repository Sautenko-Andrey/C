#include<stdio.h>

#define MAX 20
#define LEN 20

int read_char(void);
void read_word(char *word, int len);


int main(void)
{   
    char my_word[MAX + 2];

    read_word(my_word, LEN);


    return 0;
}

int read_char(void)
{
    int symbol = getchar();
    if (symbol == '\n' || symbol == '\t'){
        return ' ';
    }
    return symbol;
}

void read_word(char *word, int len)
{
    int symbol;
    int position = 0;

    while( (symbol = read_char()) == ' ' ){
        puts("While works!");
        ;
    }
    while ( symbol != ' ' && symbol != EOF ){
        if(position < len){
            word[position++] = symbol;
        }
        symbol = read_char();
    }

    word[position] = '\0';
    puts(word);
}