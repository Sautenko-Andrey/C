#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct item {
    int data;
    struct item *next;
};


/* Function adds a new element in the top of the linked list */
struct item* create_linked_list(const int *array, int len);

int main(void)
{
    int array[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    struct item *l_list = create_linked_list(array, MAX);
    

    for(i = 0; i < MAX; i++){
        printf("%d ", l_list->data + i);
    }
    putchar('\n');

    free(l_list);

    return 0;
}


struct item* create_linked_list(const int *array, int len)
{
    struct item *first = NULL, *new;
    int i;

    for( i = len - 1; i >= 0; i-- ){
        new = malloc(sizeof(struct item));
        if( new == NULL ){
            fprintf(stderr, "Error: memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        new->data = array[i];
        new->next = first;
        first = new;
    }
    return first;
}
