#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct item {
    int data;
    struct item *next;
};

struct item* int_array_to_list(const int *array, int len);
struct item* int_array_to_list_Simple(const int *array, int len);

int main(void)
{
    int array[MAX] = {90, 35, -100, 24, 879, 11, 43, 0, -1, 12};
    /* Testing int_array_to_list function */
    struct item *start_1 = int_array_to_list(array, MAX);

    /* Testing int_array_to_list_Simple function */
    struct item *start_2 = int_array_to_list_Simple(array, MAX);    

    return 0;
}

/* Add new elements in the end of list */

struct item* int_array_to_list(const int *array, int len)
{
    /* first element, last element and temporary pointer of linked list */
    struct item *first = NULL, *last = NULL, *tmp;    
    int i;

    for(i = 0; i < len; i++){
        tmp = malloc(sizeof(struct item));
        if(tmp == NULL){
            fprintf(stderr,"Error: memory allocation failed for pointer tmp\n");
            exit(EXIT_FAILURE);
        }
        tmp->data = array[i];
        tmp->next = NULL;
    if(last){
        last->next = tmp;
        last = last->next;
    }
    else{
        first = last = tmp;
    }

    return first;        
}
    
/* Add new elements int the top of list */
struct item* int_array_to_list_Simple(const int *array, int len)
{
    struct item *first = NULL, *new;
    int i;

    for(i = len -1; i >= 0; i--){
        new = malloc(sizeof(struct item));
        if(new == NULL){
            fprintf(stderr, "Error: memory allocation failed for new\n");
            exit(EXIT_FAILURE);
        }
        new->data = array[i];
        new->next = first;
        first = new;
    }
    return first;
}
