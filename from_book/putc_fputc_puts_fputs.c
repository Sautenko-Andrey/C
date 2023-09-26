//Функции символьного вывода putc, fputc, puts, fputs
#include<stdio.h>
#include<stdlib.h>


void write_symbol_into_file(char *file_name);
void write_symb_fputc(char *file_name);
void write_text(char *file_name);
void clear(void);



int main(void)
{   
    //начнем с putc()
    write_symbol_into_file("one_symbol.txt");

    //fputc
    write_symb_fputc("one_symbol.txt");

    //fputs
    write_text("one_symbol.txt");


    return 0;
}

void write_symbol_into_file(char *file_name)
{   
    /*Запись одного символа в файл*/

    FILE *file_ptr;
    char symbol = 'A';

    if ( (file_ptr = fopen(file_name, "w")) == NULL ){
        puts("Error with opening file!");
        exit(1);
    }

    //заносим символ в файл
    putc(symbol, file_ptr);

    //закрываем файл
    fclose(file_ptr);

    //выведем этот символ в консоль
    fprintf(stdout, "sumbol = %c\n", symbol);
}

void write_symb_fputc(char *file_name)
{
    FILE *file_ptr;
    char symbol = 'Y';

    if ( (file_ptr = fopen(file_name, "w")) == NULL ){
        puts("Error with openning file");
        exit(1);
    }

    //заносим символ в файл
    fputc(symbol, file_ptr);

    fclose(file_ptr);
}

void write_text(char *file_name)
{
    FILE *file_ptr;

    //char text[50];
    char *text = malloc(sizeof(char) * 100);

    if ( (file_ptr = fopen(file_name, "w")) == NULL ){
        puts("Error with openning file");
        exit(1);
    }

    printf("Enter a text: ");
    fgets(text, 99, stdin);
    
    fputs(text, file_ptr);
    //clear();
    fclose(file_ptr);
}

void clear(void)
{
    char trash[255];
    fgets(trash, 255, stdin);
}