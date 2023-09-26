//Подсчет символов в текстовом файле
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int count_symbols(char *file_name);
void copy_file(char *orig_file_name, char *copy_file_name);


int main(void)
{   
    //подсчитаем количесво символов в текстовом файле
    int symbols = count_symbols("/home/andrey/grocery_data/ALL_TEXT_VARIANTS/coconut.txt");
    printf("Symbols: %d\n", symbols);


    //скопируем файл с заменой символов
    copy_file("EPL_clubs.txt", "EPL_clubsUP.txt");

    return 0;
}

int count_symbols(char *file_name)
{   
    //переменная-счетчик
    int count = 0;
    char buffer;

    //откроем файл на чтение
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    while ( feof(file_ptr) == 0 ){
        buffer = fgetc(file_ptr);
        //игнорируем перенос строки и символ конца файла
        if (buffer == '\n' || buffer == EOF){
            continue;
        }
        count++;
    }

    return count;
}

void copy_file(char *orig_file_name, char *copy_file_name)
{   
    char one_symbol;

    //откроем существующий файл на чтение
    FILE *file_orig_ptr;
    if ( (file_orig_ptr = fopen(orig_file_name, "r")) == NULL ){
        fprintf(stderr, "I can't open original file!");
        exit(1);
    }

    //откроем/создадим новый файл-копию
    FILE *file_copy_ptr;
    if ( (file_copy_ptr = fopen(copy_file_name, "w")) == NULL ){
        fprintf(stderr, "I can't open/create new file!");
        exit(1);
    }

    //скопируем посимвольно все ,при этом символы в нижнем регистре сделаем символами
    //верхнего регистра
    while(feof(file_orig_ptr) == 0){
        one_symbol = fgetc(file_orig_ptr);
        
        if (tolower(one_symbol)){
            one_symbol = toupper(one_symbol);
        }

        fputc(one_symbol, file_copy_ptr);
    }

    fclose(file_orig_ptr);
    fclose(file_copy_ptr);
}