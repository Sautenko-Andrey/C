//практика ссо всеми операциями для работы с файлами

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

//блочный ввод и  вывод
void write_array_to_file(char *file_name, void *ptr_array, int count);
void read_full_file(char *file_name, void *ptr, int count);

//символьный ввод и вывод
void read_one_symbol(char *file_name, char *symbol);
void write_one_symbol(char *file_name, char symbol);

//ввод и вывод строк
void write_string_to_file(char *file_name, char *string);
void read_string_from_file(char *file_name, char *string, size_t length);


int main(void)
{   
    //объявим и инициализиурем массив int
    int numbers[MAX] = {1,2,3,4,5,6,7,8,9,10};

    //вызовем ф-ю write_array_to_file()
    write_array_to_file("numbers_1_10.txt", numbers, MAX);

    //считаем данные из этого файла и запишем их в новый массив
    int new_numbers[MAX];

    read_full_file("numbers_1_10.txt", new_numbers, MAX);

    //сравним два массива
    for (int i = 0; i < MAX; ++i){
        printf("%d --- %d\n", numbers[i], new_numbers[i]);
    }

    //запишем одиночный символ
    char my_symbol = 'A';
    write_one_symbol("one_number.txt", my_symbol);

    //прочитаем это одиночный символ
    char new_symb;
    read_one_symbol("one_number.txt", &new_symb);
    //посмотрим на прочитанный символ
    printf("That symbol is %c\n", new_symb);


    //запишем строку в файл
    char text[] = "I love football.";
    write_string_to_file("arsenal.txt", text);


    //прочитаем эту строку в переменную
    //char new_text[20];
    char *new_text = malloc(sizeof(char) * 20);
    read_string_from_file("arsenal.txt", new_text, 20);
    puts(new_text);


    return 0;
}

void write_array_to_file(char *file_name, void *ptr_array, int count)
{
    //для записи любого массива в указанный файл

    //открываем файл на запись
    FILE *ptr_file;

    if ( (ptr_file = fopen(file_name, "wb")) == NULL ){
        fprintf(stderr, "Error opening file for writing data!");
        exit(1);
    }

    //записываем весь массив в файл целиком
    if (fwrite(ptr_array, sizeof(int), count, ptr_file) != count){
        fprintf(stderr, "Error writing data via fwrite!");
        exit(1);
    }

    //закроем поток
    fclose(ptr_file);
}

void read_full_file(char *file_name, void *ptr, int count)
{   
    //объявим массив , в который считаем данные из файла
    //int data_array[MAX];

    //откроем файл на чтение
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Error while opening file.");
        exit(1);
    }

    //считываем данные из файла в указанный массив
    if (fread(ptr, sizeof(int), count, file_ptr) != count){
        fprintf(stderr, "Error while reading file via fread()!");
        exit(1);
    }

    //закроем поток
    fclose(file_ptr);
}

void read_one_symbol(char *file_name, char *symbol)
{
    //откроем файл на чтение
    FILE *file_pointer;

    if ( (file_pointer = fopen(file_name, "r")) == NULL ){
        fprintf(stderr,"Error when openning file for reading data.");
        exit(1);
    }

    //читаем данные в переменную
    
   // number = fgetc(file_pointer);
    *symbol = fgetc(file_pointer);

    //закрываем поток
    fclose(file_pointer);
}

void write_one_symbol(char *file_name, char symbol)
{
    FILE *file_pointer;

    if ( (file_pointer = fopen(file_name, "w")) == NULL ){
        fprintf(stderr, "Error when writting one symbol!");
        exit(1);
    }

    fputc(symbol, file_pointer);

    fclose(file_pointer);
}

void write_string_to_file(char *file_name, char *string)
{
    FILE *file_pointer;

    if ( (file_pointer = fopen(file_name, "w")) == NULL ){
        fprintf(stderr, "Error opening file for text!");
        exit(1);
    }

    fputs(string, file_pointer);

    fclose(file_pointer);
}

void read_string_from_file(char *file_name, char *string, size_t length)
{
    FILE *file_pointer;

    if ( (file_pointer = fopen(file_name, "r")) == NULL ){
        fprintf(stderr, "Error trying to read data from file!");
        exit(1);
    }

    fgets(string, length, file_pointer);

    fclose(file_pointer);
}