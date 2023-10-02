/*Указатели на структуры. Передача структур в функции*/
#include<stdio.h>
#include<stdlib.h>

//улулчшим визуальную состовляющую с помощью typedef.убери нижнее определение структуры!
//typedef struct tag_vector{
    //double x;
    //double y;
//} VECTOR;    //пусть называется просто VECTOR
/*Далее в программе мы можем пользоваться этим типом VECTOR вместо struct tag_vector*/

struct tag_vector {
    double x;
    double y;
};

struct tag_vector create_vector(double x, double y)
{
    //создадим перменную на эту структуру и сразу же ее проинициализируем парметрами x,y
    struct tag_vector vector = {x,y};
    //вернем ее
    return vector;


    /*второй вариант записи этой же ф-ии
    
    return (struct tag_vector){x,y}
    
    */
};
/*Комментарий к ф-ии:
при вызове этой функции формируется переменная vector внутри тела ф-ии, т/е/ в стековом фрейме,
эта перменная инициализируется переданными переменными x,y .И затем эта созданная структура
возвращается. Вот здесь важный момент! ВОЗВРАТ СТРУКТУРЫ ЕСТЬ НИ ЧТО ИНОЕ, КАК КОПИРОВАНИЕ ВСЕГО
ЕЕ СОДЕРЖИМОГО В ПЕРМЕННУЮ( В ДАННОМ СЛУЧАЕ В СОЗДАННУЮ НИЖЕ ПЕРЕМЕННУЮ BIAS). Сама же переменная
vector перестает существовать после завршения ф-ии create_vector()

Вот такие процессы создания переменной vector и копирования ее содержимого в переменную bias
происходят в нашей программе. если структура небольшого размера, то это некритично.
Но если она занимает больште объемы, то возникает сразу две проблемы:
1) значительный расход ограниченной памяти стекового фрейма
2) копирование большого объема памяти при возврате такой структуры из функции.
Для разрешения этих проблем можно воспользоваться механизмом динамического выделения памяти 
из кучи c помощью malloc() и free().


Создадим новую функцию, которая будет решать эти проблемы. Ф-я будет возвращать указатель
на структуру, под которую мы динамически будем выделять память из кучи.*/
struct tag_vector* modern_create_vector(double x, double y)
{
    //в теле ф-ии мы должны сначала создать эту структуру, выделив под нее память из кучи
    struct tag_vector *modern_vector = malloc(sizeof(struct tag_vector));

    //далее проинициализируем соответствующие поля структуры
    modern_vector->x = x;
    modern_vector->y = y;

    //возвратим указатель modern_vector
    return modern_vector;
    
};

//ф-я складывающая два вектора между собой
struct tag_vector sum_vector(const struct tag_vector v1,const struct tag_vector v2)
{
    //создадим временную переменную res и сложим соответствующие поля векторов
    struct tag_vector res = {v1.x + v2.x, v1.y + v2.y};
    return res;
};

//более быстрый вариант суммирования векторов, где в параметры мы передаем указатели
struct tag_vector fast_sum_vector(const struct tag_vector *v1, const struct tag_vector *v2)
{
    struct tag_vector res = {v1->x + v2->x, v1->y + v2->y};
    return res;

    /*второй вариант записи этой же ф-ии
    
    return (struct tag_vector){v1->x + v2->x, v1->y + v2->y};
    
    */
};
/*ВНИМАНИЕ! указатели прописаны только в параметрах, возвращаемое значение остается 
такое же как и у более медленной функции.*/

//ф-я для суммирования координат в первом переданном векторе
void isum_vector(struct tag_vector *v1, const struct tag_vector *v2)
{
    /*В самой ф-ии мы в векторе v1 будем сохранять сумму {v1->x + v2->x, v1->y + v2->y} .*/
    v1->x += v2->x;
    v1->y += v2->y;
};
/*ВНимание! мы здесь ничего не возвращаем!
Потому что мы непосредственно меняем данные внутри области памяти на которую ведет указатель
v1.
*/

int main(void)
{   
    struct tag_vector my_vector = {1.0, 2.0};

    //далее определим указатель этого же самого типа
    struct tag_vector *ptr_vector;

    /*Привяжем указатель к переменной*/
    ptr_vector = &my_vector;

    //поменяем значения в переменной через указатель
    (*ptr_vector).x = 100;
    (*ptr_vector).y = 200;

    //прочитаем значение переменной через указатель в какую-нибудь другую переменную
    double x = (*ptr_vector).x;


    /*ЗАЧЕМ ставить круглые скобки на указатель?
    Ставим скобки, потому что приоритет у операции . выше, чем у операции *
    Поэтомубез скобок не будет работать.
    
    Как мы видим, такой синтаксис не очень удобен, поэтому в Си именно для доступа к полям
    составных типов данных через указатели, был введен спецоператор:
    
    например мы хотим поменять значение в переменной через указатель: */
    ptr_vector->x = 333.33;

    /*Эта опреация и операция выше(внесение новых данных в переменную - это одно и тоже.).
    Но второй вариант предпочтительнее из-за своей наглядности.
    
    прочитать данные в другую перменную мы можем аналогично : */
    double some_y = ptr_vector->y;
    printf("some_y = %.2f\n", some_y);


    /*Важно! Имея указатель на структуры, мы получаем возможность их динамического формирования
    в основной памяти устройства(куче).
    Для этого мы можем воспользоваться ф-ей malloc() следуюшим образом : */

    //определим новый указаетель
    /*мы указателю сразу присваиваем адрес, который вернет ф-я malloc(). */
    struct tag_vector *ptr_v = malloc(sizeof(struct tag_vector));

    /*В куче у нас выделяется память под эту структуру ыекгсе tag_vector и мы через указатель
    ptr_v  можем совершенно спокойно работать с этой областью памяти.*/

    //запишем туда данные
    ptr_v->x = 7.5;
    ptr_v->y = 11.01;

    //так же можем прочитать оттуда данные
    printf("x = %.2f, y = %.2f\n", ptr_v->x, ptr_v->y);   //x = 7.50, y = 11.01

    //не забывай освобождать выделенную память
    free(ptr_v);


    /*Фактически с помощью ф-ий malloc() и free() мы создали новую переменную на структуру
    struct tag_vector в основной памяти устройства, а не в стеке вызова функции, записали 
    туда данные и прочитали с выводом на экран.
    И так как эта переменная была создана не в стеке вызова ф-ии, а именно в куче, то она 
    продолжает существовать, пока не будет вызвана ф-я free().
    
    Если не прописать free() то переменная будет существловать и после заврешения работы
    ф-ии, то есть область памяти, которую мы выделили продолжает существовать и там продолжает
    храниться наша структура.

    В качестве примера выше объявим ф-ию, которая будет возвращать нашу структуру
    Воспользуемся созданной ф-ей : */


    struct tag_vector bias = create_vector(3.14, 4.81);

    //посмотрим что получится
    printf("bias x = %.2f, bias y = %.2f\n", bias.x, bias.y);   //bias x = 3.14, bias y = 4.81


    //используем в программе ф-ию modern_create_vector
    //определим новый указатель и присвоим ему значение, возвращаемое ф-ей modern_create_vector
    struct tag_vector *modern_bias = modern_create_vector(28.0, 34.0);

    //выведем значения на экран
    printf("bias x = %.2f, bias y = %.2f\n", modern_bias->x, modern_bias->y); //bias x = 28.00, bias y = 34.00

    //в конце освободим выделенную память
    free(modern_bias);

    /*И мы здесь получили более тонкий процесс работы со структурами.
    Во-первых в этой ф-ии мы выделяем память в основной памяти устройста, заполняем эту память
    соответствующими данными, и возвращаем только адрес на эту память. Эта выделенная паямть после 
    завершения ф-ии modern_create_vector так и остается и на эту выделенную память уже ведет
    указатель modern_bias.Этот указатель содержит адрес динамически выделенной памяти, потому что
    в ф-ии modern_create_vector мы копируем не всю структуру целиком, а только ее адрес.
    
    Соответственно через этот адрес мы работаем с памятью и в данном примере выводим не экран то,
    что содержится в этой структуре.
    
    Но , здесь есть один ньюанс!
    Если мы дважды вызовем эту ф-ию modern_create_vector(), с присвоением адреса одному и тому же
    указателю, то адрес предыдущей выделенной области памяти окажется потерянным,
    и с нею мы уже работать не сможем, потому что мы потеряли на нее указатель. Т.е у нас 
    будет выделенн кусок памяти с которым мы не можем работать и он просто будет висеть.
    Это называется утечка памяти.
    
    
    Поэтому переходить на уровень указателей стоит только в тех случаях,когда размещение и
    копирование больших структур действительно критически сказывается на скорости работы
    программы.
    
    Без этого лучше прописывать структуры на уровне обычных автоматических переменных
    как мы это делали в первом случае.
    
    
    
    Далее рассмотрим механизм передачи структур в функции.
    Предположим, что нам нужно объявить ф-ию, которая бы складывала два вектора между
    собой. Объявим ее выше.
    
    создадим два вектора, которые будем складывать*/
    struct tag_vector vector_1 = create_vector(1.0, 2.0);
    struct tag_vector vector_2 = create_vector(10.0, 20.0);

    //складываем их
    struct tag_vector conj_vector = sum_vector(vector_1, vector_2);
    printf("conj_vector x = %.2f, conj_vector y = %.2f\n", conj_vector.x, conj_vector.y);


    /*Мы здесь получили не самый быстрый, но зато безопасный процесс при работе со структурами.

    Можно ли как-то ускорить работу ф-ии sum_vector , сохранив безопасность ее работы?
    На самом деле можно, если в качестве параметров прописать константные указатели,
    т.е не просто v1 и v2,  а *v1 и *v2. Т/е/ сделать из этих параметров указатели.
    пропишем вверху улучшенную ф-ию.
    Воспользуемся этой ф-ей : */

    struct tag_vector vec1 = create_vector(100.0, 200.0);
    struct tag_vector vec2 = create_vector(1.0, 2.0);

    struct tag_vector res_sum = fast_sum_vector(&vec1, &vec2);
    printf("sum x = %.2f, sum y = %.2f\n", res_sum.x, res_sum.y);

    /*Засчет чего здесь получилось ускорение работы?
    Когда мы в параметрах ф-ии fast_sum_vector(&vec1, &vec2) передаем адреса, то структуры
    целиком копироваться сюда не будут, копируется только адрес.
    
    
    Выше пропишем еще одну ф-ию, которая бы суммировала координаты в первом переданном векторе.
    Воспользуемся этой ф-ей : */
    isum_vector(&vec1, &vec2);

    //посмотрим что получилось
    printf("vec1 x = %.2f, vec1 y = %.2f\n", vec1.x, vec1.y);

    //или вместо vec2 мы можем подставлять сразу конкретную структуру с конкретными значениями.
    struct tag_vector vv = create_vector(13.0, 98.0);
    isum_vector(&vv, &(struct tag_vector){0.5, -0.3});
    printf("vv x = %.2f, vv y = %.2f\n", vv.x, vv.y);
    

    /*Сделаем еще одно небольшое улучшение программы.
    У нас довольно часто фигурирует тип struct tag_vector.
    Визуально это  воспринимается нелучшим образом и постоянно приходится набирать эту длинную
    последовательность символов.
    Исправим этот момент с помощью typedef вверху программы
    
    VECTOR vec3 = create_vector(1.0, 2.0);
    Везде в программе мы можем заменить struct tag_vector на VECTOR.
    Программы значительно лучшесмотрится и воспринимается.
    */




    

    return 0;
}