//Unions

#include<stdio.h>
#include<string.h>
#define TITLE_LEN 25
#define AUTHOR_LEN 30
#define DESIGN_LEN 15
#define INT_KIND 0
#define DOUBLE_KIND 1


union {
    int i_value;
    double d_value;
} my_union;

//initializing
union {
    int age;
    float height;
    double weight;
} params = {34};

//designated  initializing
union {
    char *name;
    char *last_name;
    int id;
} person = {.id = 68488};



//Using unions to save space
struct catalog_item {
    int stock_number;
    double price;
    int item_type;

    union {

        struct {
            char title[TITLE_LEN + 1];
            char author[AUTHOR_LEN + 1];
            int num_pages;
        } book;

        struct {
            char design[DESIGN_LEN + 1];
        } mug;

        struct {
            char design[DESIGN_LEN + 1];
            int colors;
            int sizes;
        } shirt;
    } item;
};

//Using unions to build mixed data structures
typedef union {
    int i;
    double d;
} Number;

typedef struct {
    int kind;             //tag field either: INT_KIND or DOUBLE_KIND
    union {
        int i;
        double d;
    } num;
} ModernNumber;


void printModernNumber(ModernNumber value);


int main(void)
{   
    //let's store 28 in i_value member
    my_union.i_value = 28;

    //let's store 34.96 in d_value
    my_union.d_value = 34.96;

    printf("d_value = %.2f\n", my_union.d_value);

    //getting i_value
    printf("i_value = %d\n", my_union.i_value);   //1202590843  ??meaningless


    //let's work with params
    printf("Age: %d years old\n", params.age);

    params.height = 192.0;
    printf("Height: %.2f cm\n", params.height);

    params.weight = 85.95;
    printf("Weight: %.2f kg\n", params.weight);
    printf("Height: %.2f cm\n", params.height);   //akward behavior

    printf("Person's id: %d\n", person.id);

    person.last_name = "Chykqumeka";
    printf("Last name: %s\n", person.last_name);

    //working with catalog
    struct catalog_item my_gift;

    my_gift.stock_number = 3206;
    my_gift.item_type = 'b';
    my_gift.price = 40.50;
    strncpy(my_gift.item.book.author, "K.N. King", AUTHOR_LEN);
    strncpy(my_gift.item.book.title, "C Programming", TITLE_LEN);
    my_gift.item.book.num_pages = 829;

    printf("My order:\n---------\n"
          "Stock number: %d\nBook: %s\n", my_gift.stock_number, my_gift.item.book.title);

    struct catalog_item my_mug;
    strncpy(my_mug.item.mug.design,"Pig", DESIGN_LEN);

    //this design is also in shirt
    printf("Mug's design: %s\n", my_mug.item.mug.design);    //Pig
    printf("Shirt's design: %s\n", my_mug.item.shirt.design);   //Pig

    //array with different types of data
    Number spec_array[10];

    //first element gonna to be 28
    spec_array[0].i = 28;

    //second element gonna to be 3.14
    spec_array[1].d = 3.14;

    //third element gonna to be 100
    spec_array[2].i = 100;


    //using ModernNumber
    ModernNumber mixed_array[5];

    mixed_array[0].kind = INT_KIND;
    mixed_array[0].num.i = 150;

    mixed_array[1].kind = DOUBLE_KIND;
    mixed_array[1].num.d = 3.14;

    for (int i = 0; i < 5; ++i){
        printModernNumber(mixed_array[i]);
    }
    putchar('\n');



    return 0;
}

void printModernNumber(ModernNumber value)
{
    if (value.kind == INT_KIND){
        printf("%d ", value.num.i);
    }
    else{
        printf("%.2f ", value.num.d);
    }
}