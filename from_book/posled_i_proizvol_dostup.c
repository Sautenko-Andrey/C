//послежовательный и произвольный доступ
//ftell(), rewind()

#include<stdio.h>
#include<stdlib.h>


void write_n_read_data(char *file_name, char *user_text);

#define BUFLEN 6

int main(void)
{
    //rewind() - используется для установки указателя позиции на начало файла (байт номер 0)

    //ftell() - для определения положения указателя позиции в файле

    //объявим перменную, содержащую весь алфавит
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    //объявим переменную для буфера
    char buffer[BUFLEN];

    //объявляем указатель на структуру FILE
    FILE *file_ptr;

    //открываем файл на запись
    if ( (file_ptr = fopen("alphabet.txt", "w")) == NULL ){
        fprintf(stderr, "Opening error!");
        exit(1);
    }

    //записываем строку в файл
    if (fputs(alphabet, file_ptr) == EOF){
        fprintf(stderr, "Error wriitting to file!");
        exit(1);
    }
    
    fclose(file_ptr);

    //открытие файла для чтения
    if ( (file_ptr = fopen("alphabet.txt", "r")) == NULL ){
        fprintf(stderr, "Error while reading!");
        exit(1);
    }

    //выводим на экран позицию указателя позиции
    printf("at this moment position is %ld\n", ftell(file_ptr));

    //считывание  символов из открытого файла в переменную buffer
    fgets(buffer, BUFLEN, file_ptr);

    printf("After reading in %s , position = %ld\n", buffer, ftell(file_ptr));

    //считывание следующих пяти символов
    fgets(buffer, BUFLEN, file_ptr);
    printf("The next 5 characters are %s, and position now is %ld\n", buffer, ftell(file_ptr));

    //вернемся в начало потока
    rewind(file_ptr);

    printf("After rewinding theposition is %ld\n", ftell(file_ptr));

    //снова считаем пять символов
    fgets(buffer, BUFLEN, file_ptr);
    printf("And finally we have read %s and position is %ld\n", buffer, ftell(file_ptr));

    //закрываем поток
    fclose(file_ptr);



    //воспользуемся нашей функцией
    write_n_read_data("experiment.txt", "This is just an experiment.");

    return 0;
}

void write_n_read_data(char *file_name, char *user_text)
{
    FILE *file_pointer;

    char buffer[10];

    //открываем файл на запись
    if ( (file_pointer = fopen(file_name, "w")) == NULL ){
        puts("Error while opening file!");
        exit(1);
    }

    //записываем информацию в файл
    if( fputs(user_text, file_pointer) == EOF ){
        puts("Error writing data!");
        exit(1);
    }

    //закрываем поток
    fclose(file_pointer);

    //открываем этот же файл на чтение
    if ( (file_pointer = fopen(file_name, "r")) == NULL ){
        puts("Error opening file fore reading!");
        exit(1);
    }

    //смотрим где находится указатель позиции
    printf("Указатель позиции стоит в индексе %ld\n", ftell(file_pointer));

    //читаем данные из файла в буфер
    fgets(buffer, 10, file_pointer);

    //смотрим где теперь находится указатель позиции
    printf("После чтения указатель позиции стоит в индексе %ld\n", ftell(file_pointer));

    //возвращаем указатель позиции в начало
    rewind(file_pointer);

    //проверям ,что указатель позиции стоит в начале
    printf("Указатель позиции должен стоять в 0, стоит в %ld\n", ftell(file_pointer));

    //снова прочитаем первые 10 символов
    fgets(buffer, 10, file_pointer);

    //помотрим где находится указатель позиции
    printf("Указатель находится в %ld\n", ftell(file_pointer));

    //закрываем поток
    fclose(file_pointer);
}