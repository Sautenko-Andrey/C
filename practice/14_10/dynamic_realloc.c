#include<stdio.h>
#include<stdlib.h>

void* append(short *array, size_t *length, size_t *elements, short value)
{
    if(*elements >= *length){
        short *new_array = realloc(array, sizeof(short) * *length *2 );
        if(new_array == NULL){
            puts("Couldn't allot memeory from pit");
        }
        *length *= 2;
        array = new_array;
    }
    array[*elements] = value;
    (*elements)++;

    return array;
}

int main(void)
{
    size_t start_size = 10;
    size_t col_elements = 0;

    short *digs = malloc(start_size * sizeof(short));

    short num = 9;

    for(int i = 0; i < 44; ++i){
        digs = append(digs, &start_size, &col_elements, num);
    }

    printf("start_size = %lu, col_elements = %lu\n", start_size, col_elements);

    for (int i = 0; i < col_elements; ++i){
        printf("%d ", digs[i]);
    }
    puts("");

    free(digs);

    return 0;
}