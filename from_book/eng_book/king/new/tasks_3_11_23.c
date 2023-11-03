#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEXT putchar('\n')

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point upper_left;
    struct point lower_right;
};



void* my_malloc(size_t size);
char* dublicate(char *str);
int* create_array(int len, int initial_value);
void print_int_arr(int *array, int len);

int main(void)
{   
    //testing my_malloc
    int *x_val = my_malloc(sizeof(int));
    *x_val = 100;
    printf("x_val = %d\n", *x_val);
    free(x_val);

    //testing dublicate
    char *my_text = "I prefer books to TV.";
    char *new_text = dublicate(my_text);
    puts(new_text);

    //testing create_array
    int *my_arr = create_array(10, 7);

    print_int_arr(my_arr, 10);

    //next one
    struct rectangle *p;
    p = my_malloc(sizeof(struct rectangle));
    p->lower_right.x = 20;
    p->lower_right.y = 15;
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    

    return 0;
}

void* my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if(ptr == NULL){
        fprintf(stderr, "Error: memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

char* dublicate(char *str)
{
    int len = strlen(str) + 1;

    char *new_str = my_malloc(sizeof(char) * len);

    strcpy(new_str, str);

    return new_str;
}

int* create_array(int len, int initial_value)
{
    int *array = malloc(sizeof(int) * len);
    if(array == NULL){
        return NULL;
    }

    for(int i = 0; i < len; ++i){
        *(array + i) = initial_value;
    }

    return array;
}

void print_int_arr(int *array, int len)
{
    for(int i = 0; i < len; ++i){
        printf("%d ", array[i]);
    }
    NEXT;
}