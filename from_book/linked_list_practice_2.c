//продолжаю закрепеление материала по связанным спискам
#include<stdio.h>
#include<stdlib.h>


struct employee{
    char *name;
    int id;
    struct employee *next;
};

int main(void)
{   
    //объявим начальный указатель который равен нулю
    struct employee *head = NULL;

    //объявим указатель на новый элемент связанного списка
    struct employee *new;

    //выделим память под новый элемент
    new = (struct employee*)malloc(sizeof(struct employee));

    //сделаем проверу выделения памяти
    if (new == NULL){
        puts("Memory allocation error!");
        exit(-1);
    }

    //указатель нового элемента должен указывать на значение начального элемента(на то, что он указывал)
    new->next = head;

    //начальный указатель всегда должен указывать на первый элемент списка
    head = new;

    //создадим элемент в конце
    //объявим указатель на текущий элемент для перебора всех элементов
    struct employee *current;
    //пусть указывает на первый элемент списка
    current = head;

    //делаем перебор
    while(current->next != NULL){
        current = current->next;
    }

    //теперь выделяем память под новый элемент
    struct employee *last = (struct employee*)malloc(sizeof(struct employee));

    //установим указатель в текущем последнем элементе на новый добавленный эл-т
    current->next = last;

    //указатель последнего элемента ссылается на ноль
    last->next = NULL;


    //добавим элемент где-то в середину

    //объявим маркер от которого будет отталкиваться
    struct employee *marker;
    //пусть ссылается на первый элемент
    marker = new;

    //выделяем память под новый элемент
    struct employee *middle = (struct employee*)malloc(sizeof(struct employee));

    //говорим, что указатель нового элемента ссылается на то, на что ссылался марке
    middle->next = marker->next;

    //и что теперь маркер ссылается на этот новый элемент
    marker->next = middle;


    //добавим еще один элемент в середину после миддла

    //меняем адрес маркера
    marker = middle;

    //далее выделяем память под новый элемент
    struct employee *new_middle = (struct employee*)malloc(sizeof(struct employee));

    //теперь говорим,что указатель нового эл-та должен ссылаться на то, что ссылется маркер
    new_middle->next = marker->next;

    //а маркер в свою очередь должен ссылаться на новый элемент
    marker->next = new_middle;


    //наполним информаций элементы
    new->name = "Chaus";
    last->name = "Jarch";
    middle->name = "Andrey";
    new_middle->name = "Danil";

    //теперь посмотрим на структуру связанного списка
    printf("First : %s, adress: %p, pointer: %p\n", new->name, new, new->next);
    printf("Second : %s, adress: %p, pointer: %p\n", middle->name, middle, middle->next);
    printf("Third : %s, adress: %p, pointer: %p\n", new_middle->name, new_middle, new_middle->next);
    printf("Last : %s, adress: %p, pointer: %p\n", last->name, last, last->next);



    //Удаление элемента из списка

    //для удаления первого списка сделаем начальный указатель равным адресу второго элемента
    //и освобождаем память
    //free(head);
    //head = head->next;

    //первый элемент удален

    //для удаления последнего элемента из списка

    //объялем два указателя на структуру
    struct employee *current_1, *current_2;

    //первый будет указывать на начало списка
    current_1 = head;

    //второй будет указывать на следующий элемент после первого
    current_2 = current_1->next;

    //посмотрим на их адреса:
    printf("current_1 : %p, current_2 : %p\n", current_1, current_2);

    //пока current_2 не дойдет до последнего элемента списка выполняем перебор
    while(current_2->next != NULL){
        current_1 = current_2;
        current_2 = current_1->next;
    }

    //как только доходим до конца
    //освобождаем память у последнего элемента
    free(current_1->next);
    current_1->next = NULL;

    //если у элемента был всего один элемент
    if(head == current_1){
        //устанавливаем начальный указатель в ноль
        head = NULL;
    }

    
    

    



    return 0;
}