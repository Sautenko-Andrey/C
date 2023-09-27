#include<stdio.h>
#include"common.h"

#define ROWS 5
#define COLS 3
#define NEXT putchar('\n')

int main(void){

    //declaring array of integers
    int matrix[ROWS][COLS];
    int *ptr;

    //assigning array
    for(ptr = &matrix[0][0]; ptr <= &matrix[ROWS - 1][COLS - 1]; ptr++){
        *ptr = 0;
    }

    printf_matrix(matrix, ROWS, COLS, 'i');
    NEXT;

    int change_row = 2;

    //changing third row
    for(ptr = matrix[change_row]; ptr < matrix[change_row] + COLS; ptr++){
        *ptr = 1;
    }

    printf_matrix(matrix, ROWS, COLS, 'i');
    NEXT;

    //changing second column

    int (*ptr_arr)[COLS];
    int change_col = 1;

    for(ptr_arr = matrix; ptr_arr < matrix + ROWS; ptr_arr++){
        (*ptr_arr)[change_col] = 1;
    }

    printf_matrix(matrix, ROWS, COLS, 'i');
    NEXT;


    NEXT;

    //one more practice with pointers and multidimensional arrays
    int numbers[ROWS][COLS] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
        {13,14,15}
    };
    
    for(ptr = &numbers[0][0]; ptr <= &numbers[ROWS - 1][COLS - 1]; ptr++){
        printf("%d ", *ptr);
    }
    NEXT;

    //we want pointer points to a row
    int (*p_row)[COLS];

    p_row = &numbers[4];

    for(int i = 0; i < COLS; ++i){
        printf("%d ", (*p_row)[i]);
    }
    NEXT;

    int *pp = numbers[1];
    printf("*pp = %d\n", *pp);

    for(int i = 0; i < COLS; ++i){
        printf("%d ", *(pp++));
    }
    NEXT;

    return 0;
}