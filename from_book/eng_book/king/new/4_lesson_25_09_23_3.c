//pointers and multidimensional arrays

#include<stdio.h>
#include"common.h"

#define ROWS 5
#define COLS 3

int main(void)
{   
    int nums[ROWS][COLS] = {
        {10,20,30},
        {40,50,60},
        {70,80,90},
        {100,110,120},
        {130,140,150}
    };

    //change all elements into 0
    // for(int i = 0; i < ROWS; ++i){
    //     for(int j = 0; j < COLS; ++j){
    //         nums[i][j] = 0;
    //     }
    // }

    // printf_matrix(nums, ROWS, COLS, 'i');

    //using 1 loop
    int *ptr;
    for(ptr = &nums[0][0]; ptr <= &nums[ROWS - 1][COLS - 1]; ptr++){
        *ptr = 0;
    }

    printf_matrix(nums, ROWS, COLS, 'i');
    

    return 0;
}