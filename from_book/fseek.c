//функция fseek() - с помощью нее можно установить указатель позиции в любое место
#include<stdio.h>
#include<stdlib.h>


//в данном коде ф-я fseek() используется для произвольного доступа к файлу

#define MAX 50

void read_particular_element(char *file_name, long element_position);


int main(void)
{   
    FILE *file_pointer;

    int array[MAX];
    long offset;
    int number;

    //инициализация массива array
    for (int i = 0; i < MAX; ++i){
        array[i] = i * 10;
    }

    //открытие двоичного файла для записи
    if ( (file_pointer = fopen("random.dat", "wb")) == NULL ){
        fprintf(stderr, "Error with opening file!");
        exit(1);
    }

    //запись массива в файл и закрытие
    if (fwrite(array, sizeof(int), MAX, file_pointer) != MAX){
        fprintf(stderr, "Error with weriting data into file!");
        exit(1);
    }

    //закрываем поток
    fclose(file_pointer);

    //открытие файла для чтения
    if ( (file_pointer = fopen("random.dat", "rb")) == NULL ){
        fprintf(stderr, "Error with opening file!");
        exit(1);
    }

    //спрашиваем пользователя какой элемент выводить
    while(1){
        printf("Enter element to read [0 - %d] or -1 to quit:", MAX - 1);
        scanf("%ld", &offset);

        if(offset < 0){
            break;
        }
        else if(offset > (MAX - 1)){
            continue;
        }

        //перемещение указателя позиции к заданному элементу
        if ( (fseek(file_pointer, (offset * sizeof(long)), SEEK_SET)) !=0 ){
            fprintf(stderr, "Error using fseek()");
            exit(1);
        }

        //чтение указанного числа
        fread(&number, sizeof(int), 1, file_pointer);

        //печатаем ,что получили
        printf("We have got element %ld --->  %d \n", offset, number);

    }

    return 0;
}

void read_particular_element(char *file_name, long element_position)
{
    
}