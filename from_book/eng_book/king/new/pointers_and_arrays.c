#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(void)
{   
    //let's declare an assign an array
    int array[SIZE] = {1,2,3,4,5,6,7,8,9,10};

    int *ptr_first = array;
    int *ptr_last = &array[9];

    printf("First = %d\nLast = %d\n", *ptr_first, *ptr_last);

    //let's move forward by ptr_first
    for(int i = 0; i < SIZE; ++i){
        printf("%d ", *(ptr_first++));
    }
    putchar('\n');

    //let's move backwards by ptr_last
    for(int i = 0; i < SIZE; ++i){
        printf("%d ", *(ptr_last--));
    }
    putchar('\n');


    return 0;
}