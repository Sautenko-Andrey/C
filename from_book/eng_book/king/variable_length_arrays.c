#include<stdio.h>
#include"common.h"
#include<string.h>
#include<stdbool.h>


int main(void)
{   
    int num;

    printf("How many nmbers you want in array: ");
    scanf("%d", &num);

    int array[num];

    for (int i = 0; i < num; ++i){
        printf("Enter #%d number: ", i);
        scanf("%d", &array[i]);
    }

    printf_arr(array,num,'i');

    //reverse printf
    for(int i = num - 1; i >= 0; --i){
        printf("%d ", array[i]);
    }
    putchar('\n');


    //or this example
    int x = 2, y = 1;
    int my_array[num + x - y];

    //multidimensional arrays

    int rows = 10;
    int cols = 10;
    int matrix_1[rows][cols];

    int rows2, cols2;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows2, &cols2);

    int new_arr[rows2][cols2];


    int strange_arr[] = {1,2,3,4,[0] = 5, 6, 7, 8};

    printf_arr(strange_arr, sizeof(strange_arr) / sizeof(*strange_arr),'i');   //5,6,7,8



    //HOW TO FAST COPY ONE ARRAY INTO ANOTHER
    int arr_a[5] = {1,2,3,4,5};
    int arr_b[5];

    memcpy(arr_b, arr_a, sizeof(arr_a));
    
    printf("%d\n", arr_b[0]);
    printf("%d\n", arr_b[1]);
    printf("%d\n", arr_b[2]);
    printf("%d\n", arr_b[3]);
    printf("%d\n", arr_b[4]);
    
    //printf_arr(arr_b, sizeof(arr_b) / sizeof(*arr_b), 'i');

    //one more experiment

    bool weekend[7] = {[0] = true,[6] = true};   //1 0 0 0 0 0 1 
    printf_arr(weekend, 7, 'b');

    bool weekend2[] = {false};
    weekend2[0] = true;
    weekend2[6] = true;

    return 0;
}