#include<stdio.h>


struct customer
{
    char name[40];
    char phone[14];
};

struct user_order
{
    struct customer user;
    int item_id;
    int amount;
    float price;
};

struct footballer
{
    char name[20];
    char position[20];
    unsigned char number;
} saka = {
    "Bukayo Saka",
    "Winger",
    7
};

typedef struct customer customer;
typedef struct user_order order;


int main(void)
{   
    //воспользуемся структурой customer
    customer user = {"Oksana", "+30671235478"};

    //let's review result
    printf("Name: %s\nPhone: %s\n", user.name, user.phone);


    //let's use struct user_order
    order user_purchase = {
        {"Kate", "+380935647821"},
        1136,
        2,
        2100.99
    };

    //let's review what we've got
    puts("___________________");
    printf("| Customer's order |:\n_____________________\n\
Name: %s\nMob.: %s\n#####################\n\
Item's ID: %d\nAmount: %d\nPrice: %.2f usd\n",\
    user_purchase.user.name, user_purchase.user.phone,\
    user_purchase.item_id,user_purchase.amount, user_purchase.price);


    //let's review Saka
    puts(saka.name);
    printf("%s , %s , %d\n", saka.name, saka.position, saka.number);


    //let's declare and assign array of structers
    order orders_list[100] = {
        {
            {"Andrey", "+380950180611"},
            3131,
            1,
            99.99
        },

        {
            {"Artur", "+30999014563"},
            1001,
            3,
            156.50
        }
    };

    for(int i = 0; i < 2; ++i){
        printf("\n____________\n%s\n%s\n%d\n%d\n%.2f\n___________\n",\
        orders_list[i].user.name,orders_list[i].user.phone,\
        orders_list[i].item_id, orders_list[i].amount, orders_list[i].price);
    }



    return 0;
}