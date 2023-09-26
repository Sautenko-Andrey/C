/* Указатели на функцию. Функция как параметр (callback)  */

#include<stdio.h>
#define SIZE    10

//estimate square of prm
int sqrt_prm(int height, int width)
{
    return height * width;
}

float calc_utility_bills(float light, float water, float gas, float heating)
{
    return light + water + gas + heating;
}

double get_tax(double sallary, double bonus)
{
    return (sallary + bonus) * 0.2;
}

double get_13th_sallary(double sallary, double bonus)
{
    return (sallary + bonus) * 0.75;
}

void say_hello(void)
{
    puts("Hello, pal!");
}

/* dest_array - массив в который будут копироваться четные числа, src_array - массив из 
которого будут копироваться четные числа, int(*is_correct)(int) - указатель на функцию,
которая будет делать непосредственно отбор */
void filter(int dest_array[], size_t size_dest_array,
            const int src_array[], size_t size_src_array,
            int(*is_correct)(int))
{
    //сначала обнулим все элементы массива dest_array:
    for (int i = 0; i < size_src_array; ++i){
        dest_array[i] = 0;
    }
    /*далее пропишем цикл, который будет отбирать из массива src_array только те элементы,
    которые корректны с точки зрения ф-ии, которую будем вызывать через указатель is_correct */
    for(int i = 0, j = 0; i < size_src_array; ++i){
        if(is_correct(src_array[i])){
            dest_array[j++] = src_array[i];
        }
    }
}

//объявим ф-ию, которая выделяет только четные значения
int is_even(int x)
{
    return x % 2 == 0;//если число четное? то ф-я вернет 1? если нечетное? то ф-я вернет 0
}

//объявим функцию, которая выбирает все положительные числа
int is_positive(int x)
{
    return x > 0; //если число больше 0, то вернется 1, если меньше, то 0
}

//ф-я выбирает нечетные числа
int is_odd(int x)
{
    return x % 2 != 0;
}

int main(void)
{
    printf("Adress sqrt_prm: %p\n", sqrt_prm);  //Adress sqrt_prm: 0x557674fe5149

    //объявим указатель,который будет указывать на эту же самую функцию sqrt_prm
    int (*ptr_func)(int, int);
    /*этот указатель может ссылаться на любую функцию, которая возвращает целочисленное
    значение int и содержит два параметра int, int.
    Присовим этому указателю значение другого указателя(нашу функцию) */

    ptr_func = sqrt_prm;
    /*теперь мы можем вызвать ф-ию sqrt_prm() через указатель ptr_func*/
    int result = ptr_func(2,3);
    printf("Sqare = %d cm\n", result);

    //еще практика
    //выше определим еще одну функцию, считающую коммуналку
    //определим указатель на эту функцию
    float (*ptr_utility)(float, float, float, float);
    ptr_utility = calc_utility_bills;

    float total_bill = ptr_utility(100.00, 152.50, 33.75, 254.99);
    printf("Total bill = %.2f uah\n", total_bill);

    //определим выше еще одну ф-ию, которая считает налоги
    //определим указатель на эту ф-ию
    double (*ptr_tax)(double, double);
    ptr_tax = get_tax;
    double my_tax = ptr_tax(1000.00, 500.00);
    printf("My tax equal %.2f\n", my_tax);

    //в качестве примера мы можем объявить еще одну ф-ию на которую будет указывать этот
    //указатель ptr_tax
    ptr_tax = get_13th_sallary;
    double extra_sal = ptr_tax(25000.00, 2700.00);
    printf("My extra sallary = %.2f\n", extra_sal);

    //объявим функцию, которая ничего не возвращает
    //объявим указатель на эту ф-ию
    void (* ptr_hello)(void);
    ptr_hello = say_hello;
    ptr_hello();


    //далее рассмотрим? где это может быть полезно/
    /*Предположим, нам нужно определить ф-ию, которая бы отбирала из одного массива в другой
    массив только те элементы, которые удовлетворяют некоторому критерию, причем критерии
    будут определяться другой независимой функцией.

    объявим одномерный массив:  */
    int digits[] = {-1, 45, 23, -60, 15, 10};

    //хотим из этого массива выбирать все четные элементы и помещать в другой массив result
    int result_arr[SIZE];

    //выше пропишем функцию, которая бы отбирала только четные числа из массива
    //вызовем ф-ию filter
    filter(result_arr, SIZE, digits, sizeof(digits)/sizeof(*digits), is_even);
    
    printf("Array with only even digits: ");
    for (int i = 0; i < SIZE; ++i){
        printf("%d ", result_arr[i]);
    }
    puts("");

    //теперь отберем только положительные числа, прописавши ту же самую функцию filter,
    //но уже укажем is_positive  в аргументах
    filter(result_arr, SIZE, digits, sizeof(digits)/sizeof(*digits), is_positive);

    printf("Array with only positive digits: ");
    for (int i = 0; i < SIZE; ++i){
        printf("%d ", result_arr[i]);
    }
    puts("");



    //так же мы можем определить массив из указателей на функции
    /*предположим, что у нас определены несколько ф-ий для выделения тех или иных значений:
    is_even, is_positive и is_odd
    
    Сформируем массив из указателей на эти функции  */
    int (*criterials[])(int) = {is_even, is_positive, is_odd};

    //воспользуемся этим массивом указателей на функции
    filter(result_arr, SIZE, digits, sizeof(digits)/sizeof(*digits), criterials[2]);

    printf("Array with only odd digits: ");
    for (int i = 0; i < SIZE; ++i){
        printf("%d ", result_arr[i]);
    }
    puts("");

    return 0;
}