//Моя попытка организации связанного списка
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//опишем структуру элемента списка данных
struct list {
    int symbol;
    struct list *next;
};

//определение типов для структуры и указателя на нее
typedef struct list LIST;
typedef LIST *LISTPTR;


//прототипы ф-ий
LISTPTR add_to_list(int, LISTPTR);
void show_list(LISTPTR);
void free_memory_list(LISTPTR);


int main(void)
{   
    //определим начальный указатель
    LISTPTR head = NULL;

    //определим мусорник
    char trash[256];

    //запустим цикл для добавления символов
    for(int i = 0; i < 5; ++i){
        int symbol = 0;
        printf("Enter character %d, ", i + 1);

        while (!isalpha(symbol)){
            printf("Must be a to z : ");
            symbol = getc(stdin);  //ввод следующего символа из буфера
            fgets(trash, 255, stdin);  //очистка буфера
        }

        head = add_to_list(symbol, head);
    }

    show_list(head);
    free_memory_list(head);

    return 0;
}

LISTPTR add_to_list(int symbol, LISTPTR first)
{
    //int symbol - сивол для помещения в список
    //LISTPTR first - адрес начального указателя
    //возвращает адрес указателя на первый элемент

    //объявляем и инициализируем нулями указатели

    //указатель на новый элемент
    LISTPTR new = NULL;

    //временный указатель для перебора списка
    LISTPTR temp = NULL;

    //указатель на предыдущий элемент,если в списке больше одного элемента
    LISTPTR previous = NULL;

    //Далее выделяем память для новой записи
    new = (LISTPTR)malloc(sizeof(LIST));

    //проверяем на корректность выделения памяти
    if (new == NULL){
        puts("Memory allocation error!");
        exit(1);
    }

    //записываем новые данные
    new->symbol = symbol; //записываем символ из аргумента
    new->next = NULL;     //говорим, чтобы указатель элемента указывал на ноль(был последним)

    //добавление первого элемента в список(если список пустой)
    if(first == NULL){ //если список изначально пуст(начальный указатель равен 0)
        first = new;     //начальный указатель ссылается теперь на новый элемент, а не на 0
        new->next = NULL;  //лишнее, но так безопаснее
    }
    /*далее рассмотрены варианты, если новый элемент не является первым
    а так же будет производится сортировка символов по алфавиту*/
    else{
        /*проверим, не вставлять ли этот элемент перед первым элементом*/
        if(new->symbol < first->symbol){ //если новый символ в алфавите располагается раньше
            new->next = first; //указатель нового элемента ссылается на то,на что ссылался начальный
            first = new; //начальный указатель ссылается на новый элемент
        }
        else{  //если нет, то проверяем не вставлять ли элемент в середину или конец списка
            temp = first->next; //временный указатель указывает на второй элемент списка
            previous = first;   //предыдущий указатель указывает на первый элемент списка

            /*теперь анализируем куда вставиться новый элемент*/
            if(temp == NULL){  //если второй элемент равен нулю(его нет)
                //тогда добавляем новый элемент в конец списка
                //указателю первого элемента присваиваем адрес нового элемента
                previous->next = new;
            }
            else{   //проверка не вставляется ли новый элемент в середину
                //в этом случае пробегаем по списку до конца начиная со второго элемента
                while((temp->next != NULL)){
                    if(new->symbol < temp->symbol){ //снова сортировка по символам алфавита
                        //если символ нового элемента стоит раньше в алфавите
                        //указателю нового элемента присваивается адрес текущего элемента
                        new->next = temp;
                        //проверяем ссылаются ли указатели на одно и тоже
                        if(new->next != previous->next){
                            puts("Error!");
                            getc(stdin);
                            exit(0);
                        }

                        //далее говорим, предыдущий элемент указывает на новый
                        previous->next = new;
                        break;  //элемент вставлен, выход из цикла
                    }
                    else{  //если же символ нового элемента стоит позже в алфавите чем текущий
                        //то мы шагаем по списку дальше
                        temp = temp->next;
                        previous = previous->next;
                    }
                }

                //проверка , не вставляется ли новый элемент в конец списка
                if(temp->next == NULL){
                    //если текущий элемент является последним
                    if(new->symbol < temp->symbol){
                        //если символ нового стоит раньше текущего (последнего)
                        //то мы новый символ вставляем перед последним
                        new->next = temp;
                        previous->next = new;
                    }
                    else{  //если же символ нового элемнета стоит в алфавите позже текущего последнего
                        temp->next = new;
                        new->next = NULL;
                    }
                }
            }
        }
    }
    return(first);
}

void show_list(LISTPTR first)
{
    //определим текущий указатель для перебора списка
    LISTPTR current;

    //счетчик
    int counter = 1;

    printf("\n\nRec addr    Position    Data    Next Rec addr\n");
    printf("============    ========    ====    ============\n");

    //установим текущий указатель на начало списка
    current = first;

    //далее делаем перебор списка от начала и до конца
    while(current != NULL){
        printf("    %p    ", current);
        printf("       %d      %c", counter++, current->symbol);
        printf("        %p    \n", current->next);

        //шаг дальше
        current = current->next;
    }
}

void free_memory_list(LISTPTR first)
{
    // освобождение всей памяти , занятой списком

    //объявляем два указателя
    LISTPTR current, next_rec; //указатель на текущий элемент и на следующий элемент

    current = first; //текущий указатель ставим в самое начало списка


    //проходим весь список до конца
    while(current != NULL){
        //получаем адрес следующей записи
        next_rec = current->next;

        //освобождение памяти для текущей записи
        free(current);

        //шагаем дальше
        current = next_rec;
    }
}