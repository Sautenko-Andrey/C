//Форматированный ввод fscanf()
#include<stdio.h>
#include<stdlib.h>

#define MAX_DIGS    6


void read_data_from_file(char *file_name);
void one_read_data(char *file_name);
void read_data_cycle(char *file_name);

int main(void)
{   
    read_data_from_file("salary.txt");

    one_read_data("salary.txt");

    read_data_cycle("salary.txt");


    return 0;
}

void read_data_from_file(char *file_name)
{
    //объявляем указатель на структуру FILE
    FILE *file_ptr;

    //создаем переменные для чисел
    float dig1, dig2, dig3, dig4, dig5, dig6;

    //открываем файл на чтение
    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Opening file error!");
        exit(1);
    }

    fscanf(file_ptr, "%f %f %f %f %f %f", &dig1, &dig2, &dig3, &dig4, &dig5, &dig6);

    //выведем на экран то, что прочитали из файла
    printf("Sallarys: %.2f, %.2f,%.2f,%.2f,%.2f,%.2f\n",\
dig1, dig2,dig3, dig4, dig5, dig6);

    fclose(file_ptr);

}

void one_read_data(char *file_name)
{
    //объяляем указатель на структуру FILE
    FILE *f_ptr;

    //объявляем переменную типа float
    float num;

    //открываем файл
    if ( (f_ptr = fopen(file_name, "r")) == NULL ){
        puts("Opening file error!");
        exit(1);
    }

    fscanf(f_ptr, "%f", &num);

    //печатаем прочитанное число
    printf("We got : %.2f\n", num);

    //закрываем файл
    fclose(f_ptr);
}

void read_data_cycle(char *file_name)
{
    FILE *file_ptr;

    float number[MAX_DIGS];
    float *p_number = number;

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        puts("Error!");
        exit(1);
    }

    for (int i = 0; i < MAX_DIGS; ++i){
        fscanf(file_ptr, "%f", (p_number + i));
    }

    fclose(file_ptr);

    for (int i = 0; i < 6; ++i){
        printf("#%d sallary = %.2f usd\n", i + 1, number[i]);
    }

}