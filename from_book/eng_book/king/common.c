#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

#define NEXT putchar('\n');

//showing execution time
void execution_time(clock_t begin, clock_t end)
{
    printf("Time: %f s\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void type_check(char type)
{
    if (type != 'i' && type != 'c' && type != 's' && type != 'f' && type !='d' && type != 'l'\
&& type != 'b' && type != 'u'){
        fprintf(stderr, "Type error.\n");
        exit(1);
    }
}

//printf array
void printf_arr(void *arr, size_t length, char type)
{
    if (length <= 0){
        fprintf(stderr, "Length must be greater then 0. Error in line %d.\n", __LINE__ -3);
        exit(1);
    }

    /*if (type != 'i' && type != 'c' && type != 's' && type != 'f' && type !='d' && type != 'l'){
        fprintf(stderr, "Type error in line %d.\n", __LINE__ - 8);
        exit(1);
    }*/
    type_check(type);

    if (type == 'i'){
        for (int i = 0; i < length; ++i){
            printf("%d ", *((int*)arr + i));
        }
        NEXT;
    }

    else if (type == 'c'){
        for (int i = 0; i < length; ++i){
            printf("%c ", *((char*)arr + i));
        }
        NEXT;
    }

    else if (type == 's'){
        for (int i = 0; i < length; ++i){
            printf("%c ", *((short*)arr + i));
        }
        NEXT;
    }

    else if (type == 'f'){
        for (int i = 0; i < length; ++i){
            printf("%f ", *((float*)arr + i));
        }
        NEXT;
    }

    else if (type == 'd'){
        for (int i = 0; i < length; ++i){
            printf("%f ", *((double*)arr + i));
        }
        NEXT;
    }

    else if (type == 'l'){
        for (int i = 0; i < length; ++i){
            printf("%ld ", *((long*)arr + i));
        }
        NEXT;
    }

    else if (type == 'b'){
        for (int i = 0; i < length; ++i){
            printf("%d ", *((bool*)arr + i));
        }
        NEXT;
    }

    else if (type == 'u'){
        for (int i = 0; i < length; ++i){
            printf("%d ", *((unsigned*)arr + i));
        }
        NEXT;
    }
    
}

//manual sorting
void sort_int(int array[], size_t length)
{   
    if(length < 1){
        fprintf(stderr, "Length of array must be greather then 1.\n");
        exit(1);
    }

    int min_index;

    for(int i = 0; i < length - 1; ++i){
        min_index = i;

        for (int j = i + 1; j < length; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }

        if (min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

//comparing digits function
int comparing_val(const void *val_1, const void *val_2)
{
    return ( *(int*)val_1 - *(int*)val_2 );
}

//sorting using library func qsort
void sort_library(int array[], size_t length)
{
    qsort(array, length, sizeof(int), comparing_val);
}

//printing matrix
void printf_matrix(void *ptr_matrix, size_t rows, size_t columns, char type)
{
    type_check(type);

    if (ptr_matrix == NULL){
        fprintf(stderr, "Array doesn't exist.\n");
        exit(1);
    }

    if (type == 'i'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%d ", *((int*)ptr_matrix + i));
            ++counter;
        }
    }
    else if (type = 'f'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%f ", *((float*)ptr_matrix + i));
            ++counter;
        }
    }
    else if (type = 's'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%d ", *((short*)ptr_matrix + i));
            ++counter;
        }
    }
    else if (type = 'd'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%f ", *((double*)ptr_matrix + i));
            ++counter;
        }
    }
    else if (type = 'l'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%ld ", *((long*)ptr_matrix + i));
            ++counter;
        }
    }

    else if (type = 'b'){
        int counter = 0;
        for(int i = 0; i < (rows * columns); ++i){
            if (counter == columns){
                NEXT;
                counter = 0;
            }
            printf("%d ", *((bool*)ptr_matrix + i));
            ++counter;
        }
    }
    NEXT;
}

//memery allocation check
void memCheck(void *ptr)
{
    if(!ptr){
        fprintf(stderr, "Memory allocation error (realloc).");
        exit(0);
    }
}