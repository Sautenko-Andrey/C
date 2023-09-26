//Форматированный ввол и вывод (работа с файлами)

#include<stdio.h>
#include<stdlib.h>

void say_hello(char file_name[20]);

int main(void)
{   
    char *path = "hello_world.txt";

    say_hello(path);

    return 0;
}

void say_hello(char *file_name)
{   
    FILE *file_ptr;

    //проверяем на успешное открытие файла
    if ( (file_ptr = fopen(file_name, "w")) != NULL ){
        puts("File was successfuly opened!");
    }
    else{
        puts("Error!");
        exit(1);
    }

    //записываем текс в файл
    fprintf(file_ptr, "Hello, World!\n");
    fprintf(stdout, "Hello, World!\n");
    fclose(file_ptr);
}