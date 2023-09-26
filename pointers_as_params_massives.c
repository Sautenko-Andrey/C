/*Указатели как параметры. Передача массивов в функции */

#include<stdio.h>
#include<strings.h>

void swap_2(float *ptr_1, float *ptr_2)
{
    //создадим временную переменную temp и присвоим ей содержимое первого указателя
    float temp = *ptr_1;
    //далее мы в ячейку памяти, на которую ссылается первый указатель, заносим значение
    //на которое ссылается второй указатель
    *ptr_1 = *ptr_2;
    //а далее присваиваем второму указателю значение temp
    *ptr_2 = temp;
}

void price_changer(float *change_pr_pointer, float new_price)
{
    *change_pr_pointer = new_price;
}

int summ_array_el(const short ptr_array[], int length)
{
    int res = 0;
    for (int i = 0; i < length; ++i){
        res += ptr_array[i];
    }
    return res;
}

//при необходимости можно объявлять функции, которые возвращают указатель
const char* find_space(const char* some_string)
{
    while(*some_string!='\0'){
        if (*some_string == ' ')
            return some_string;
        
        some_string++;
    }
}

int main(void)
{
    //для освежения памяти
    float value = 100.99f;
    float *ptr = &value;
    *ptr = 99.99f;

    printf("value = %.2f\nptr* = %.2f\nadress of ptr = %p\n",value, *ptr, ptr);

    //далее представим, что нам нужна функция, которая бы меня значение двух переменных,
    float apple_golden = 21.99f, kent_silver = 85.00f;
    //мы хотим написать ф-ию, которая бы присваивала apple_golden цену kent_silver и наоборот.

    //вызываем ф-ию swap_2() и в параметры передаем именно адреса переменных
    swap_2(&apple_golden, &kent_silver);

    //посмотрим на результат
    printf("apple_golden = %.2f\nkent_silver = %.2f\n", apple_golden, kent_silver);
    

    //еще пример для практики
    //у нас есть цена картошки, и мы хоти ее поменять на другую цену
    float potato = 29.50f;
    price_changer(&potato, 30.00f);
    //смотрим результат
    printf("potato costs : %.2f uah\n", potato);
    

    //пример, когда указатели используются для передачи массивов в функции
    //посчитаем сумму значений элементов массива
    short my_array[] = {1,2,3,4,5};
    int size = sizeof(my_array) / sizeof(*my_array);

    int summa = summ_array_el(my_array, size);
    printf("Total summ of elements = %d\n", summa);

    //воспользуемся функцией для поиска пробела в строке
    //char my_string[] = "I love.";
   // const char* res = find_space(my_string);
    //printf("res = %p\n", res);
    puts("lalalala");

    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }



    return 0;
}