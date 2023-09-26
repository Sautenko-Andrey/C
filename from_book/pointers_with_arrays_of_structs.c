#include<stdio.h>

#define AMOUNT  3

struct product
{
    char *name;
    float price;
};

typedef struct product product;


int main(void)
{   
    //объявим массив структур product
    product all_products[AMOUNT] = {
        "banana", 46.50,
        "sour", 18.99,
        "potato", 21.25
    };

    //далее объявим указатель на структуру типа product и присвоим ему адрес первого элемента
    //в массиве all_product
    product *ptr = all_products;

    //выведем на экран первый элемент массива
    printf("%s costs %.2f\n", ptr->name, ptr->price);

    //второй элемент массива
    printf("%s costs %.2f\n", (ptr + 1)->name, ++ptr->price);


    //выведем все цены через цикл
    printf("\n--------------\n");
    for(int i = 0; i < AMOUNT; ++i){
        printf("%s = %.2f uah, adress : %p\n", ptr->name, ptr->price, ptr);
        ptr++;
    }

}
