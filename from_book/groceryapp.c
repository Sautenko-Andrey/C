#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"groceryapp.h"

#define ITEM_LENGTH 75
#define ITEMS_AMOONT

#define SALO_1_KG 1
#define POTATO_1_KG 2
#define BEER_OBOLON_PREM_1_1_l 3

struct prices {
    float atb_price;
    float eko_price;
    float varus_price;
    float silpo_price;
    float ashan_price;
    float novus_price;
    float metro_price;
    float nk_price;
    float fozzy_price;
};

typedef struct prices prices;

struct item_data {
    char *item_name;
    prices all_prices;
};

typedef struct item_data item_data;

//const char becon[] = "сало соленое, 1 кг";
//const char potato[] = "картофель, 1 кг";
//const char beer_Obolon_premium_1_1_l_pl[] = "пиво Оболонь Премиум 1.1 литр в пластике";

item_data all_products[ITEMS_AMOONT] = {
    {
       "сало соленое, 1 кг",
       199.29,210.55,200.00,175.80,189.99,211.00,205.00,205.95,215.75 
    },

    {
        "картофель, 1 кг",
        15.00, 14.00, 13.00, 15.75, 18.10, 16.30, 14.25, 15.15, 15.99  
    },

    {
        "пиво Оболонь Премиум 1.1 литр в пластике",
        28.00, 29.00, 30.00, 28.99, 27.75, 30.15, 32.25, 33.75, 30.10
    }
};

extern char user[];

char* user_request(void)
{   
    /*Function which get request from user from the keyboard and return it.*/

    char *searced_item = malloc(sizeof(char) * ITEM_LENGTH);

    printf("%s, welcome to the www.groceryapp.com.\n-----------------------------------\n", user);
    sleep(3);
    printf("Enter product name for searching: ");
    
    fgets(searced_item, ITEM_LENGTH, stdin);

    searced_item[strlen(searced_item) - 1] = '\0';

    return searced_item;
}

void NN_job(char *user_request)
{
    puts("Searching...");
    sleep(2);
    puts("Processing...");
    sleep(5);

    //comparing strings
    if (strncmp(user_request, all_products[0].item_name, strlen(user_request)) == 0){
        printf("\n\nProduct: %s\n--------\n", all_products[0].item_name);
        printf("Prices:\n-------\n");
        printf("Atb: %.2f uah\n", all_products[0].all_prices.atb_price);
        printf("Eko: %.2f uah\n", all_products[0].all_prices.eko_price);
        printf("Varus: %.2f uah\n", all_products[0].all_prices.varus_price);
        printf("Silpo: %.2f uah\n", all_products[0].all_prices.silpo_price);
        printf("Ashan: %.2f uah\n", all_products[0].all_prices.ashan_price);
        printf("Novus: %.2f uah\n", all_products[0].all_prices.novus_price);
        printf("Metro: %.2f uah\n", all_products[0].all_prices.metro_price);
        printf("NK: %.2f uah\n", all_products[0].all_prices.nk_price);
        printf("Fozzy: %.2f uah\n", all_products[0].all_prices.fozzy_price);
    }
    else if (strncmp(user_request, all_products[1].item_name, strlen(user_request)) == 0){
        puts("It's a potato.");
    }
    else if (strncmp(user_request, all_products[2].item_name, strlen(user_request)) == 0){
        puts("It's a beer Obolon Premium 1.1 l");
    }
    else{
        puts("I didn't find your item. Sorry.");
    }
}