/* Рекурсивные фннкции */

#include<stdio.h>
//определим размер игрового поля
#define N    5


//recursion func
void recursion_func(int x);

void show_pole(const char (*p)[N])
{
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            printf("%c ", (p[i][j] == 0) ? '#' : '0');
        }
        putchar('\n');
    }
}

void open_zeros(const char(*p)[N], char (*pp)[N], int i, int j)
{
    if (p[i][j] != 0 || pp[i][j] == 1)
        return;
    
    pp[i][j] = 1;
    if(i - 1 >= 0 && p[i - 1][j] == 0) open_zeros(p, pp, i - 1, j);
    if(i + 1 < N && p[i + 1][j] == 0) open_zeros(p, pp, i + 1, j);
    if(j - 1 >= 0 && p[i][j - 1] == 0) open_zeros(p, pp, i, j - 1);
    if(j + 1 < N && p[i][j + 1] == 0) open_zeros(p, pp, i, j + 1);

}    
    


int main(void)
{
    //launch recursion function
    recursion_func(4);
    putchar('\n');
    puts("");


    //рассмотрим реальную практическую задачу на рекурсию
    /*предположим, у нас есть некоторое игровое поле pole[N][N], и в этом игровом поле
    имеются значния 1 и 0. Изначальное все клетки игрового поля у нас закрыты/
    Есть еще один массив  ppole[N][N] содержащий во всех клетках 0.
    Эти нули во втором массиве будут означать, что соответствующие клетки игрового
    поля закрыты и мы можем открывать эти клетки. Так вот , когда игрок открывает
    какую-либо клетку с 0 в игровом поле, то автоматически нам нужно открыть все соседние
    клетки, которые тоже содержат нули,
    В итоге можно отобразить результат на экране следующим образом:
    закрытые клетки мы будем отображать символом #, а открытые будем обозначать тем значением
    числовым, которое имеется в этом игровом поле.
    Реализуем эту задачу с помощью рекурсивной функции.
    Логика будет следующей: когда пользователь открывает какую-либо клетку, в которой находится 0,
    то он рекрсивно просматривает все соседние клетки, которые расположены по горизонтали и по
    вертикали, и если в этих соседних клетках тоже встречается 0, то по рекурсии мы снова отно-
    сительно этой новой клетки смотрим ее соседние клетки и т.д.
    В результате, когда мы открываем и появляется какой-либо ноль, мы рекурсивно сможем открыть
    все остальные нули, которые находятся в связке с этим нулем.*/

    //определим игровое поле
    char pole[N][N] = {
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };

    //определим еще один массив, который определяет открыта или закрыта клетка
    char ppole[N][N] = {0};

    //далее у нас будет вспомагательная функция - отображение игрового поля на экране
    show_pole(ppole);

    /*далее пропишем еще одну ф-ию, которая называется open_zeros(), то есть открытие нулей.
    И в эту функцию в качестве аргументов будем передавать игровое поле,  ppole,
    чтобы мы могли помечать клетки, которые открываем и затем индексы той клетки,которую
    первой открываем : open_zeros(pole, ppole,2,2) - первая клетка, которую откроем будет 2 2
    */
    open_zeros(pole, ppole, 2, 2);
    puts("---------------------------");
    show_pole(ppole);

    return 0;
}


void recursion_func(int x)
{
    //сначала выводится значение x
    printf("Down: x = %d\n", x);
    //происходит проверка, что если х больше 1, то ф-я вызывает саму себя с аргументом x - 1
    if (x > 1){
        recursion_func(x - 1);
    }

    //после того как будет выполненя вся эта ф-я, в конце вызывается еще один printf()
    printf("Up: x = %d\n", x);
}