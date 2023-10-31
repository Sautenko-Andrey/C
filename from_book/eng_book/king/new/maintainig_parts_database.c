//Maintaining a Parts Database (revisited)
#include<stdio.h>
#include<stdlib.h>
#include"readline.h"

#define NAME_LEN 30

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;    //points to first part

struct part* find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*
    main: Prompts the user to enter an operation code,
          then calls a function to perform the requested
          action. Repeats untill the user enters the 
          command 'q'. Prints an error message if the user
          enters an illegal code.

*/

int main(void){

    char code;

    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while(getchar() != '\n'){    //skips to end of line
            ;                       
        }
        switch (code)
        {
        case 'i':
            insert();
            break;

        case 's':
            search();
            break;

        case 'u':
            update();
            break;

        case 'p':
            print();
            break;

        case 'q':
            return 0;
        
        default:
            printf("Illegal code.\n");
        }
        printf("\n");
    }
}

/*
    find_part: Looks up a part number in the inventory list.
               Returns a pointer to the node containing the
               part number; if the part number is not found,
               returns NULL.
*/
struct part* find_part(int number)
{
    struct part *ptr;

    for(ptr = inventory; ptr != NULL && number > ptr->number; ptr = ptr->next){
        ;
    }

    if(ptr != NULL && number == ptr->number){
        return ptr;
    }

    return NULL;
}

/*
    insert: Prompts the user for information about a new part
            and then inserts the part into the inventory list.
            The list remains sorted by part number. Prints an
            error message and returns prematurely if the part
            already exists or space could not be allocated
            for the part.
*/
void insert(void)
{
    struct part *current;
    struct part *previous;
    struct part *new_node;

    new_node = malloc(sizeof(struct part));

    if(new_node == NULL){
        fprintf(stderr, "Error: Database is full.Can't add more parts\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for(current = inventory, previous = NULL; current != NULL && new_node->number > current->number;
        previous = current, current = current->next){
            ;
        }

    if(current != NULL && new_node->number == current->number){
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = current;
    if(previous == NULL){
        inventory = new_node;
    }
    else{
        previous->next = new_node;
    }
}

/*
    search: Prompts the user to enter a part number,
            then looks up the part in the database.
            If the part exists, prints the name and
            quantity on hand; if not prints an error
            message.
*/
void search(void)
{
    int number;
    struct part *ptr;

    printf("Enter part number: ");
    scanf("%d", &number);

    ptr = find_part(number);
    if(ptr != NULL){
        printf("Part name: %s\n", ptr->name);
        printf("Quantity on hand: %d\n", ptr->on_hand);
    }
    else{
        printf("Part not found\n");
    }
}

/*
    update: Prompts the user to enter a part number.
            Prints an error message if the part doesn't
            exist; otherwise prompts the user to enter
            change in quantity on hand and updates the
            database.
*/

void update(void)
{
    int number;
    int change;
    struct part *ptr;

    printf("Enter part number: ");
    scanf("%d", &number);

    ptr = find_part(number);
    if(ptr!=NULL){
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        ptr->on_hand += change;
    }
    else{
        printf("Part not found.\n");
    }
}

/*
    print: Prints a listing of all parts in the database,
           showing the part number, part name, and quantity
           on hand. Part numbers will appear in ascending order.
*/

void print(void)
{
    struct part *ptr;

    printf("Part number\tPart name\tQuantity on hand\n");

    for(ptr = inventory; ptr != NULL; ptr = ptr->next){
        printf("%7d        %-25s%11d\n", ptr->number, ptr->name, ptr->on_hand);
    }
}