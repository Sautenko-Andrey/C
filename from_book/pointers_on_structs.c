// СОЗДАНИЕ УКАЗАТЕЛЕЙ НА СТРУКТУРЫ
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct employee
{
    char *name;
    int id;
};

struct department
{
    char *dep_name;
    struct employee empls[3];
};

struct product
{
    char *item_name;
    float prices[9];
};

typedef struct department DEP;
typedef struct product product;

int main(void)
{   
    //объявим указатель на структуру
    struct employee *emp_ptr;

    //объявим один экземпляр типа employee
    struct employee user_Chaus;

    //после этого уже можно инициализировать указатель
    emp_ptr = &user_Chaus;//теперь у нас есть указатель на структуру user_Chaus

    emp_ptr->name = "Alex Chausov";
    emp_ptr->id = 36;

    printf("Employee's name: %s\nID: %d\n----------------\n", emp_ptr->name, emp_ptr->id);


    product coca_cola = {
        "Coca Cola 2l",
        {50.00, 49.75, 48.09, 49.99, 51.25, 48.50, 53.15, 50.99, 46.75}
    };

    printf("Item: %s\nAtb: %.2f uah\nEKO: %.2f uah\n",\
coca_cola.item_name, coca_cola.prices[0], coca_cola.prices[1]);

    //объявим указатель на структуру
    product *product_ptr = &coca_cola;

    printf("\nItem: %s\nAtb: %.2f uah\nEko: %.2f uah\n",\
product_ptr->item_name, product_ptr->prices[0], product_ptr->prices[1]);

    //поменяем цену у fozzy
    product_ptr->prices[8] = 100.00;

    //распечатаем все цены
    for(int i = 0; i < sizeof(product_ptr->prices) / sizeof(*product_ptr->prices); ++i){
        printf("#%d %.2f usd\n", i + 1, product_ptr->prices[i]);
    }

    //изменим название продукта
    product_ptr->item_name = "Fanta 2l";
    printf("Item: %s\n", product_ptr->item_name);
    //изменим имя напрямую
    coca_cola.item_name = "Sprite";
    printf("Item: %s\n", product_ptr->item_name);

    //обнулим все цены
    for (int i = 0; i < 9; ++i){
        product_ptr->prices[i] = 0;
    }

    //посмотрим все цены
    for(int i = 0; i < 9; ++i){
        printf("%.2f ", product_ptr->prices[i]);
    }
    putchar('\n');

    return 0;
}