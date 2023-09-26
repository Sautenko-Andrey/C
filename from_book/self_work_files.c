//Программа открывает заданный текстовый файл и подсчитывает количество раз,
//которое каждый символ встречается в этом файле.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 80

int file_exist(char *file_name);


int main(void)
{   
    char file_name[MAX];
    FILE *file_ptr;
    long count_array[127];
    char symbol;

    //ввод имени файла
    fprintf(stderr, "\nEnter file name: ");
    fgets(file_name, MAX, stdin);
    //убираем символ перевода строки
    file_name[strlen(file_name) - 1] = '\0';

    //проверка существования файла в каталоге
    if (file_exist(file_name) == 0){
        fprintf(stderr, "\nFile %s doesn't exist!", file_name);
        exit(1);
    }
    else{
        puts("File exist!");
    }

    //открываем файл на чтение
    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "I can't open file %s!", file_name);
        exit(1);
    }

    //инициализируем массив нулями
    for (int i = 31; i < 127; i++){
        count_array[i] = 0;
    }

    //начинаем читать текст посимвольно до конца
    while(feof(file_ptr) == 0){
        symbol = fgetc(file_ptr);

        //считаем сиволы только между 32 и 126
        if (symbol > 31 && symbol < 127){
            //увеличиваем соответствующее значение в массиве
            count_array[symbol]++;
        }
    }

    //вывод результатов
    for (int i = 32; i < 127; i++){
        printf("[%c] = %ld\n", i, count_array[i]);
    }

    //закрытие файла
    fclose(file_ptr);

    return 0;
}

int file_exist(char *file_name)
{
    //возвращает True если файл существует, False- если не существует
    
    FILE *file_ptr;
    if( (file_ptr = fopen(file_name, "r")) == NULL ){
        return 0;
    }
    else{
        fclose(file_ptr);
        return 1;
    }
}