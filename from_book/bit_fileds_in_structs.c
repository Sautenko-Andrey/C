//БИТОВЫЕ ПОЛЯ В СТРУКТУРАХ
#include<stdio.h>
#include<stdlib.h>

#define DEPARTMENT_SIZE 3
#define MAN 1    //sex
#define WOMAN 0   //sex
#define MARRIED 1  //status
#define SINGLE 0   //status
#define SIMPLE_ASSURANCE 0   //kind of the assurance
#define NORMALL_ASSURANCE 1   //kind of the assurance
#define FULL_ASSURANCE 2     //kind of the assurance


//объявим структуру с битовыми полями
struct employee {
    unsigned sex :1;
    unsigned status :1;
    unsigned assurance :2;
    char *name;
    char *position;
    unsigned char old;
};

typedef struct employee EMPLOYEE;

int main(void)
{   
    /* Битовое поле - это элемент структуры, состоящий из заданного количества битов.
    Можно экономить память используя их в струтурах, где элемент подразумевает 
    бинарное храннение, то есть да или нет, правда или ложь и т.д.
    Вместо использования char. */

    EMPLOYEE dev_department[DEPARTMENT_SIZE];

    dev_department[0].name = "Andrey Sautenko";
    dev_department[0].old = 34;
    dev_department[0].position = "C/C++ developer";
    dev_department[0].sex = MAN;
    dev_department[0].status = SINGLE;
    dev_department[0].assurance = FULL_ASSURANCE;

    printf("Name: %s\nOld: %d\nPosition: %s\nSex: %d\nStatus: %d\nAssurance: %d\n",\
dev_department[0].name,dev_department[0].old,dev_department[0].position,dev_department[0].sex,\
dev_department[0].status, dev_department[0].assurance);

    return 0;
}