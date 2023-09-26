//Запись и чтение данных (работа с файлами)

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void clear(void);
void make_file_with_data(void);


int main(void)
{   
    //let's try to open file for reading
    FILE *file_ptr;
    if ( (file_ptr = fopen("../../data.txt", "r")) != NULL ){
        puts("File is successfuly opened!");
        fclose(file_ptr);
    }
    else{
        puts("Got error when was trying ti open file.Sorry!");
    }


    //Форматированный вывод fprintf()

    //создади указатель на структуру файла
    FILE *f_ptr;

    //создадим массив из  5 элементов типа float
    float data[5];

    //имя файла
    char filename[20];

    //режим
    char mode[2] = "w";

    puts("Enter five floating-point numerical values : ");

    //через цикл добавляем данные в массив
    for(int i = 0; i < 5; ++i){
        scanf("%f", &data[i]);
    }

    //очищаем поток stdin от всего лишнего (на всякий случай)
    clear();

    //ввод имени файла и его открытие
    printf("Enter file's name: ");
    fgets(filename, 20, stdin);
    filename[strlen(filename) - 1] = '\0';

    //делаем проверку того, что файл открылся
    if ( (f_ptr = fopen(filename, mode)) == NULL ){
        fprintf(stderr, "Error opening file %s.", filename);
        exit(1);
    }

    //запись числовой информации в файл и поток stdout
    for(int i = 0; i < 5; ++i){
        fprintf(f_ptr, "data[%d] = %.2f\n", i, data[i]);
        fprintf(stdout, "data[%d] = %.2f\n", i, data[i]);
    }

    //закрываем файл
    fclose(f_ptr);

    putchar('\n');


    //опробуем нашу новую функцию
    make_file_with_data();

    return 0;
}

void clear(void)
{
    char trash[256];
    fgets(trash, 256, stdin);
}

void make_file_with_data(void)
{
    //создадим указатель на структуру FILE
    FILE *file_ptr;

    //создадим строку
    char string[80];;

    //добавим инфу в массив строк
    for(int i = 0; i < 4; ++i){
        printf("Enter a text here: ");
        fgets(string, 79, stdin);
        string[strlen(string) - 1] = '\0';
    }

    //чистим поток stdin
    clear();

    //откроем файл на запись и сделаем проверку
    if ( (file_ptr = fopen("text_data.txt", "w")) == NULL ){
        puts("Error with file openinng!");
        exit(1);
    }

    puts("File was opened successfuly!");

    //делаем запись если все ок
    for(int i = 0; i < 3; ++i){
        fprintf(file_ptr, "%s\n", string);
        fprintf(stdout, "%s\n", string);
    }

    //закрываем файл
    fclose(file_ptr);
}