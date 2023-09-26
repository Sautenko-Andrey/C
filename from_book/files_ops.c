//повторение работы с файлами
#include<stdio.h>
#include<stdlib.h>

//for write and read symbols
void write_symbol(char *file_name, char symbol);
void read_symbol(char *file_name, char *ptr_symbol);


//for write and read strings
void write_str(char *file_name, char *text);
void read_str(char *file_name, char *text);

//for read and write blocks
void write_array(char *file_name, float array[], size_t len_array);
void read_array(char *file_name, float array[], size_t len_array);

//for moving position pointer
void move_to(int steps, char *file_name);



int main(void)
{
    //testing write_symbol
    write_symbol("symbol_A.txt", 'A');

    //testing read_symbol
    char my_symbol;
    read_symbol("symbol_A.txt", &my_symbol);
    printf("My symbol: %c\n", my_symbol);

    //testing write_str
    char my_text[] = "I prefer to get away form here to the EU!";
    write_str("europe.txt", my_text);

    //testing read_str
    char *my_string = malloc(sizeof(char) * 100);
    read_str("europe.txt", my_string);
    puts(my_string);


    //testing write_array
    float prices[] = {100.00, 52.36, 78.99, 400.01, 99.00};
    size_t len = sizeof(prices) / sizeof(*prices);
    write_array("item_prices.dat", prices, len);

    //testing read_array
    float my_prices[5];
    read_array("item_prices.dat", my_prices, 5); 
    //display result
    for(int i = 0; i < 5; ++i){
        printf("%.2f ", my_prices[i]);
    }
    putchar('\n');

    //testin move_to
    move_to(1,"symbol_A.txt");


    return 0;
}

void write_symbol(char *file_name, char symbol)
{
    //откроем файл на запись
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "w")) == NULL ){
        fprintf(stderr, "Error with opening file for writing one symbol!");
        exit(1);
    }

    //записываем символ в файл
    if ( fputc(symbol, file_ptr) == EOF ){
        fprintf(stderr,"Error writiing ine symbol in file via fputc()!");
        exit(1);
    }

    //попробуем сделать запись через цикл
    for (int i = 0; i < 5; ++i){
        if ( fputc(++symbol, file_ptr) == EOF ){
        fprintf(stderr,"Error writiing ine symbol in file via fputc() in the loop!");
        exit(1);
        }
    }

    fclose(file_ptr);
}

void read_symbol(char *file_name, char *ptr_symbol)
{
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        fprintf(stderr, "Error opening file for read one symbol!");
        exit(1);
    }

    *ptr_symbol = fgetc(file_ptr);

    //посмотрим позицию позиционного указателя
    printf("pos = %ld\n", ftell(file_ptr));


    //попробуем прочитать через цикл
    for(int i = 0; i < 3; ++i){
        *ptr_symbol = fgetc(file_ptr);
        printf("Symbol = %c\n", *ptr_symbol);
        //посмотрим позицию позиционного указателя
        printf("pos = %ld\n", ftell(file_ptr));
    }

    fclose(file_ptr);
}

void write_str(char *file_name, char *text)
{
    //открываем файл на запись
    FILE *file_ptr;
    if ( (file_ptr = fopen(file_name, "w")) == NULL ){
        fprintf(stderr, "Error with opening file for writing text!");
        exit(1);
    }

    //записываем текст в файл
    fputs(text,file_ptr);

    fclose(file_ptr);
}

void read_str(char *file_name, char *text)
{
    FILE *file_ptr;
    if( (file_ptr = fopen(file_name, "r")) == NULL ){
        fprintf(stderr, "Error reading text!");
        exit(1);
    }

    //читаем данные из файла в переменную text
    fgets(text, 50, file_ptr);

    fclose(file_ptr);
}

void write_array(char *file_name, float array[], size_t len_array)
{
    FILE *file_ptr;
    if( (file_ptr = fopen(file_name, "wb")) == NULL ){
        fprintf(stderr, "Error opening file for writing data block!");
        exit(1);
    }

    if ( fwrite(array, sizeof(float), len_array, file_ptr) != len_array ){
        fprintf(stderr, "Error writing data to the file!");
        exit(1);
    }

    fclose(file_ptr);
}

void read_array(char *file_name, float array[], size_t len_array)
{
    FILE *file_ptr;
    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Error opening file for reading data block from file!");
        exit(1);
    }

    if ( (fread(array, sizeof(float), len_array,file_ptr)) != len_array ){
        fprintf(stderr, "Error reading block data!");
        exit(1);
    }

    fclose(file_ptr);
}

void move_to(int steps, char *file_name)
{
    FILE *file_ptr;
    if( (file_ptr = fopen(file_name, "r")) == NULL ){
        fprintf(stderr,"Error!");
        exit(1);
    }

    //посмотрим начальное положение позиционного указателя
    printf("Starting pos is %ld\n", ftell(file_ptr));

    //перемещение указателя к заданной позиции (сместимся на 3 позиции)
    if ( (fseek(file_ptr, sizeof(char) * steps, SEEK_SET)) != 0){
        fprintf(stderr, "I can't move position pointer!");
        exit(1);
    }

    //выводим элемент на экран
    char element = fgetc(file_ptr);
    printf("Element is %c\n", element);

    //посмотрим текущую позицию позиционного указателя
    printf("Current pos is %ld\n", ftell(file_ptr));


    //вернем позиционный указатель а начало
    rewind(file_ptr);

    //посмотрим его значение
    printf("pos is %ld\n", ftell(file_ptr));

    fclose(file_ptr);
    
}