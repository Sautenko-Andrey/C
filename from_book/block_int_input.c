//блочный ввод-вывод fread() , fwrite()
#include<stdio.h>
#include<stdlib.h>

#define SIZE 20


int main(void)
{   
    //объявим два массива типа int
    int array_1[SIZE], array_2[SIZE];

    //объявим указатель на сруктуру FILE
    FILE *file_ptr;

    //инициализируем первый массив
    for(int i = 0; i < SIZE; ++i){
        array_1[i] = 2 * i;
    }

    //открытие файла в двоичном режиме
    if ( (file_ptr = fopen("dirext.txt", "wb")) == NULL ){
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    //сохранение массива array_1 в файле
    if (fwrite(array_1, sizeof(int), SIZE, file_ptr) != SIZE){
        fprintf(stderr, "Error reading file!");
        exit(1);
    }

    //закрытие файла
    fclose(file_ptr);

    //открытие того же файла для чтения в двоичном режиме
    if ( (file_ptr = fopen("dirext.txt", "rb")) == NULL ){
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    //тпереь считаем данные из файла в массив array_2
    if (fread(array_2, sizeof(int), SIZE, file_ptr) != SIZE){
        fprintf(stderr, "Error reading file!");
        exit(1);
    }

    //закрываем файл
    fclose(file_ptr);

    //вывод обоих массивов , чтобы показать, что они идентичны
    for (int i = 0; i < SIZE; ++i){
        printf("%d\t%d\n", array_1[i], array_2[i]);
    }

    return 0;
}