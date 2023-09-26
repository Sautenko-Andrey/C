/* практика применения enum и typedef */

#include<stdio.h>
#include<stdlib.h>

//пропишем фцнкцию для подсчета самой выгодной цены
void get_best_price(float array[], size_t len_array)
{
    size_t min_index;
    for(int i = 0; i < len_array - 1; ++i){
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

//новый тип данных на основании этой функции
typedef void (*PTR_SORT)(float*, size_t);

//определим функцию которая выдает толльк о четные целые числа
int sum_even(int x, int y, int z)
{
    int res = x + y + z;
    return res % 2 == 0;
}

//заведем тип данных на основании этой функции
typedef int (*PTR_EVEN_SUM)(int, int, int);

enum items_id {
    beer = 12, cola = 7, sigarettes = 3, chips = 22
};

int main(void)
{   

    //старый метод
    //сначала сделаем указатель на эту функцию по старинке в явном виде
    void (*ptr_best_price)(float *, size_t);
    ptr_best_price = get_best_price;

    //применим его
    //исходный массив с ценами
    float prices[5] = {10.00, 15.00, 14.55, 99.99, 100.10};
    //размер
    size_t len_prices = sizeof(prices) / sizeof(*prices);

    ptr_best_price(prices, len_prices);

    float best_price = prices[0];

    printf("best price = %.2f\n", best_price);

    //определим перменную с новым объявленным типом данных
    PTR_EVEN_SUM summa_chet = sum_even;

    printf("%d\n", summa_chet(1,2,3));

    //определим переменную для сортировки массивов
    float nums[10] = {1,2,10,9,3,4,5,8,7,6};
    size_t len_nums = sizeof(nums)/sizeof(*nums);
    PTR_SORT sorting_arr = get_best_price;

    sorting_arr(nums, len_nums);

    for(int i = 0; i < len_nums; ++i){
        printf("%.2f ", nums[i]);
    }
    puts("");

    //определим переменные из перечисления
    enum items_id obolon_svitle = beer;
    printf("obolon svitle : %d\n", obolon_svitle);



    



    return 0;
}