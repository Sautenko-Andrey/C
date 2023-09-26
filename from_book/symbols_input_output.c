//Символьный ввод-вывод fgetc() , fgets()
#include<stdio.h>
#include<stdlib.h>

#define MAX 25
#define MAX_CLUBS 7
#define MAX_SYMBOLS 26


void read_file(char *file_name);
void read_clubs(char *file_name);
void read_symbol(char *file_name);
void read_all_symbols(char *file_name);


int main(void)
{   
    read_file("clubs.txt");
    read_clubs("clubs.txt");
    read_symbol("alphabet.txt");
    read_all_symbols("alphabet.txt");

    
    return 0;
}

void read_file(char *file_name)
{
    FILE *file_ptr;
    char club[MAX];

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Error with opening file.");
        exit(1);
    }

    fgets(club, MAX, file_ptr);
    fclose(file_ptr);

    putchar('\n');
    puts(club);
}

void read_clubs(char *file_name)
{   
    FILE *file_ptr;
    char *all_clubs[MAX_CLUBS];

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Got error while opening!");
        exit(1);
    }

    for(int i = 0; i < MAX_CLUBS; ++i){
        all_clubs[i] = malloc(sizeof(char) * MAX);
        fgets(all_clubs[i], MAX, file_ptr);
    }
    fclose(file_ptr);
    
    for(int i = 0; i < MAX_CLUBS; ++i){
        printf("Club: %s\n", all_clubs[i]);
    }

}

void read_symbol(char *file_name)
{
    FILE *file_ptr;
    char symbol;
    
    if( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Error while opening!");
        exit(1);
    }

    symbol = fgetc(file_ptr);
    fclose(file_ptr);

    printf("We've got symbol < %c >\n", symbol);

}

void read_all_symbols(char *file_name)
{
    FILE *file_ptr;

    char symbols[255];

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Error with opening file!");
        exit(1);
    }

    for(int i = 0; i < 255; ++i){
        //fgets((symbols + i), 255, file_ptr);
        symbols[i] = fgetc(file_ptr);
    }
    fclose(file_ptr);

    for (int i = 0; i < MAX_SYMBOLS; ++i){
        printf("Symbol: < %c >\n", symbols[i]);
    }
}
