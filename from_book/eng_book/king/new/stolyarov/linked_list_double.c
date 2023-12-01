#include<stdio.h>
#include<stdlib.h>


struct item {
    double data;
    struct item *previous, *next;
};


int main(void)
{
    struct item *first = NULL;  /* Start of the linked list */
    struct item *last = NULL;   /* End of the linked list */
    struct item *current = NULL; /* Pointer on current element in the linked list */
    struct item *tmp, *tmp2;            /* Temporary pointer for the convenience */

    /* Adding a new node into the list in the beggining */
    double value = 100.999;
    double value2 = 333.3;    

    tmp = malloc(sizeof(struct item));
    if(tmp == NULL){
        fprintf(stderr, "Error: memory allocation failed.\n");
        return 1;
    }

    tmp->data = value;     /* putting a value */
    tmp->previous = NULL;  /* Previous will be NULL, coz element addint in the top */
    tmp->next = first;    /* Next to first */
    if(first){           /* if first is not the last element */
        first->previous = tmp;   /* Previous for first will be a new node */
    }
    else{
        last = tmp;    /* else a new node will be the last element */
    }
    first = tmp;     /* tmp is a first element in the linked list */

    /* Adding element in the end of the linked list */    
    
    tmp2 = malloc(sizeof(struct item));
    
    if(tmp2 == NULL){
        fprintf(stderr, "Error: memory allocation failed.\n");
        return 2;
    }

    tmp2->data = value2;
    tmp2->previous = last;
    tmp2->next = NULL;
    if(last){
        last->next = tmp2;
    }
    else{
        first = tmp2;
    }

    last = tmp2;

    


    return 0;
}



