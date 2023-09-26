#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void* append(int *data, size_t *capacity, size_t *length, int value)
{
    if(*length >= *capacity){
        //int *new_data = malloc(*capacity * sizeof(int) * 2);
        int *new_data = realloc(data, *capacity * sizeof(int) *2);

        if(new_data == NULL){
            puts("Memory error!");
        }

        (*capacity) *= 2;
        data = new_data;

        /*for(int i = 0; i < *length; ++i){
            new_data[i] = data[i];
        }*/

        //memcpy(new_data, data,*length * sizeof(int));

        //free(data);

        //data = new_data;
    }

    data[*length] = value;
    (*length)++;

    return data;
}

int main(void)
{
    size_t capacity = 10;
    size_t lenght = 0;

    int *data = malloc(capacity * sizeof(int));


    for (int i = 0, max_app = 14; i < max_app; ++i){
        data = append(data, &capacity, &lenght, 3);
    }

    printf("capacity = %lu, length = %lu\n", capacity, lenght);
    for(int i = 0; i < lenght; ++i){
        printf("%d ", data[i]);
    }
    puts("");

    free(data);

    return 0;
}