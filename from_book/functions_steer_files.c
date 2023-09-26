//Функции управления файлами. Копирование файлов, переименование и удаление.

#include<stdio.h>
#include<stdlib.h>

void delete_file(char *file_name);
void rename_file(char *file_old_name, char *file_new_name);
void file_copy(char *orig_file_name, char *copy_file_name);


int main(void)
{   
    //удаление файлов
    delete_file("alphabet.txt");
    delete_file("arsenal.txt");
    delete_file("clubs.txt");


    //переименование файлов
    rename_file("data.txt", "data_Andrey.txt");

    //копирование файлов
    file_copy("EPL_clubs.txt", "EPL_clubs_2.txt");


    return 0;
}

void delete_file(char *file_name)
{
    if ( (remove(file_name)) == 0 ){
        printf("File %s has been deleted!\n", file_name);
    }
    else{
        fprintf(stderr, "I can't delete this file %s!\n", file_name);
    }
}

void rename_file(char *file_old_name, char *file_new_name)
{
    if ( rename(file_old_name, file_new_name) == 0 ){
        printf("File has been successfuly renamed!\n");
    }
    else{
        fprintf(stderr, "I can't rename file %s!\n", file_old_name);
    }
}

void file_copy(char *orig_file_name, char *copy_file_name)
{   
    char byte;

    //откроем файл на чтение, который хотим скопировать
    FILE *file_ptr_orig;
    if ( (file_ptr_orig = fopen(orig_file_name, "rb")) == NULL ){
        fprintf(stderr, "Error opening file %s\n", orig_file_name);
        exit(1);
    }

    //откроем файл на запись, в который хотим скопировать информацию
    FILE *file_ptr_copy;
    if ( (file_ptr_copy = fopen(copy_file_name, "wb")) == NULL ){
        fprintf(stderr, "Error opening file %s\n", copy_file_name);
        exit(1);
    }

    //если открытие файлов прошло без ошибок, мы побайтно копируем информацию
    while ( !feof(file_ptr_orig)){
        byte = fgetc(file_ptr_orig);
        fputc(byte, file_ptr_copy);
    }

    fclose(file_ptr_orig);
    fclose(file_ptr_copy);

    printf("File %s has been successfully copied!\n", orig_file_name);
}