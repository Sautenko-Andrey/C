//Объединения
#include<stdio.h>

#define INTEGER 'I'
#define FLOAT   'F'

#define EUR 'E'
#define USD 'U'
#define GRN 'G'

#define DEFENDER    'D'
#define MIDFIELDER  'M'
#define STRIKER 'S'

union person
{
    char *name;
    int id;
};

struct value
{
    char type;
    union shared_value{
        int int_value;
        float float_value;
    }shared;
};

struct currency_exchange
{
    char type;
    union sort_of_value{
        float eur;
        float usd;
        float grn;
    } value;
};

struct player
{
    char position;
    union variety{
        char *defender;
        char *midfielder;
        char *forward;
    } role;
};

void print_value(struct value some_x);
void print_money(struct currency_exchange cash);
void print_player(struct player x_player);

int main(void)
{   
    //проинициадизируем объединение person
    union person alex = {"Chaus"};

    printf("Name: %s\nID: %d\n", alex.name, alex.id);

    alex.id = 36;
    printf("ID: %d\n",alex.id);


    //болле сложный вариант использования структур
    struct value my_dig;
    my_dig.type = FLOAT;
    my_dig.shared.float_value = 13.05;
    print_value(my_dig);

    //еще одна переменная
    struct value my_num;
    my_num.type = 'X';
    my_num.shared.float_value = 3.69;
    print_value(my_num);


    //обменик валют.Переведем гривны в доллары
    struct currency_exchange my_money, your_money;
    my_money.type = USD;
    my_money.value.usd = 100.00f;
    print_money(my_money);

    your_money.type = EUR;
    your_money.value.eur = 100.00f;
    print_money(your_money);

    //let's play with players
    struct player j_timber, d_rice;
    j_timber.position = DEFENDER;
    d_rice.position = MIDFIELDER;

    print_player(j_timber);
    print_player(d_rice);


    return 0;
}

void print_value(struct value some_x)
{
    printf("Value is ...");
    switch (some_x.type)
    {
    case INTEGER:
        printf("integer --- %d\n", some_x.shared.int_value);
        break;

    case FLOAT:
        printf("float --- %.2f\n", some_x.shared.float_value);
        break;
    
    default:
        puts("Unknown type");
        break;
    }
}

void print_money(struct currency_exchange cash)
{
    printf("We are converting money in...");
    switch (cash.type)
    {
    case EUR:
        printf("euro...result is %.2f\n", cash.value.eur * 40.00);
        break;

    case USD:
        printf("euro...result is %.2f\n", cash.value.usd * 37.00);
        break;
    
    default:
        puts("Unknown value....");
        break;
    }
}

void print_player(struct player x_player)
{
    printf("You have created ");
    switch (x_player.position)
    {
    case DEFENDER:
        printf("defender player ");
        x_player.role.defender = "clearence ";
        printf("with %s role.\n", x_player.role.defender);
        break;
    
    case MIDFIELDER:
        printf("midfield player ");
        x_player.role.midfielder = "ball control";
        printf("with %s role.\n", x_player.role.midfielder);
        break;

    case STRIKER:
        printf("forward player.\n");
        break;

    default:
        printf("undefined-position player.");
        break;
    }
}