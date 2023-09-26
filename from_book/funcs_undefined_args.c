//ФУНКЦИИ С ПЕРЕМЕННЫМ ЧИСЛОМ АРГУМЕНТОВ (...)
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 55
#define NAME_LEN 30

//создадим структуру телефонной книги
struct book {
    char *name;
    int id;
};
 typedef struct book PHONE_BOOK;

//считает среднее по переданным аргументам
float average(int num, ...);

//печатает на экран все аргументы
void personal_data(int num, ...);

//заносит имена в телефонный справочник (массив) и возвращает этот массив
PHONE_BOOK* make_phonelist(int num, ...);

//для понимания
PHONE_BOOK* create_contacts(int num, ...);

//для массива строк
char* cars(int num, ...);

int main(void)
{   
    //помситаем среднее чисел
    float res = average(5, 100,200,300,400,500);
    printf("Average = %.2f\n", res);    //Average = 300.00

    //выведем на экран всю введенную инфу
    personal_data(3, "Andrey Sautenko", "34 y.o.", "C/C++ developer");

    //заполним телефонную книгу
    PHONE_BOOK *phones = make_phonelist(3, "Max", "Tibo", "Gareth");

    PHONE_BOOK *first_contact = create_contacts(1, "Thierry Henry");
    printf("Contact: %s\n", first_contact->name);
    
    //create_contacs
    PHONE_BOOK *friends_tel = create_contacts(2, "Alexis Sanchez", "Mesut Ozil");
    for(int i = 0; i < 2; ++i){
        printf("%s\n", friends_tel[i].name);
    }


    //cars
    char *car = cars(3, "BMW", "Nissan", "Porshe");
    puts(car);


    

    return 0;
}

float average(int num, ...)
{   
    //объявление переменной типа va_list
    //это указатель для обращения к отдельным аргументам функции
    va_list arg_ptr;

    //инициализация указателя на аргументы
    va_start(arg_ptr, num);

    //получение отдельных аргументов из списка через макрос va_arg()
    int total = 0;
    for(int i = 0; i < num; ++i){
        total += va_arg(arg_ptr, int);
    }

    //очистка ненужных данных
    va_end(arg_ptr);

    //деление суммы total для получения среднего значения
    return ((float)total / num);
}

void personal_data(int num, ...)
{
    //объявление указателя для обращения ко всем аргументам
    va_list ptr_arg;

    //инициализация указателя
    va_start(ptr_arg,num);

    //печать всех данных из списка через макрос va_arg()
    printf("Personal data:\n");
    for(int i = 0; i < num; ++i){
        printf("%s\n", va_arg(ptr_arg, char*));
    }
    va_end(ptr_arg);
}

PHONE_BOOK* make_phonelist(int num, ...)
{
    //объявим массив указателей PHONE_BOOK

    PHONE_BOOK *all_contacts = malloc(sizeof(PHONE_BOOK) * SIZE);

    //объявим указатель на список аргументов
    va_list ptr_arg;

    //инициализируем этот указатель
    va_start(ptr_arg, num);

    for(int i = 0; i < num; ++i){
        all_contacts[i].name = va_arg(ptr_arg, char*);
    }

    va_end(ptr_arg);

    

    return all_contacts;

}

PHONE_BOOK* create_contacts(int num, ...)
{   
    PHONE_BOOK *all_contacts = malloc(sizeof(PHONE_BOOK) * SIZE);
    
    va_list ptr_arg;

    va_start(ptr_arg, num);


    for (int i = 0; i < num; ++i){
        all_contacts[i].name = va_arg(ptr_arg, char*);
    }

    return all_contacts;
}

char* cars(int num, ...)
{
    //выделим память под массив указателей на char
    char *all_cars = malloc((sizeof(char) * NAME_LEN) * SIZE);

    //объявляем указатель на список аргументов
    va_list ptr_args;

    //инициализируем его
    va_start(ptr_args, num);

    //заполняем массив аргументами
    for (int i = 0; i < num; ++i){
        all_cars = va_arg(ptr_args, char*);
    }

    //очищаем
    va_end(ptr_args);

    return all_cars;
}