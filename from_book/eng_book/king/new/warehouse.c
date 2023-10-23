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
    return 0;
}