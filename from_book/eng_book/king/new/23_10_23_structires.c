//Structures
#include<stdio.h>
#include<string.h>

#define DEBUG1
#define NEXT putchar('\n')

#define NAME_LEN 20

struct product {
    char name[NAME_LEN + 1];   //doesn't conflict with employee name
    int on_hand;
    float price;
} item_1 = {"Potato", 100, 16.95},
  item_2 = {"Carrot", 28, 35.00};

struct employee {
    char name[NAME_LEN + 1];   //does't conflict with product name
    int id;
} chausov = {"Alex Chausov", 2707},
  tereshuk = {"Alex Tershuk", 2911};

//declaration struct using typedef
typedef struct {
    char name[NAME_LEN + 1];
    char position[4];
    char club[NAME_LEN + 1];
    float worth;
} Player;                        // this is struct Player


void display_product(struct product item);
struct product construct_product(const char *name, int amount, float price);

int medeian(int x, int y, int z);

int main(void)
{   

    //designated structs
    struct employee kubasov = {.id = 0506, .name = "Artem Kubasov"};

    //
    printf("Item: %s, %d, %.2f\n", item_1.name, item_1.on_hand, item_1.price);

    //changes values in structure
    struct product coca_cola = {.name = "Coca Cola", .price = 64.00, .on_hand = 359};

    strncpy(coca_cola.name, "Coca Cola 2l", NAME_LEN);
    coca_cola.on_hand = 350;
    coca_cola.on_hand++;

    printf("Item #1\n-------\nName: %s\nOn hand: %d\n", coca_cola.name, coca_cola.on_hand);

    #ifdef DEBUG
    printf("Enter a new price: ");
    scanf("%f", &coca_cola.price);

    printf("A new price of Coca Cola is %.2f $\n", coca_cola.price);
    #endif

    //another one common operation
    item_1.on_hand = item_2.on_hand;

    struct product onion = {.name = "Onion", .on_hand = 14, .price = 45.50};
    struct product beet = {.on_hand = 56, .price = 29.99, .name = "Beet"};

    onion.price = beet.price;

    
    printf("Onion price: %.2f\nBeet price: %.2f\n", onion.price, beet.price);

    //define Player
    Player declan_rice = {.name = "Declan Rice",
                          .club = "Arsenal",
                          .worth = 113000000.0,
                          .position = "dcm"
    };

    puts(declan_rice.name);

    //testing function with struct as a parameter
    display_product(onion);

    //let's create struct via construct_product function
    struct product banana = construct_product("Banana", 150, 35.75);
    display_product(banana);

    int res = medeian(10,20,30);
    printf("res = %d\n", res);


    //nested structers
    struct user_name {
        char first_name[NAME_LEN + 1];
        char last_name[NAME_LEN + 1];
    };

    struct person {
        struct user_name full_name;   //nested structure
        int age;
        char sex;
    };

    struct person bellingam = {
        {"Jude", "Bellingam"},
        19,
        'm'
    };


    //arrays of structers
    struct person all_players[3] = {
        {{"Rhys", "James"}, 22, 'm'},
        {{"Kyle", "Walker"}, 32, 'm'},
        {{"Olly", "Watkins"}, 27, 'm'}
    };

    NEXT;
    NEXT;

    //accessing to names
    for (int i = 0; i < 3; ++i){
        printf("%s %s\n", all_players[i].full_name.first_name, all_players[i].full_name.last_name);
    }


    //pointers on structs
    struct person *ptr;
    ptr = all_players;

    




    return 0;
}


void display_product(struct product item)
{
    printf("\n\nName: %s\nOn hand: %d\nPrice: %.2f $\n",item.name, item.on_hand, item.price);
}

struct product construct_product(const char *name, int amount, float price)
{
    struct product item;
    strncpy(item.name, name, NAME_LEN);
    item.on_hand = amount;
    item.price = price;

    return item;
}

int medeian(int x, int y, int z)
{
    int result;
    result = (x + y + z) / 3;
    return result;
}