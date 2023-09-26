//пркатика по основам связанных списков
#include<stdio.h>
#include<stdlib.h>


//опишем струтуру друзей
struct friend{
    char *name;
    char *phone;
    struct friend *next_friend;
};

//declearing footballer struct
struct footballer{
    char *name;
    char *club;
    struct footballer *next_player;
};



int main(void)
{   
    //заполним полносвязный список

    //объявим начальный указатель и присвоим ему значение 0
    struct friend *head = NULL;

    //объявим указатель на новый элемент полносвязного списка
    struct friend *new;

    //выделим память под новый элемент
    new = (struct friend*)malloc(sizeof(struct friend));

    //установим указатель на следующий узел списка таким же, что и у начального указателя
    new->next_friend = head;

    //установим начальный указатель равный адресу нового элемента
    head = new;

    //попрбуем заполнить новый элемент данными
    new->name = "Andrey";
    new->phone = "+380950180611";

    //теперь посмотрим на все значения нового элемента полносвязного списка
    printf("Name: %s\nTel: %s\nNext friend adress: %p\n", new->name, new->phone, new->next_friend);


    //теперь добавим новый элемент в конец списка

    //объявим указатель на структуру присвоим ему адресс начального указателя
    struct friend *current;
    current = head;
    struct friend *last_friend;

    //пройдемся этим указателям в самый конец
    while(current->next_friend != NULL){
        current = current->next_friend;
    }
    
    //выделим память под новый элемент
    last_friend = (struct friend*)malloc(sizeof(struct friend));

    //установить указатель в текущем последнем элементе на добавляемый новый элемент
    current->next_friend = last_friend;

    //установим указатель нового элемента в ноль, показывая,что это последний эл-т в списке
    last_friend->next_friend = NULL;

    //присвоим значения последнему элементу
    last_friend->name = "Alex";
    last_friend->phone = "+380954563214";


    //теперь посмортим на общую картину списка
    printf("Name: %s\nTel: %s\nNext friend adress: %p\n", new->name, new->phone, new->next_friend);
    printf("Name: %s\nTel: %s\nCurrent adress: %p\nNext friend adress: %p\n", last_friend->name,\
    last_friend->phone, last_friend, last_friend->next_friend);



    //let's practice with another onr linked list which name is footballer

    //объявим начальный указатель и инициализируем его нулем
    struct footballer *head_ptr = NULL;

    //объявим указатель на новый элемент списка
    struct footballer *player;

    //выделим память под новый элемент свзянного списка
    player = (struct footballer*)malloc(sizeof(struct footballer));

    //далее скажем, что указатель нового элемента ссылается на значение начального указателя
    player->next_player = head_ptr;  //на ноль если пустой список или на первый элемент,
                                     //если не пустой список
    
    //начальный указатель всегда должен указывать на первый элемент связанного списка
    head_ptr = player;


    //далее добавим элемент в конец связанного списка
    //объявляем указатель на текущий элемент списка , который изначально указывает на начальный ук
    struct footballer *current_player = head_ptr;

    //объявляем указатель на новый элемент и выделяем под него память
    struct footballer *last_player;
    last_player = (struct footballer*)malloc(sizeof(struct footballer));

    //перебираем полносвязный список пока не дойдем до последнего элемента
    while(current_player->next_player != NULL){
        current_player = current_player->next_player;
    }

    //устаноим указатель в текущем элементе на новый добавленный элемент
    current_player->next_player = last_player;

    //так же говорим, что значение нового элемента указывает на ноль
    last_player->next_player = NULL;



    //далее рассмотрим добавление элемента в середину связного списка

    //сначала найдем существующий элемент в списке, после которого должен стоять новый добавляемый
    //элемент, назовем его маркер
    struct footballer *marker;


    //скажем, что это первый элемент
    marker = player;

    //создадим новый элемент и выделим под него память
    struct footballer *middle_player;
    middle_player = (struct footballer*)malloc(sizeof(struct footballer));

    //установить указатель в новом элементе на тот элемент, на который до этого указывал маркер
    middle_player->next_player = marker->next_player;

    //установить указатель в маркере на новый добавляемый элемент
    marker->next_player = middle_player;

    //добавим данные в элементы
    player->name = "Ben White";
    player->club = "Arsenal FC";

    middle_player->name = "Declan Rice";
    middle_player->club = "Arsenal FC";

    last_player->name = "Martinelli";
    last_player->club = "Arsenal FC";

    //посмотрим на структуру целиком
    printf("First player adress: %p\n", player);
    printf("First player name: %s\n", player->name);
    printf("First player pointer adress: %p\n", player->next_player);

    printf("Middle player adress: %p\n", middle_player);
    printf("Middle player name: %s\n", middle_player->name);
    printf("Midlle player pointer adress: %p\n", middle_player->next_player);

    printf("Last player adress: %p\n", last_player);
    printf("Last player name: %s\n", last_player->name);
    printf("Last player pointer adress: %p\n", last_player->next_player);
    

    


    


    return 0;
}