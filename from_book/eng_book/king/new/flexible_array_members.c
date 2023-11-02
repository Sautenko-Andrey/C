//Flexible array members

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

struct person {
    char name[MAX];
    int id;
};

//alternative
struct person2 {
    char name[1];   //dammy value 1
    int id;
};

//flexible aeeay member 
struct employee {

    int id;
    char name[];    //if it's a last member in struct len of array may be ommited
};

int main(void)
{   
    //let's do the struct hack
    //suppose we need in name 4 bytes
    // struct person2 *alex = malloc(sizeof(struct person2) + 4);
    // strncpy(alex->name, "Alex", 4);
    // alex->id = 1345;

    // struct person2 *andrey = malloc(sizeof(struct person2) + 6);
    // strncpy(alex->name, "Andrey", 6);
    // alex->id = 1345123;

    // printf("Name: %s\nID: %d\n", alex->name, alex->id);
    // printf("Name: %s\nID: %d\n", andrey->name, andrey->id);

    //alternative!!!

    struct employee *alisa = malloc(sizeof(struct employee) + 6);
    if (alisa == NULL){
        printf("Error : memory allocation is failed.\n");
        exit(EXIT_FAILURE);
    }
    alisa->id = 155;
    strcpy(alisa->name, "Alisa");
    printf("Name: %s\nID: %d\n", alisa->name, alisa->id);


    return 0;
}