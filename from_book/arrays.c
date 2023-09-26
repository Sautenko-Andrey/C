#include<stdio.h>
#include<stdlib.h>

#define N   10

//запись жлементов с клавиатуры в массив в куче
int* read_data_arr(void);

//сортировка массива в куче
void sort_array(int array[], size_t len_array);

//подсчет суммы элементов в массиве
int sum_array(int array[], size_t len_array);

//обнуление всех элементов
void fill_nulls(int array[], size_t len_array);

//перевернутый массив
void reverse_array(int array[], size_t len_array);


int main(void)
{   

    //filling the array in main memory by stdin and display it
    int *res = read_data_arr();
    for(int i = 0; i < N; ++i){
        printf("%d ", *(res + i));
    }
    putchar('\n');

    puts("-------------------------------------");
    

    //sorting our array
    sort_array(res, N);

    for(int i = 0; i < N; ++i){
        printf("%d ", *(res + i));
    }
    putchar('\n');

    //computing summ of all elements in array
    int sum = sum_array(res, N);
    printf("Total sum = %d\n", sum);

    //making all elements in array equal 0
/*    fill_nulls(res, N);
    //display result
    for(int i = 0; i < N; ++i){
        printf("%d ", *(res + i));
    }
    putchar('\n');
*/

    //reversing array's values
    reverse_array(res, N);
    
    free(res);

    //designated initializer
    int numbers[N] = {[2] = 29, [5] = 16, [8] = -1};
    for(int i = 0; i < N; ++i){
        printf("%d ", numbers[i]);   //0 0 29 0 0 16 0 0 -1 0
    }
    putchar('\n');


    int values[] = {[3] = 13, [1] = 100, [23] = 144, [7] = -7};
    for(int i = 0; i < sizeof(values) / sizeof(*values); ++i){
        printf("%d ", values[i]);
    }
    putchar('\n');
    printf("Size = %ld\n", sizeof(values) / sizeof(*values));


    return 0;
}

int* read_data_arr(void){

    //выделяем память в куче размером 10 * int
    int *ptr = malloc(sizeof(int) * N);

    //черезз цикл добавляем в каждый элемент новое значение
    for (int i = 0; i < N; ++i){
        printf("Enter an integer : ");
        scanf("%d", ptr + i);  //используется адресная арифметика для перебора ячеек
    }

    for(int i = 0; i < N; ++i){
        printf("%d ", *(ptr + i));
    }
    putchar('\n');

    return ptr;
}

void sort_array(int array[], size_t len_array)
{
    int min_index;

    for (int i = 0; i < len_array - 1; ++i){
        min_index = i;

        for(int j = i + 1; j < len_array; ++j){
            if(array[min_index] > array[j]){
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

int sum_array(int array[], size_t len_array)
{   
    int total = 0;

    for(int i = 0; i < len_array; ++i){
        total += array[i];
    }

    return total;
}

void fill_nulls(int array[], size_t len_array)
{
    for (int i = 0; i < len_array; ++i){
        array[i] = 0;
    }
}

void reverse_array(int array[], size_t len_array)
{
    int *ptr = malloc(sizeof(int) * len_array);

    for(int i = 0; i < len_array; ++i){
        *(ptr + i) = array[len_array - (i + 1)];
    }

    for(int i = 0; i < len_array; ++i){
        printf("%d ", *(ptr + i));
    }
    putchar('\n');
}
