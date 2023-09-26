#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{   
    size_t size = 10;

    int *digs = malloc(size * sizeof(int));
    for(int i = 0; i < size; ++i){
        digs[i] = 1;
    }

    printf("Was: ");
    for(int i = 0; i < size; ++i){
        printf("%d ", digs[i]);
    }
    puts("");


    int *new_copy = realloc(digs, sizeof(int) * sizeof(digs)/sizeof(*digs) + 1);

    digs = new_copy;

    for(int i = 0; i < size + 1; ++i){
        digs[i] = 1;
    }

    printf("NOW: ");
    for(int i = 0; i < size + 1; ++i){
        printf("%d ", digs[i]);
    }
    puts("");

    



    return 0;
}