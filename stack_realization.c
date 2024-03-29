/*Реализация стека (пример использования структур) */
/*В программе мы реализуем стек следующим образом:
        каждый объект этого стека будет представляться вот такой структурой :
        
        typedef struct tag_obj {
            int data;
            struct tag_obj *next;
        }OBJ;
        
        -здесь поле data  - это данные,которые будут сохраняться в каждом объекте этого стека.
        -указатель next - это указатель на следующий объект этого стека.
        У последнего объекта этот указатель next будет равен NULL.
        Если мы видим, что указатель имеет значнеие NULL, значит объект в стеке последний.
        
    На самый верх стека будет вести указатель top, и он всегда указывает на самый верхний
    объект этого стека.
    */

#include<stdio.h>
#include<stdlib.h>

//объявим нашу структуру
typedef struct tag_obj {
    int data;
    struct tag_obj *next;
}OBJ;

/*Обрати внимание как объявлен в структуре указатель next.Он имеет тот же тип, который мы и
описываем в структуре. Это так называемый неполный тип данных. Когда мы в структуре прописываем
тот же самый тип, который прямо сейчас и объявляем, он как бы на данный момент является
неполным, мы его полностью еще не объявили, но для компилятора это достаточная информация,
для того, чтобы мы могли сделать указатель этого типа. Кстати сделать перменную такого же типа \
внутри структуры уже нельзя.
Такой прием вполне можно использовать для того, чтобы внутри объекта стека у нас был указатель
точно такого же типа и он ссылался бы на следующий объект.*/



/*первая ф-я, которую мы объявим - это ф-я добавления нового объекта в стек.*/
OBJ* push(OBJ *top, int data)
{
    /*в качестве параметров передаем указатель на верхний объект стека и значение data-значение,
    которое будем добавлять в этот объект стека, а возвращать ф-я будет указатель на новый
    созданный объект.
    
    первым делом создадим временный указатель, который будет ссылаться на выделенную область
    для нового объекта нашего стека.*/
    OBJ *ptr = malloc(sizeof(OBJ));
    /*по сути таким образом мы в куче создаем новый объект стека.
    
    далее через указатель ptr в поле data скопируем значение data*/
    ptr->data = data;

    /*далее указатель next у нас должен указывать на следующий объект стека, а следующим
    объектом в данном случае будет top.*/
    ptr->next = top;

    /*почему top? сейчас top указывает на самый верхний объект стека,
    и кроме того мы создаем новый объект, на который ведет временный указатель ptr.
    У этого нового объекта есть указатель next. И нам нужно, чтобы указатель next
    ссылался на следующий элемент, то есть на элемент, который под ним в стеке,а сейчас на
    этот элемент указывает указатель top. поэтому нам нужно приравнять значение
    указателя next к top(скопировать адрес).Таким образом мы создадим связку.
    А top уже должен будет указывать на самый верхний объект.Сделаем это так:
    возвратим указатель на новый созданый объект*/
    return ptr;
};

/*ф-я извлечения объектов из стека*/
OBJ* pop(OBJ* top)
{
    /*в качестве параметров принимает указатель на самый верхний объект стека*/
    //проверяем, что если самый верхний объект существует
    if (top == NULL){
        return top;
    }

    //мы будем видеть какой объект с каким данными извлекается
    printf("deleted: %d\n", top->data);

    //затем этот объект нужно удалить
    /*для этого создадим временный указатель ptr_next, который ссылается на следующий объект
    этого стека*/
    OBJ *ptr_next = top->next;

    /*освоболим память, которую занимает указатель top.*/
    free(top);

    //возвратим адрес следующего объекта
    return ptr_next;
} 


//ф-я, отображающая все объекты нашего стека
void show(OBJ *top)
{
    //в качестве пераметра - вершина объекта стека
    //создадим временный указатель, который будет перебирать объекты нашего стека
    //изначально он ссылается на вершину
    const OBJ *current = top;
    while(current!=0){
        printf("%d\n", current->data);
        //далее переходим к следующему объекту
        current = current->next;
    }
}

int main(void)
{   
    /*определим указатель top с начальным значением NULL.Т.е если top = NULL, то это значит,
    что у нас пустой стек. Это указатель значит не ссылается ни на какой объект.Если top
    не равен NULL, значит он ссылается на какой-то верхний объект, который существует.*/
    OBJ *top = NULL;

    /*далее нужно определить функции для работы со стеком.
    они вверху!
    
    когда будем с помощбю ф-ии push создавать новый объект, то мы указатель top тоже
    будем менять.Т.е мы top присвоим адрес нового созданного объекта.*/
    top = push(top, 1);


    //вызовем несколько раз эту ф-ию
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    //вызовем ф-ию show
    show(top);

    /*следующая ф-я,которая понадобится - это извлечеие объектов из стека.
    воспользуемся ею*/

    while(top){   //пока top не равен 0
        top = pop(top);  //ф-я pop последовательно будет удалять все объекты из стека
    }

    return 0;
}