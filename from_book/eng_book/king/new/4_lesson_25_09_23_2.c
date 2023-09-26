#include<stdio.h>
#include<stdlib.h>
#include"common.h"

#define MAX 5


int minimum(int array[], size_t len);
int maximum(const int array[], size_t len);
void* universal_min(void *array, size_t len, char type);

int main(void)
{
    //searchung minimum
    // int numbers[MAX];
    // for(int i = 0; i < MAX; ++i){
    //     printf("Enter an element: ");
    //     scanf("%d", &numbers[i]);
    // }

    // int min_value = minimum(numbers, MAX);
    // int max_value = maximum(numbers, MAX);
    // printf("Minimum value is %d\nMaximum value is %d\n", min_value, max_value);

    //one more try
    int x[5] = {9,3,2, -34, 100};
    int *min = universal_min(x,5,'d');
    printf("minimum = %d\n", *min);

    //using custom func from "common.h"
    int *min_x = min_arr(x,5,'d');
    printf("*min_x = %d\n", *min_x);

    free(min_x);

    int xx_m = maximum(x,5);
    printf("xx_m = %d\n", xx_m);

    putchar('\n');
    putchar('\n');

    int points[5] = {10,90, 45,33,100};
    int *p_points = points;
    int sum = 0;

    for(int i = 0; i < 5; ++i){
        sum += p_points[i];
    }

    printf("sum = %d\n", sum);

    for(int i = 0; i < 5; ++i){
        printf("%d ", p_points[i]);
    }
    putchar('\n');


    return 0;
}

int minimum(int array[], size_t len)
{
    int min = array[0];

    for (int i = 1; i < len; ++i){
        if (min > array[i]){
            min = array[i];
        }
    }

    return min;
}

int maximum(const int array[], size_t len)
{
    int max_val = array[0];

    for (int i = 0; i < len; ++i){
        if(max_val < array[i]){
            max_val = array[i];
        }
    }

    return max_val;
}

void* universal_min(void *array, size_t len, char type)
{
    type_check(type);

    if (type == 'd'){
        int *min_val = malloc(sizeof(int));
        memCheck(min_val);

        *min_val = *(int*)array;
        printf("*min_val = %d\n", *min_val);

        for(int i = 1; i < len; ++i){
            if(*min_val > *((int*)array + i)){
                *min_val = *((int*)array + i);
            }
        }

        return min_val;
    }
    else{
        puts("In progress...");
    }

}