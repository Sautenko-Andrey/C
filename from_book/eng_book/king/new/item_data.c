#include<stdio.h>
#include<string.h>

#define AMOUNT 3

struct data {
    char *name;
    float price;
    unsigned lettovers;
};

typedef struct data data;

void modify_str(char *str);

int main(int argc, char *argv[])
{

    data all_products[AMOUNT] = {
        {"Snickers", 15.99, 54},
        {"Beer Hike light 0.5l", 25.50, 100},
        {"Pork 1 kg", 257.85, 34}
    };


    int i, j;
    for(i = 1; i < argc; ++i){
        for(j = 0; j < AMOUNT; ++j){
            if( (strcmp(argv[i], all_products[j].name)) == 0 ){
                printf("Name: %s\nPrice: %.2f\nAmount: %u\n\n", all_products[j].name, all_products[j].price, all_products[j].lettovers);
                break;
            }
        }
        // if(j == AMOUNT){
        //     printf("None\n");
        // }
    }

    char name[] = "Andrey";
    modify_str(name);
    puts(name);

    return 0;
}

void modify_str(char *str)
{
    *str = 'Q';
}