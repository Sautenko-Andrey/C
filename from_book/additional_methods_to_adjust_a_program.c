/*Дополнительные средства управления программой*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GIVE_ITEM   1
#define LEFTOVERS   2
#define EXIT    3

struct warehouse_item
{
    char *name;
    int amount;
};

typedef struct warehouse_item w_item;

unsigned char menu(void);
int square_int(int number);

int main(void)
{   
    //let's plug infinitive loop
    while(1){
        unsigned char choice = menu();
        puts("Doing something.....");
        sleep(3);

        int res = square_int(choice);
        sleep(5);

    }


    return 0;
}


unsigned char menu(void)
{   
    unsigned char user_choice;

    printf("___MENU___\n\n#1 Give item\n#2 Check leftovers\n#3 Exit\n__________\n");
    printf("Enter menu number: ");
    scanf("%hhu", &user_choice);

    return user_choice;
}

int square_int(int number)
{   
    int result;

    switch (number)
    {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        puts("This is integer in range 1 - 9!");
        result = number*number;
        printf("Square of %d is %d\n", number, result);
        return result;
        break;

    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        puts("This is integer in range 10 - 19!");
        result = number*number;
        printf("Square of %d is %d\n", number, result);
        return result;
        break;
    
    default:
        puts("Undefined argument!");
        exit(EXIT_SUCCESS);
    }
}
