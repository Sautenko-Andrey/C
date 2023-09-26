//Указателина функции часть 2

//Будем сортировать по алфавиту в обе стороны(по возрастанию и по убыванию)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5

//прототипы функций
int get_lines(char *lines[]);
int alpha(char *str_1, char *str_2);
int reverse(char *str_1, char *str_2);
void print_str(char *strings[], int number);

void sort(char *strings[], int num, int sort_type);

//объявим пока что пустой массив указателей на строки
char *lines[MAX];

int main(void)
{   

    int number_of_lines, sort_type;

    //чтение строк с клавиатуры
    puts("Enter a string: ");
    number_of_lines = get_lines(lines);

    //сделаем проверку корректного выделения памяти
    if (number_of_lines < 0){
        puts("Memory allocation error!");
        exit(-1);
    }

    puts("Enter 0 for reverse order sort or 1 for alphabetical: ");
    scanf("%d", &sort_type);

    sort(lines, MAX, sort_type);
    print_str(lines, MAX);


    return 0;
}

int get_lines(char *lines[])
{
    //временное хранилище для строки
    char buffer[100];

    //счетчик итераций
    int i;

    while((i < MAX) && (fgets(buffer, sizeof(buffer), stdin) != NULL) && (buffer[0] != '\n')){
        if ((lines[i] = malloc(sizeof(char) * (strlen(buffer) + 1))) == NULL){
            return -1;
        }
        strcpy(lines[i++], buffer);
    }

    return i;
}

void sort(char *strings[], int num, int sort_type)
{
    //объявляем временный указатель на строку
    char *temp;

    //объявляем указатель на функцию
    int (*compare)(char *str_1, char *str_2);

    //присваивание указателю нужного адреса на функцию в зависимости от типа сортировки
    compare = (sort_type) ? reverse : alpha;

    for (int i = 0; i < num - 1; ++i){
        for (int j = i + 1; j < num; ++j){
            if (compare(strings[i], strings[j]) > 0){
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int alpha(char *str_1, char *str_2)
{
    //сравнение в алфавитном порядке
    return(strcmp(str_2, str_1));
}

int reverse(char *str_1, char *str_2)
{
    //сравнение в обратном алфавитному порядке
    return (strcmp(str_1, str_2));
}

void print_str(char *strings[], int number)
{
    for (int i = 0; i < number; ++i){
        printf("%s\n", strings[i]);
    }
}