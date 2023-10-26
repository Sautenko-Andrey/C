//Enumerations

#include<stdio.h>

// #define SUIT int
// #define CLUBS 0
// #define DIAMONDS 1
// #define HEARTS 2
// #define SPADES 3

//alternative and more proper way

typedef struct {
    char a;
    int b;
} SimpleStruct;

enum suit {CLUBS = 0, DIAMONDS = 1,HEARTS = 2, SPADES = 3} card_1,card_2;
typedef enum {GOALKEEPER = 0, DEFENDER = 1, MIDFIELDER = 2, FORWARD = 3} Position;
typedef enum {ZERO, ONE, TWO, THREE} Counter;

typedef struct {
    enum {INT_KIND, DOUBLE_KIND} kind;
    union {
        int i_val;
        double d_val;
    } num;
} ModerNum;

int main(void)
{   
    //SUIT card = HEARTS;

    card_1 = HEARTS;

    enum suit card_2 = CLUBS;

    printf("card_1 = %d\n", card_1);

    Position jorginho = MIDFIELDER;

    Counter one = ONE;
    printf("one = %d\n", one);

    ModerNum my_value;
    my_value.kind = INT_KIND;
    my_value.num.i_val = 55;
    printf("value = %d\n", my_value.num.i_val);

    printf("Size = %ld\n", sizeof(SimpleStruct));   //8 bytes


    return 0;
}