#include<stdio.h>
#include<stdlib.h>

#ifndef TEST
#define TEST
#endif

enum {max_len = 10};

int *copy_int_array(const int *array, unsigned len);
void display_int_array(const int *array, unsigned nums);

int main(void)
{
    int original_array[max_len] = {1,10,2,9,3,8,4,7,5,6};
    int *array_copied = copy_int_array(original_array, max_len);

    display_int_array(array_copied, max_len);


    return 0;
}


int *copy_int_array(const int *array, unsigned len)
{
    int i;
    int *new_array;

    new_array = malloc(sizeof(int) * len);
    if(new_array == NULL){
        fprintf(stderr, "ERROR:in file %s memory allocaton failed in line: %d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    
    for(i = 0; i < len; i++){
        new_array[i] = array[i];
        #if defined TEST
        printf("%d\n", new_array[i]);
        #endif
        
        #if defined CONTROL
        puts("Ok");
        #endif
    }

    return new_array;
    
}


void display_int_array(const int *array, unsigned nums)
{
    int i;
    for(i = 0; i < nums; i++, array++){
        printf("%d ", *array);
    }

    putchar('\n');
}
