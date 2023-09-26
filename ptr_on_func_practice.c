/*практика применения указателей на функции*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE_ORIG   7

void sorting_array(int array[], size_t len_array);

void remove_spec_symbol(char text[], size_t len_text, char symbol);

void copy_array(char copy_array[], size_t size_copy_array,
                char orig_array[], size_t size_orig_array);

void insert_element(char array[], size_t len_array, char element, char index_element);

void del_element(char array[], size_t len_array, char del_index);

int summa(int x, int y);

int substract(int x, int y);

int mult(int x, int y);

int devide(int x, int y);

int calculator(int x, int y, int(*action)(int,int));

void def_bad_words(char text[], size_t len_text);

void conc_excl_point(char text[], size_t len_text);

void str_processing( char text[], size_t len_text, void( *str_func)(char text[], size_t len_text));



int main(void)
{
   
    //определим указатель на ф-ию по сортировке массива
    void (* ptr_sort_arr)(int *, size_t);
    ptr_sort_arr = sorting_array;

    //определим массив, который хотим отсортировать
    int my_array[] = {10,1,9,2,8,3,7,4,6,5};

    //определим его дину
    size_t length = sizeof(my_array)/ sizeof(*my_array);
    //распечатаем его
    printf("Was : ");
    for (int i = 0; i < length; ++i){
        printf("%d ", my_array[i]);
    }
    puts("");


    //отсортируем массив через указаетль на ф-ию 
    ptr_sort_arr(my_array, length);
    //sorting_array(my_array, length);
    ptr_sort_arr(my_array, length);

    //распечатаем его
    printf("Now : ");
    for (int i = 0; i < length; ++i){
        printf("%d ", my_array[i]);
    }
    puts("");

    //определим текст, который будем корректировать
    char my_text[] = "@I love Arsenal FC@";
    
    //определим длину текста
    size_t len_text = strlen(my_text);

    //определим символ, который хотим удалить
    char symbol = '@';

    //распечатаем его
    printf("Text was : ");
    puts(my_text);

    //определим указатель на ф-ию remove_spec_symbol
    void (* ptr_rm_symb)(char *, size_t, char);
    ptr_rm_symb = remove_spec_symbol;

    //изменим текст с помощью указателя
    ptr_rm_symb(my_text, len_text, symbol);

    //распечатаем его
    printf("Text now : ");
    puts(my_text);


    //скопируем элементы из одного массива в другой
    char original[SIZE_ORIG] = {1,2,3,4,5,6,7};

    char copy[SIZE_ORIG];

    //определим указатель на ф-ию copy_array
    void(* ptr_copy_array)(char *, size_t, char *, size_t);
    ptr_copy_array = copy_array;

    //скопируем элементы
    ptr_copy_array(copy, SIZE_ORIG, original, SIZE_ORIG);

    //посмотрим результат
    for(int i = 0; i < SIZE_ORIG; ++i){
        printf("%d ", copy[i]);
    }

    puts("");
    puts("----------------------");

    //вставим элемент в массив
    //определим массив
    char rates[SIZE_ORIG] = {1,2,4,5,6,7};
    for(int i = 0; i < SIZE_ORIG; ++i){
        printf("%d ", rates[i]);
    }
    puts("");
    insert_element(rates, SIZE_ORIG, 3, 2);
    //распечатаем массив
    for(int i = 0; i < SIZE_ORIG; ++i){
        printf("%d ", rates[i]);
    }
    puts("");

    //удалим элемент из массива
    char boxes[SIZE_ORIG] = {1,2,3,4,5,6,7};
    char index_for_delete = 2;
    void(*ptr_del_index)(char *, size_t, char);
    ptr_del_index = del_element;
    ptr_del_index(boxes, SIZE_ORIG, index_for_delete);

    //распечатаем массив
    puts("boxes : ");
    for(int i = 0; i < SIZE_ORIG - 1; ++i){
        printf("%d ", boxes[i]);
    }
    puts("");


    //воспользуемся услугами калькулятора
    int first_dig = 25;
    int sec_dig = 5;

    int result = calculator(first_dig, sec_dig, summa);
    printf("summa result = %d\n", result);

    int result2 = calculator(first_dig, sec_dig, substract);
    printf("substract result = %d\n", result2);

    int result3 = calculator(first_dig, sec_dig, mult);
    printf("mult result = %d\n", result3);

    int result4 = calculator(first_dig, sec_dig, devide);
    printf("devide result = %d\n", result4);



    //определим массив указателей на функции
    int (*actions[])(int) = {summa, substract, devide, mult};

    int res5 = calculator(first_dig,sec_dig, actions[0]);
    printf("summa result 2 = %d\n", res5);


    //пропишем текст с нецензурной лексикой
    char filthy_string = "i am going to fuck Vika!";

    size_t len_fs = strlen(filthy_string);
    //проверим на нецензурщину
    str_processing(filthy_string, len_fs, def_bad_words);

    return 0;
}

void sorting_array(int array[], size_t len_array)
{
    int min_index;

    for (int i = 0; i < len_array - 1; ++i){
        min_index = i;
    
        for (int j = i + 1; j < len_array; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }

        if(min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

void remove_spec_symbol(char text[], size_t len_text, char symbol)
{
    for (int i = 0; i < len_text; ++i){
        if(text[i] == symbol){
            text[i] = ' ';
        }
    }
}

void copy_array(char copy_array[], size_t size_copy_array,
                char orig_array[], size_t size_orig_array)
{
    for(int i = 0; i < size_copy_array; ++i){
        copy_array[i] = orig_array[i];
    }
}

void insert_element(char array[], size_t len_array, char element, char index_element)
{
    for (int i = SIZE_ORIG - 1; i > index_element; --i){
        array[i] = array[i - 1];
    }

    array[index_element] = element;
}

void del_element(char array[], size_t len_array, char del_index)
{
    for(int i = del_index; i < len_array; ++i){
        array[i] = array[i + 1];
    }
}

int summa(int x, int y)
{
    return x + y;
}

int substract(int x, int y)
{
    return x - y;
}

int mult(int x, int y)
{
    return x * y;
}

int devide(int x, int y)
{
    return (float)x / (float)y;
}

int calculator(int x, int y, int(*action)(int,int))
{
    return action(x, y);
}

void def_bad_words(char text[], size_t len_text)
{
    char bad_words[] = {
        "shit", "bitch", "fuck", "dick", "twat"
    };

    if(strstr(text, bad_words[0]) || strstr(text, bad_words[1]) || 
    strstr(text, bad_words[2]) || strstr(text, bad_words[3]) == 0){
        puts("filthy words identificed!");
    }
}

void conc_excl_point(char text[], size_t len_text)
{
    return strcat(text, '!');
}

void str_processing( char text[], size_t len_text, void( *str_func)(char text[], size_t len_text))
{
    return str_func(text, len_text);
}