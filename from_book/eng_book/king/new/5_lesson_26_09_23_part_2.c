#include<stdio.h>
#include"common.h"

#define ROW 10
#define COL 5 
#define ROWS 3
#define COLS 7
#define NEXT putchar('\n')

int main(void){

    //let's declare multidimensional array of integers and fill it with 1
    int array[ROW][COL];
    int *ptr;

    for(ptr = &array[0][0]; ptr <= &array[ROW - 1][COL - 1]; ptr++){
        *ptr = 1;
    }

    printf_matrix(array, ROW, COL, 'i');
    NEXT;

    //lets fill first and last rows with 0
    int first_row = 0, last_row = ROW - 1;

    for(ptr = array[first_row]; ptr < array[first_row] + COL; ptr++){
        *ptr = 0;
    }
    for(ptr = array[last_row]; ptr < array[last_row] + COL; ptr++){
        *ptr = 0;
    }

    printf_matrix(array, ROW, COL, 'i');
    NEXT;

    //lets' fill first column and last column with 0
    int (*pp)[COL];

    for(pp = &array[0]; pp < &array[ROW - 1]; pp++){
        (*pp)[0] = 0;
        (*pp)[4] = 0;
    }

    printf_matrix(array, ROW, COL, 'i');

    NEXT;
    NEXT;

    int matrix[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int *pointer;
    pointer = &matrix[0][0];
    printf("pointer = %d\n", *pointer);


    pointer = matrix[1];
    printf("pointer = %d\n", *(++pointer));
    

    int (*q)[4];
    q = &matrix[0];
    printf("q = %d\n", (*q)[2]);


    //one more
    int nums[ROWS][COLS];
    int *ptr_nums;
    //assigning multidimensiona larray
    for(ptr_nums = nums[0]; ptr_nums <= &nums[ROWS - 1][COLS - 1]; ptr_nums++){
        *ptr_nums = 9;
    }

    printf_matrix(nums, ROWS, COLS, 'i');
    NEXT;

    //let's change second row
    int sec_row = 1;
    for(ptr_nums = nums[sec_row]; ptr_nums < nums[sec_row] + COLS; ptr_nums++){
        *ptr_nums = 0;
    }

    printf_matrix(nums, ROWS, COLS, 'i');
    NEXT;

    //lets change last column
    int (*ptr_col)[COLS];
    for(ptr_col = nums; ptr_col < nums + COLS; ++ptr_col){
        (*ptr_col)[6] = 2;
    }

    printf_matrix(nums, ROWS, COLS, 'i');

    NEXT;

    //looking insight
    int digs[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int *pr;
    pr = digs[0];
    printf("adress pr = %p\n", pr);
    pr = &digs[0][0];
    printf("adress pr = %p\n", pr);
    pr = digs;
    printf("adress pr = %p\n", pr);

    //let's get 2
    pr = digs[0];
    printf("adress pr = %p, value = %d\n", ++pr, *(++pr));









    return 0;
}