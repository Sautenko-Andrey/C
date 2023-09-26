//пример простого связанного списка
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//объявим структуру элемента данных списка
struct data {
    char name[20];
    struct data *next;
};

//определение структурного типа и типа указателя на эту структуру
typedef struct data PERSON;
typedef PERSON *LINK;

int main(void)
{   
    //демонстрация основных приемов работы со связанным списком

    //объявим указатели на первый, новый и текущий элементы
    LINK head = NULL;
    LINK new = NULL;
    LINK current = NULL;


    /*Добавление первого элемента в список. Не предпологается, что список пустой, хотя
    в этой просто программе это всегда так.*/

    //выделяем память для нового элемента
    new = (LINK)malloc(sizeof(PERSON));

    //говорим, что новый элемент указыает на то,на что указывает начальный указатель
    new->next = head;

    //говорим, что начальный указатель всегда указывает на первый элемент списка
    head = new;

    //присваиваем имя
    strcpy(new->name, "Andrey");

    /*Добавление элемента в конец списка. Предполагается, что в списке есть хотя бы
    один элемент.*/

    //говорим ,что текущий указатель изначально стоит в начале
    current = head;

    while(current->next != NULL){
        current = current->next;
    }

    //выделяем память под новый элемент
    new = (LINK)malloc(sizeof(PERSON));

    //говорим,что указатель текущего последнего элемента теперь ссылается на на новый элемент
    current->next = new;

    //говорим,что указатель нового элемента ссылается на ноль
    new->next = NULL;
    strcpy(new->name, "Alex");

    /*Добавление элемента во вторую позицию списка*/

    //выделяем память для нового элемента
    new = (LINK)malloc(sizeof(PERSON));

    //скажем,что новый элемент теперь ссылается на то, на что ссылался первый элемент
    new->next = head->next;

    //скажем,что теперь первый элемент теперь ссылается на новый элемент
    head->next = new;

    //присвоим имя
    strcpy(new->name, "Danil");


    /*Добавление элемента в третью позицию списка*/

    //выделяем память для нового элемента
    new = (LINK)malloc(sizeof(PERSON));

    //определяем маркер,который указывает на второй элемент в списке
    LINK marker = head->next;

    //далее говорим,что указатель нового элемента указывает на то,на что указывал указаель второго
    new->next = marker->next;

    //и говорим что второй элемент теперь ссыдается на новый
    marker->next = new;

    //добавляем имя
    strcpy(new->name, "Vika");


    /*Добавление элемента в четвертую позицию через цикл*/
    //установим текущий указатель на начало связанного списка
    current = head;
    for(int i = 0; i < 2; ++i){
        current = current->next;
    }
    //выделяем память под новый элемент
    new = (LINK)malloc(sizeof(PERSON));

    //указатель нового элемента теперь указыает на то,что указывал предшествующий
    new->next = current->next;
    

    //предыдущий элемент должен вести теперь на новый элемент
    current->next = new;

    //добавим имя
    strcpy(new->name, "Ann");


    /*Добавим элемент во вторую позицию*/
    //выделим память под новый элемент
    new = (LINK)malloc(sizeof(PERSON));

    //указатель нового эл-та указывает на то,на что указывал старый второй элемент
    new->next = head->next;

    //первый элемент ведет теперь на этот
    head->next = new;

    //добавим имя
    strcpy(new->name, "Rita");


    /*Добавим элемент в пятую позицию*/
    current = head;
    new = (LINK)malloc(sizeof(PERSON));

    for(int i = 0; i < 3; ++i){
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
    strcpy(new->name, "Oleg");



    /*Добавим элементв четвертую позицию*/
    new = (LINK)malloc(sizeof(PERSON));
    current = head;
    int pos = 4;
    int real_position = pos - 2;

    for(int i = 0; i < real_position; ++i){
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
    strcpy(new->name, "Kristina");


    /*Добавим элемент в самый конец*/
    new = (LINK)malloc(sizeof(PERSON));
    current = head;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = new;
    new->next = NULL;

    strcpy(new->name, "Ivan");



    //Добавим элемент в самое начало списка*/
    new = (LINK)malloc(sizeof(PERSON));
    printf("head adress: %p\n", head);
    new->next = head;
    head = new;
    strcpy(new->name, "Tereshyk");

    /*Добавим элемент во вторую позицию*/
    new = (LINK)malloc(sizeof(PERSON));
    current = head;

    for(int i = 0, pos = 2, position = pos - 2; i < position; ++i){
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
    strcpy(new->name, "Rose Monroe");

    

    /*Вывод всех пунктов по порядку*/
    current = head;
    int i = 1;

    printf("Compare adress: %p --- %p\n", current, current->next);

    while(current != NULL){
        printf("#%d Name: %s, adress: %p, pointer: %p\n", i++, current->name, current, current->next);
        current = current->next;
    }

    printf("head after all : %p\n", head);

    return 0;
}