#include<stdio.h>
#include"struct_funcs.h"

#define MAX  25

struct product {
    char name[MAX + 1];   //doesn't conflict with employee name
    int on_hand;
    float price;
};

void display_product(struct product item)
{
    printf("Name: %s\n, On hand: %d\nPrice: %.2f $\n",item.name, item.on_hand, item.price);
}