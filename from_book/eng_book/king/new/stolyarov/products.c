#include<stdio.h>
#include<stdlib.h>

#define NAME_LEN 50

union amount {
    float weight;
    unsigned item;
};

struct product {
    char name[NAME_LEN + 1];
    float price;
    union amount on_hand;
    struct product *next;
};

int compare_str(const char *first_str, const char *sec_str);
void copy_str(char *dest, const char *source, unsigned num);
struct product* create_product(const char *prod_name, float prod_price, char amount_mode, float prod_on_hand);
void add_to_list(struct product **db, struct product *new_item);
void display_data(const struct product *db);
float average_price(const struct product *db);
void delete_db(struct product *db);
void delete_item(struct product *db, const char *del_name);

int main(void)
{   
    /* Database */
    struct product *db = NULL;

    /* Creating a new products*/
    /* Potato */
    struct product *potato = create_product("Potato 1 kg", 24.55, 'w', 50.00);
    
    /* Banana */
    struct product *banana = create_product("Banana 1 kg", 45.75, 'w', 125.25);
    
    /* Beer */
    struct product *beer = create_product("Beer Amstel Light", 34.00, 'i', 1500);

    /* Adding products to the DB */
    add_to_list(&db,potato);
    add_to_list(&db,banana);
    add_to_list(&db, beer);    

    /* Displaying all products in DB */
    display_data(db);

    /* Displaying average price in DB */
    printf("Average price: %.2f $\n----------------------\n", average_price(db));

    /* Deleting DB */
    delete_db(db);

    return 0;
}

/* Create a new node */
struct product* create_product(const char *prod_name, float prod_price, char amount_mode, float prod_on_hand)
{

    if(amount_mode != 'w' && amount_mode != 'i'){
        fprintf(stderr, "Error: unsupported amount_mode\n");
        exit(EXIT_FAILURE);
    }

    struct product *new_product = malloc(sizeof(struct product));
    if( new_product == NULL ){
        fprintf(stderr,"Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    /* Filling a node */
    copy_str(new_product->name, prod_name, NAME_LEN);
    new_product->price = prod_price;
    
    if(amount_mode == 'w'){
        new_product->on_hand.weight = prod_on_hand;
    }
    else{
        new_product->on_hand.item = (unsigned)prod_on_hand;
    }
    
    return new_product;
}

/* String copy */
void copy_str(char *dest, const char *source, unsigned num)
{
    const char *ptr;
    int i;

    for(ptr = source, i = 0; i < num; i++, ptr++, dest++){
        *dest = *ptr;
    }
    *dest = '\0';
}


/* Adds a new node to the linked list */
void add_to_list(struct product **db, struct product *new_item)
{   
    new_item->next = *db;
    *db = new_item;
}

/* Prints all data in linked list */
void display_data(const struct product *db)
{
    int i;    

    for(i = 1; db; db = db->next, i++){
        printf("#%d\t%s\n", i, db->name);
    }
    puts("------------------------------");
}

/* Counts average price in DB */
float average_price(const struct product *db)
{
    float total = 0;
    int i;
    
    for(i = 0; db; db = db->next, i++){
        total += db->price;
    }

    return total / i;
}

/* Deletes db */
void delete_db(struct product *db)
{
    if(db){
        delete_db(db->next);
        free(db);
    }
}



int compare_str(const char *first_str, const char *sec_str)
{
    for( ; first_str && sec_str; first_str++, sec_str++ ){
        if ( *first_str != *sec_str ){
            return 0;  /* 0 if strings don't mutch */
        }
    }

    return 1;
}
