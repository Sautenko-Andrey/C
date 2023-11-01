//Pointers to pointers

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 25

struct item {
    char name[MAX_LEN + 1];
    float price;
    int on_hand;
    struct item *next;
};

void add_itemV2(struct item **warehouse, char *new_name, float new_price, int new_on_hand);
void add_itemV1(struct item *warehouse, char *new_name, float new_price, int new_on_hand);
void show_storage(struct item *warehouse);


int main(void)
{   
    struct item *storage = NULL;
    add_itemV2(&storage, "banana", 46.70, 50);
    add_itemV2(&storage, "apple", 12.00, 1);
    show_storage(storage);
    putchar('\n');

    return 0;
}


void add_itemV1(struct item *warehouse, char *new_name, float new_price, int new_on_hand)
{
    struct item *new_item = malloc(sizeof(struct item));

    if(new_item == NULL){
        fprintf(stderr, "Error: memory allocation error in add_itemV1().\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_item->name, new_name);
    new_item->price = new_price;
    new_item->on_hand = new_on_hand;

    new_item->next = warehouse;
    warehouse = new_item;
}

void add_itemV2(struct item **warehouse, char *new_name, float new_price, int new_on_hand)
{
    struct item *new_item = malloc(sizeof(struct item));

    if(new_item == NULL){
        fprintf(stderr, "Error: memory allocation error in add_itemV1().\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_item->name, new_name);
    new_item->price = new_price;
    new_item->on_hand = new_on_hand;

    new_item->next = *warehouse;
    *warehouse = new_item;
}

void show_storage(struct item *warehouse)
{
    struct item *ptr;

    printf("Name\tPrice\tOn hand\n");
    for(ptr = warehouse; ptr != NULL; ptr = ptr->next){
        printf("%s\t%.2f\t%d\n", ptr->name, ptr->price, ptr->on_hand);
    }
}