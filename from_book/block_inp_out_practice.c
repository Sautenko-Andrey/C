//блочный ввод - вывод fwrite() fread()
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct friend{
    char *name;
    char *phone_number;
};

typedef struct friend FRIEND;

void write_to_file(char *file_name, void *ptr);
void read_from_file(char *file_name);
void universal_read_from_file(char *file_name, void *buff, size_t size, size_t count);
void universal_write_to_file(char *file_name, void *from_buff, size_t size, size_t count);

int main(void)
{   
    //объявим массив структур FRIEND
    FRIEND my_friends[SIZE] = {
        {"Alex", "+380664563214"},
        {"Danil", "+380504571235"},
        {"Yuriy", "+380974511454"},
        {"Radik", "+380639897412"},
        {"Chaus", "+380957899874"}
    };

    //запишем этот массив в файл
    write_to_file("friends.txt",my_friends);

    //прочитаем данные из файла и выведем их на экран
    read_from_file("friends.txt");

    //попробуем прочитать данные универсальной функцией
    FRIEND my_new_friends[SIZE];
    universal_read_from_file("friends.txt", my_new_friends, sizeof(FRIEND),SIZE);

    //посмотрим как прочитались данные и поместились ли в массив
    for(int i = 0; i < SIZE; ++i){
        printf("%s------%s\n", my_new_friends[i].name, my_new_friends[i].phone_number);
    }

    //попробуем что-то записать с помощью новой функции
    char *clubs[SIZE] = {"Arsenal", "Chelsea", "Man City", "Liverpool", "West Ham"};
    universal_write_to_file("epl_clubs.txt", clubs, sizeof(clubs), SIZE);

    //попробуем прочитать данные из файла epl_clubs.txt
    char *new_clubs[SIZE];
    universal_read_from_file("epl_clubs.txt", new_clubs, sizeof(new_clubs), SIZE);
    //посмотрим как прочитались данные и поместились ли в массив
    for(int i = 0; i < SIZE; ++i){
        printf("Club: %s\n", new_clubs[i]);
    }

    return 0;
}

void write_to_file(char *file_name, void *ptr)
{
    //объявим указатель на структуру FILE
    FILE *file_ptr;

    //открываем файл на запись
    if ( (file_ptr = fopen(file_name, "wb")) == NULL ){
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    //записываем данные в файл
    if (fwrite(ptr, sizeof(FRIEND), SIZE, file_ptr) != SIZE){
        fprintf(stderr, "Error writing data!");
        exit(1);
    }

    //закрываем файл
    fclose(file_ptr);
}

void read_from_file(char *file_name)
{
    //объявим указатель на структуру FILe
    FILE *file_ptr;

    //объявим массив структур
    FRIEND array[SIZE];

    //открываем файл на чтение
    if( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    //читаем данные из файла
    if (fread(array, sizeof(FRIEND), SIZE, file_ptr) != SIZE){
        fprintf(stderr, "Reading error!");
        exit(1);
    }

    fclose(file_ptr);

    puts("________________________");
    //выводим на экран то, что прочитали из файла
    for ( int i = 0; i < SIZE; ++i ){
        fprintf(stdout, "Name: %s\nTel: %s\n___________\n", array[i].name,array[i].phone_number);
    }
}

void universal_read_from_file(char *file_name, void *buff, size_t size, size_t count)
{
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Opening error!");
        exit(1);
    }

    if (fread(buff, size, count, file_ptr) != count){
        fprintf(stderr, "Reading error in read_from_file!");
        exit(1);
    }

    fclose(file_ptr);
}

void universal_write_to_file(char *file_name, void *from_buff, size_t size, size_t count)
{
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "wb")) == NULL){
        fprintf(stderr, "Opening file error!");
        exit(1);
    }

    if (fwrite(from_buff, size, count, file_ptr) != count){
        fprintf(stderr, "Writting error!");
        exit(1);
    }

    fclose(file_ptr);
}