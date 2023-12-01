#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct item {
    int data;
    struct item *next;
};

struct item* create_list(const int *array, int len);

int main(void)
{
    int i;
    int array[MAX] = {1,4,2,3,5};
    struct item *l_list = create_list(array, MAX);

    for(i = 0; i < MAX; i++){
        printf("%d ", l_list->data + i);
    }

    putchar('\n');

    return 0;
}


struct item* create_list(const int *array, int len)
{
    struct item *new;

    if( !len ){
        return NULL;
    }

    new = malloc(sizeof(struct item));
    new->data = *array;
    new->next = create_list(array + 1, len - 1);

    return new;
}
