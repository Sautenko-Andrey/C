//Массивы структур

#include<stdio.h>
#include<stdlib.h>

#define AMOUNT  5


struct phone_user
{
    char name[30];
    char phone[15];
};

struct employee
{
    char name[30];
    char phone[15];
    short id;
};

typedef struct phone_user PHONE;
typedef struct employee EMP;

void new_employees(void);

int main(void)
{   
    //объявим массив структур для телефонной книги из 10 человек
    PHONE phone_book[10] = {
        {"Andrey", "+380950180611"},
        {"Ivan", "+380509997814"}
    };

    //посмотрим что получилось
    for (int i = 0; i < 10; ++i){
        printf("%s : %s\n", phone_book[i].name, phone_book[i].phone);
    }


    //new_employees
    new_employees();

    
    return 0;
}

void new_employees(void)
{
    EMP all_employees[AMOUNT];

    for(int i = 0; i < AMOUNT; ++i){
        printf("Enter employee's name, phone and id using spaces: ");
        scanf("%s %s %d", all_employees[i].name, all_employees[i].phone, &all_employees[i].id);
    }

    puts("All employees in developers team:");
    printf("__________________________________\n");
    for(int i = 0; i < AMOUNT; ++i){
        printf("Name: %s\nPhone: %s\nID: %d\n_______________________\n",\
        all_employees[i].name, all_employees[i].phone, all_employees[i].id);
    } 
}