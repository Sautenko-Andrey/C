#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item
{
    int *id;
    float *value;
} user_item;

struct friend
{
    char *name;
    int age;
};

struct footballer
{
    char *name;
    char *position;
};

struct club
{   
    char club_name[20];
    struct footballer players[3];
};

typedef struct friend friend;
typedef struct club FC;



int main(void)
{   
    //let's use struct item
    int user_id = 2806;
    float user_price = 100.00f;

    user_item.id = &user_id;        //assigning pointers
    user_item.value = &user_price;

    printf("%d, %.2f\n", *user_item.id, *user_item.value);
    printf("Adress orig : %p, adress via pointer: %p\n", &user_id, user_item.id);
    
    if(&user_price == user_item.value){
        puts("Same adress!");
    }


    //let's use struct friend
    friend alex = {"Alex", 35};

    //let's review
    printf("name: %s , age: %d\n", alex.name, alex.age);

    //one more friend
    char name_ch[] = "Chaus";
    friend chaus = {name_ch, 36};
    //let's display
    printf("%s , %d\n", chaus.name, chaus.age);


    //using FC
    FC arsenal = {
        "Arsenal FC",
        {
            "Bukayo Saka","winger",
            "Declan Rice", "midfielder",
            "Kai Havertz", "attacking midfielder"
        }
    };

    printf("Club: %s\nPlayers:\n%s - %s\n%s - %s\n%s - %s\n",\
arsenal.club_name, arsenal.players[0].name, arsenal.players[0].position,\
arsenal.players[1].name, arsenal.players[1].position, arsenal.players[2].name,\
arsenal.players[2].position);

    char *some_text_pointer = "Welcome, Declan Rice!";
    puts(some_text_pointer);

    return 0;
}