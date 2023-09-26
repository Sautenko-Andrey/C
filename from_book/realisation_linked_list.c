/*Реализация связанного списка.
Связаный список будет хранить пять символов.
Программа сортирует данные по мере их добавления, т.е элементы добавляются
в начало, середину или в конец списка в зависимости от их значения. Данные списка
всегда находятся в отсортированном порядке.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#ifndef NULL
#define NULL    0
#endif


/*Структура данных элемента списка*/
struct list{
    int ch;  //в переменной типа int хранится символ типа char;
    struct list *next;
};

//определение типов для структуры и указателя на нее
typedef struct list LIST;
typedef LIST *LISTPTR;


/*Прототипы функций*/
LISTPTR add_to_list(int, LISTPTR);
void show_list(LISTPTR);
void free_memory_list(LISTPTR);

int main(void)
{   
    //объявим указатель на первый элемент связанного списка и инициализируем его NULL
    LISTPTR first = NULL;

    int i = 0;
    char symbol;

    char trash[256]; //переменная для очистки буфера stdin

    //построение списка из 5 элементов
    while( i++ < 5){
        symbol = 0;
        printf("Enter character %d', ", i);

        /*do{
            printf("\nMust be a to z : ");

            //ввод следующего символа из буфера
            ch = getc(stdin);

            //очистка буфера
            fgets(trash, 50, stdin);
        } while  ( (ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') ); //abdvz */

        while ((symbol < 'a' || symbol > 'z') && (symbol < 'A' || symbol > 'Z')){
            printf("\nMust be a to z : ");

            //ввод следующего символа из буфера
            symbol = getc(stdin);

            //очистка буфера
            fgets(trash, 50, stdin);
        }

        first = add_to_list(symbol, first);   
    }

    //вывод всего списка
    show_list(first);

    //освобождение всей памяти
    free_memory_list(first);

    return 0;
}

/*Функция add_to_list() помещает новый элемент в список.
int ch - это символ для помещения в список.
LISTPTR first - это адрес начального указателя.
Функция возвращает адрес указателя на первый элемент.*/
LISTPTR add_to_list(int ch, LISTPTR first)
{
    //определяем указатели
    LISTPTR new_rec = NULL;   //указатель на новый элемент(адрес новой записи)
    LISTPTR tmp_rec = NULL;   //временный указатель для перебора списка
    LISTPTR prev_rec = NULL;  //указатель на предыдущий элемент списка


    //Выделение памяти для нового элемента
    new_rec = (LISTPTR)malloc(sizeof(LIST));

    //проверяем на ошибку выделения памяти
    if(!new_rec){
        printf("\nUnable to allocate memeory!");
        exit(1);
    }

    //Запись новых данных
    new_rec->ch = ch;
    new_rec->next = NULL;

    if (first == NULL){   //добавление первого элемента в список,если список пустой
        first = new_rec;
        new_rec->next = NULL; //лишнее, но так безопаснее
    }
    else{   //если не первый элемент

        //проверка, не вставлять ли этот элемент перед первым элементом
        if(new_rec->ch < first->ch){
            new_rec->next = first;
            first = new_rec;
        }
        else{   //если вставляется в середину или конец
            tmp_rec = first->next;
            prev_rec = first;

            //анализируем куда вставить элемент
            if(tmp_rec == NULL){
                //значит добавляем запись в конец списка
                prev_rec->next = new_rec;
            }
            else{
                //проверка , не вставляется ли в середину
                while((tmp_rec != NULL)){
                    if(new_rec->ch < tmp_rec->ch){
                        new_rec->next = tmp_rec;
                        if(new_rec->next != prev_rec->next){
                            printf("Error!");
                            getc(stdin);
                            exit(0);
                        }
                        prev_rec->next = new_rec;
                        break; //элемент вставлен, выход из цикла 
                    }
                    else{
                        tmp_rec = tmp_rec->next;
                        prev_rec = prev_rec->next;
                    }
                }

                //проверка, не вставляется ли в конец
                if(tmp_rec->next == NULL){
                    if(new_rec->ch < tmp_rec->ch){   /*предпоследний*/
                        new_rec->next = tmp_rec;
                        prev_rec->next = new_rec;
                    }
                    else{   //в конец
                        tmp_rec->next = new_rec;
                        new_rec->next = NULL;  //лишнее
                    }
                }
            }
        }
    }
    return (first);
}

/*функция для вывода информации из списка*/
void show_list(LISTPTR first)
{
    LISTPTR cur_ptr;
    int counter = 1;
    printf("\n\nRec addr  Position  Data  Next  Rec  addr\n");
    printf("=======  =======  ====  =============\n");

    cur_ptr = first;
    while (cur_ptr != NULL){
        printf("  %X  ", cur_ptr);
        printf("    %2i    %c", counter++, cur_ptr->ch);
        printf("     %X   \n", cur_ptr->next);
        cur_ptr = cur_ptr->next;
    } 
}

/*Функция для освобождения всей памяти, занятой списком*/
void free_memory_list(LISTPTR first){

    LISTPTR cur_ptr, next_rec;
    cur_ptr = first;  //начать сначала

    while(cur_ptr != NULL){   //идти до конца
        next_rec = cur_ptr->next;  //получение адреса следующей записи
        free(cur_ptr);   //освобождение текущей записи
        cur_ptr = next_rec;  //сммещение на одну запись
    }
}
