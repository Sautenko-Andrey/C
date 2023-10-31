//Linked lists
#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

//creating new node and add it into the beggining of the linked list
struct node* add_to_list(struct node *list, int new_value);

//creating linked list containing numbers entered by the users
struct node* read_numbers(void);

//searching a list for an integer val
struct node* search_list(struct node* list, int val);

//alternative version
struct node* search_list_V2(struct node* list, int val);

//deleting a node from a linked list
struct node* delete_from_list(struct node *list, int del_val);


int main(void)
{   
    //variable that always point to the first node
    struct node *first = NULL;   //list is initially empty

    //variable that can point to the node temporarily, untill it has been inserted into the list
    struct node *new_node;

    //allocating memory for the new_node
    new_node = malloc(sizeof(struct node));

    //storing data in the node
    new_node->value = 10;

    //inserting a node at the begining of a linked list

    //modifying new_node. its next will point to the previous first node in the list
    new_node->next = first;

    //making first points to the new_node
    first = new_node;

    //let's add one more node into the list
    //we should allocate mamory one more time
    new_node = malloc(sizeof(struct node));

    new_node->value = 20;
    new_node->next = first;
    first = new_node;


    //pointer to the first node in the new  linked list(another one)
    struct node *new_first = NULL;

    new_first = add_to_list(new_first, 99);
    new_first = add_to_list(new_first, 28);
    new_first = add_to_list(new_first, 34);
    new_first = add_to_list(new_first, 6);
    new_first = add_to_list(new_first, 96);

    struct node *my_node = search_list_V2(new_first, 28);
    printf("My node:\nValue: %d\nNext node adress: %p\n", my_node->value, my_node->next);

    new_first = delete_from_list(new_first, 6);


    return 0;
}

struct node* add_to_list(struct node *list, int new_value)
{
    //*list is a pointer - a pointer to the first node in the old list
    //new_value - the integer to be stored in the new node

    //creating the new_node
    struct node *new_node;

    new_node = malloc(sizeof(struct node));

    if(new_node == NULL){
        fprintf(stderr, "Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = new_value;

    new_node->next = list;

    return new_node;
}

struct node* read_numbers(void)
{   
    /*The numbers will be in reverse order.*/

    //declearing the beggining of the linked list
    struct node *first = NULL;

    //variable for a new value, which will be added into the linked list
    int new_value;

    printf("Enter a series of integers (0 to terminate): ");
    for(;;){
        scanf("%d", &new_value);
        if(new_value == 0){
            return first;
        }
        first = add_to_list(first, new_value);
    }
}

struct node* search_list(struct node* list, int val)
{
    struct node *ptr;

    for(ptr = list; ptr != NULL; ptr = ptr->next){
        if (ptr->value == val){
            return ptr;
        }
    }
    return NULL;
}

struct node* search_list_V2(struct node* list, int val)
{
    while(list != NULL && list->value != val){
        list = list->next;
    }
    return list;
}

struct node* delete_from_list(struct node *list, int del_val)
{
    struct node *current;    //pointer for a current node
    struct node *previous;   //pointer for a previous node

    for( current = list, previous = NULL;
         current != NULL && current->value != del_val;
         previous = current, current = current->next ){
            ;
        }
    
    if(current == NULL){
        return list;                    //del_val was not found
    }
    if(previous == NULL){
        list = list->next;              //del_val is in the first node
    }
    else{
        previous->next = current->next;       //del_val is in some other node
    }

    free(current);    //realising memory
    return list;
}