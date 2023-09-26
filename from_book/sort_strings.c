//программа сортировки строк (моя версия)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct product
{
    char *item_name;
    float prices[9];
};

typedef struct product product;

#define MAX_INPUT   50

int get_lines(char *lines[]);
void sort(char *pointers[], int n);
void print_strings(char *pointers[], int n);
void sort_int(int array[], int len_array);

int main(void)
{   
    //массив указателей на строки
    char *lines[MAX_INPUT];


    //объявим перменную, которая будет хранить количество введенных строк
    int count_strings = get_lines(lines);

    if(count_strings < 0){
        puts("Memory allocation error!");
        exit(-1);
    }

    //сортировка
    sort(lines, count_strings);

    //распечатываем
    print_strings(lines, count_strings);
    

    //объявим перменную на структуру product
    product apple = {
        "Apple Golden",
        {51, 41, 49, 38, 44, 56, 50, 48, 55}
    };

    product *ptr = &apple;
    printf("Item: %s\n", ptr->item_name);
    printf("Price: %.2f\n", apple.prices[0]);
    printf("Price: %.2f uah\n", ptr->prices[0]);
    printf("Adres: %p\n", ptr->prices);
    printf("Adres: %p\n", &apple.prices[0]);


    //объявим еще один массив указателей типа char
    char *friends[5];
    friends[0] = "Alex";
    friends[1] = "Kate";


    return 0;
}

int get_lines(char *lines[])
{
    int n = 0;    //счетчик
    char buffer[80];   //временный буфер на 80  символов

    puts("Enter one line at time; Enter a blank when done.");

    while((n < MAX_INPUT) && (fgets(buffer, sizeof(buffer), stdin) != NULL) && (buffer[0] != '\n')){
        if ((lines[n] = malloc(sizeof(char) * (strlen(buffer) + 1))) == NULL){
            return -1;
        }
        strcpy(lines[n++], buffer);
    }
    return n; //возвращает кол-во занесенных строк
}

void sort(char *pointers[], int n)
{
    char *temp;  //временная переменная

    /*for (int j = 1; j < n; j++){
        for (int i = 0; i < n - 1; ++i){
            if (strcmp(pointers[i], pointers[i + 1]) > 0){
                temp = pointers[i];
                pointers[i] = pointers[i + 1];
                pointers[i + 1] = temp;
            }
        }
    }*/

    for (int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if (strcmp(pointers[i], pointers[j]) > 0){
                temp = pointers[i];
                pointers[i] = pointers[j];
                pointers[j] = temp;
            }
        }
    }
}

void print_strings(char *pointers[], int n)
{
    for(int i = 0; i < n; ++i){
        printf("%s\n", pointers[i]);
    }
}

void sort_int(int array[], int len_array)
{
    int min_index;
    for(int i = 0; i < len_array - 1; ++i){
        min_index = i;
        for(int j = i + 1; j < len_array; ++j){
            if(array[min_index] > array[j]){
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}
