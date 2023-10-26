#include<stdio.h>
#include"readline.h"


#define LEN_NAME 25
#define MAX_PARTS 100

struct item {
    int ident_number;
    char name[LEN_NAME + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   //number of parts currently stored

int find_part(int ident_number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*
    main: Prompts the user to enter an operation code,
          the calls a function to perform the requested
          action. Repeats untill the user enters the 
          command 'q'. Prints an error message if the user
          enter an illegal code.
*/

int main(void)
{   
    char code;

    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);   //" %c" allows scanf to skip over white space before reading
                               // the operation code. The space in the  format string is
                               //crucial. Without it scanf would sometimes read the new-line
                               //character that terminated a previous line of input. 

        while( getchar() != '\n' ){
            ;                             //skips to end of line
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
            printf("Illegal code\n");
        }
    }
}

/*
    find_part(): Looks up a part number in the inventory array.
                 Returns the array index if the part number is
                 found; otherwise returns -1
*/
int find_part(int number)
{   
    int i;

    for(i = 0; i < num_parts; i++){
        if(inventory[i].ident_number == number){
            return i;
        }
    }

    return -1;
}

/*
    insert(): Promts the user for information about a new part
              and then inserts the part into the datebase. Prints
              an error message and returns prematurely if the part
              already exists or the database is full.
*/
void insert(void)
{
    int part_number;

    if(num_parts == MAX_PARTS){
        printf("Datebase is full. Can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if(find_part(part_number) >= 0){
        printf("Part already exist.\n");
        return;
    }

    inventory[num_parts].ident_number = part_number;

    printf("Enter part name: ");
    read_line(inventory[num_parts].name, LEN_NAME);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

/*
    search(): Promts the user to enter a part number,
              then looks up the part in the database.
              If the part exists, prints the name and
              quantity on hand. If not, prints an error
              message.           
*/
void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);

    if (i >= 0){
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else{
        puts("Part not found.");
    }
}

/*
    update(): Promts the user to enter a part number.
              Prints an error message if the part number
              doesn't exist; otherwise prompts the user
              to enter a change in quantity on hand and
              updates the database.
*/
void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if(i >= 0){
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else{
        puts("Part not found.");
    }
}

/*
    print(): Prints a listing of all parts in the database,
             shoing the part number, part name and quantity
             on hand. Parts are printed in the order in which
             they were entered into the database
*/
void print(void)
{
    int i;

    printf("Part number  Part name\t\t"
          "Quantity on hand\n");

    for(i = 0; i < num_parts; ++i){
        printf("%7d    %-25s%11d\n", inventory[i].ident_number,
              inventory[i].name, inventory[i].on_hand);
    }
}