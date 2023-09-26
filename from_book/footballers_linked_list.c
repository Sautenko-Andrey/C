//this is my implementation of linked list for football team data

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define PLAYERS_AMOUNT  5
#define NAME_LEN    25

// define structure of data element
struct footballer{
    char *name;
    char *second_name;
    unsigned char number;
    struct footballer *next;
};

//for the convenience we are defining new types of data and pointer
typedef struct footballer FOOTBALLER;
typedef FOOTBALLER *FOOTB_PTR;

//functions heads
FOOTB_PTR add_to_list(char player_name[], char player_sec_name[],\
unsigned char player_number, FOOTB_PTR head);

void show_footballers(FOOTB_PTR head_pointer);

void free_memory_list(FOOTB_PTR head_pointer);


int main(void)
{   
    //создадим переменную для сбора мусора
    char trash[256];

    //определим начальный указатель
    FOOTB_PTR head = NULL;

    for(int i = 0; i < PLAYERS_AMOUNT; ++i){
        printf("iteration #%d\n", i + 1);
        char name[NAME_LEN] = "0";
        char sec_name[NAME_LEN] = "0";
        unsigned char number = 100;

        while( (!isalpha(name[0])) && (!isalpha(sec_name[0])) && ( number < 1 || number > 99) ){
            printf("Enter player's name and number using spaces: ");
            scanf("%s %s %hhd", name, sec_name, &number);
            fgets(trash, 255, stdin);
        }

        /*далее идет логика добавления нового футболиста в список*/
        head = add_to_list(name, sec_name, number, head);
    }

    show_footballers(head);
    free_memory_list(head);

    return 0;
}

FOOTB_PTR add_to_list(char player_name[], char player_sec_name[],\
unsigned char player_number, FOOTB_PTR head)
{
    //объявляем и инициализируем нулями следующие указатели
    FOOTB_PTR new = NULL;
    FOOTB_PTR temp = NULL;
    FOOTB_PTR previous = NULL;

    //далее выделяем память для новой записи в списке и проверяем корректность
    //выделения памяти из кучи
    new = (FOOTB_PTR)malloc(sizeof(FOOTBALLER));

    if (!new){
        puts("Memory allocation error!");
        exit(1);
    }

    //далее записываем данные в новый элемент списка
    new->name = player_name;
    new->second_name = player_sec_name;
    new->number = player_number;
    new->next = NULL;

    //далее мы определяемся куда именно будет записан новый элемент списка

    //Проверяем ,пустой ли список?
    if(head == NULL){
        //если список пустой, то новый элемент добавляется в начало списка
        //начальный указатель ссылается на новый элемент
        head = new;

        //указатель нового элемента ссылается на ноль
        new->next = NULL;
    }

    //перепишем код!
    else{
        //проверим,не вставлять ли новый элемент перед первым элементом?
        if(new->number < head->number){
            new->next = head;
            head = new;
        }
        else{
            //если нет,то проверяем вставлять в середину или в конец списка
            //для этого прибегнем к помощи дополнительных указателей
            temp = head->next;
            previous = head;

            //теперь анализируем куда вставляется новый элемент

            //если второго элемента нет, то мы вставляем новый элемент в конец списка
            if(temp == NULL){
                previous->next = new;
                new->next = NULL;//не обязательно?
            }
            else{
                //проверяем не вставляется ли новый эл-т в серердину списка
                while(temp->next != NULL){
                    if(new->number < temp->number){
                        new->next = temp;

                        //проверка ошибки
                        if(new->next != previous->next){
                            puts("Error!");
                            exit(1);
                        }
                        previous->next = new;
                        break;
                    }
                    else{
                        //если же номер нового игрока больше номера текущего, мы шагаем дальше
                        temp = temp->next;
                        previous = previous->next;
                    }
                }

                //проверка не вставляется ли новый элемент в конец списка
                if(temp->next == NULL){
                    if(new->number < temp->number){
                        new->next = temp;
                        previous->next = new;
                    }
                    else{
                        temp->next = new;
                        new->next = NULL;
                    }
                }
            }
        }
    }
    return (head);
}

void show_footballers(FOOTB_PTR head_pointer)
{
    //определим текущий указатель для перебора списка
    FOOTB_PTR current = head_pointer;   //начинаем с первого элемента

    //проходим циклом по всему списку и выводим в консоль данные футболистов
    while(current != NULL){
        
        printf("Player: %s %s %hhd %p\n",\
current->name, current->second_name, current->number, current);

        current = current->next;  //шаг вперед
    }

    //второй вариант распечатки
    /*for(int i = 0; i < 5; ++i){
        printf("%s %s %hhd\n", current->name, current->second_name, current->number);
        current = current->next;
    }*/
}

void free_memory_list(FOOTB_PTR head_pointer)
{
    //объявим два указателя на текущий элемент и на следуюший
    FOOTB_PTR current_ptr, next_ptr;

    //проходим весь список от начала и до конца
    while(current_ptr != NULL){
        //получаем адрес следующей записи
        next_ptr = current_ptr->next;

        //освобождение памяти текущего элемента
        free(current_ptr);

        //шагаем дальше по списку
        current_ptr = next_ptr;
    }
}