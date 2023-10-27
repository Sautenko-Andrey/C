/*
    ADVANCED USES OF POINTERS
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 15
#define NEXT putchar('\n')

struct point {
    int x;
    int y;
};

char *concat (const char *str1, const char *str2);
void check_mem_alocation(void *pointer);
void print_int_arr(int array[], size_t len);


int main(void)
{   
    //Using malloc to allocate memory for a string

    char *ptr = malloc(LEN + 1);
    strcpy(ptr, "Some text");

    char *new_str = concat("Jared", " Dunn");
    puts(new_str);
    free(new_str);

    //Dynamically allocated arrays

    int *ptr_int_arr;
    int x = 100, y = 20;
    int numbers = x / y;

    ptr_int_arr = malloc(sizeof(int) * numbers);
    check_mem_alocation(ptr_int_arr);

    for(int i = 0; i < numbers; ++i){    //as a regular array
        ptr_int_arr[i] = i;
    }

    for(int i = 0; i < numbers; ++i){    //as regular array
        printf("%d ", ptr_int_arr[i]);
    }
    NEXT;
    free(ptr_int_arr);

    // or using adress arithmetic
    int *new_arr = malloc(sizeof(int) * numbers);
    check_mem_alocation(new_arr);

    for(int i = 0; i < numbers; ++i){
        *(new_arr + i) = i;
    }

    for(int i = 0; i < numbers; ++i){    
        printf("%d ", *(new_arr + i));
    }
    NEXT;
    free(new_arr);


    //The Calloc function
    int *zero_arr;
    zero_arr = calloc(LEN, sizeof(int));

    print_int_arr(zero_arr, LEN);
    free(zero_arr);

    struct point *dot;
    dot = calloc(1, sizeof(struct point));

    printf("x = %d, y = %d\n", dot->x, dot->y);

    dot->x = 13;
    dot->y = 99;

    printf("x = %d, y = %d\n", dot->x, dot->y);
    free(dot);


    //The realloc function

    int *marks = malloc(sizeof(int) * 3);

    *marks = 10;
    *(marks + 1) = 7;
    *(marks + 2) = 11;

    print_int_arr(marks, 3);

    marks = realloc(marks, sizeof(marks) + sizeof(int) * 2);
    *(marks + 3) = 5;
    *(marks + 4) = 3;

    print_int_arr(marks, 5);
    

    free(marks);


    //Linked lists

    //let's declare a node type
    struct node {
        int value;            //data stored in the nod
        struct node *next;    //pointer to the next node
    };

    //let's create the first node
    //and we are saying that list is empty
    struct node *first = NULL;

    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    //storing a data in the new_node
    (*new_node).value = 100;

    return 0;
}

char *concat (const char *str1, const char *str2)
{
    char *result;

    result = malloc( strlen(str1) + strlen(str2) + 1 ); //memory allocation

    if(result == NULL){                                           //checking memory allocation
        fprintf(stderr, "Error: malloc failed in concat().\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

void check_mem_alocation(void *pointer)
{
    if(!pointer){
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void print_int_arr(int array[], size_t len)
{
    for(int i = 0; i < len; ++i){
        printf("%d ", array[i]);
    }
    NEXT;
}