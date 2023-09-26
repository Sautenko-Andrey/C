#include<stdio.h>
#include"common.h"

#define NEXT putchar('\n')
#define ROWS 10
#define COLS 5
#define STROKA 3
#define COLONKA 4

int largest(int array[], size_t len);

int main(void)
{   
    int matrix[ROWS][COLS];

    int *ptr;

    for(ptr = &matrix[0][0]; ptr <= &matrix[ROWS - 1][COLS - 1]; ptr++){
        *ptr = 1;
    }

    printf_matrix(matrix,ROWS, COLS,'i');

    //we can display this matrix using this tecnique
    int counter = 0;
    for(ptr = &matrix[0][0]; ptr <= &matrix[ROWS - 1][COLS - 1]; ptr++){
        
        if(counter == COLS){
            putchar('\n');
            counter = 0;
        }
        ++counter;
        printf("%d ", *ptr);
    }
    NEXT;


    //processing the rows of multidimensional array
    int rectangle[3][5] = {
        {10,20,30,40,50},
        {66,70,80,90,100},
        {110,120,130,140,150}
    };

    int *p;

    for(p = rectangle[0]; p < rectangle[0] + 5; p++){
        printf("%d ", *p);
    }
    NEXT;
    NEXT;

    //we can change values only in particular row
    //let's change values in a row 1
    int row = 1;
    for(p = rectangle[row]; p < rectangle[row] + 5; p++){
        *p = 999;
    }

    printf_matrix(rectangle, 3,5,'i');

    //finding largest value in particular row
    int seek_row = 2;

    int maximum = largest(rectangle[seek_row],5);
    printf("max = %d\n", maximum);

    //processing the columns of multidimensional array
    int vortex[ROWS][COLS] = {0};

    int (*pt)[COLS];
    int seek_column = 1;

    for(pt = &vortex[0]; pt < &vortex[ROWS]; pt++){
        (*pt)[seek_column] = 99;
    }

    printf_matrix(vortex, ROWS,COLS, 'i');

    //practice
    int matr[3][5] = {
        {10,20,30,40,50},
        {60,70,80,90,100},
        {110,120,130,140,150}
    };

    int (*pp)[5]; //this is pointer on an array of integers size 5
    pp = &matr[0];
    printf_arr(pp, 5, 'i');

    (*pp)[2] = 777;
    NEXT;
    printf_matrix(matr, 3,5,'i');

    NEXT;
    NEXT;

    int points[STROKA][COLONKA] = {
        {11,22,33,44},
        {55,66,77,88},
        {99,110, 120, 130}
    };

    //let's change values in column 2
    int col_change = 2;
    int (*ppp)[COLONKA];

    for(ppp = &points[0]; ppp < &points[STROKA]; ppp++){
        (*ppp)[col_change] = -1;
    }

    printf_matrix(points, STROKA, COLONKA, 'i');


    //one more practice

    int marks[COLS][ROWS];
    int *p_marks;

    for(p_marks = &marks[0][0]; p_marks <= &marks[COLS - 1][ROWS - 1]; p_marks++ ){
        *p_marks = 0;
    }
    NEXT;
    printf_matrix(marks, ROWS,COLS, 'i');

    //let's change row 3
    int row_3 = 1;

    for(p_marks = marks[row_3]; p_marks < marks[row_3] + COLS; p_marks++){
        *p_marks = 1;
    }
    NEXT;
    NEXT;
    printf_matrix(marks, ROWS, COLS, 'i');

    //another
    int values[4][3] = {
        {11,22,33},
        {44,55,66},
        {77,88,99},
        {111, 222, 333}
    };

    NEXT;
    puts("----------");

    int *p_val;
    for(p_val = &values[0][0]; p_val <= &values[4-1][3-1]; p_val++){
        *p_val = 0;
    }
    printf_matrix(values, 4,3,'i');

    int last_row = 3;
    for(p_val = values[last_row]; p_val < values[last_row] + 3; p_val++){
        *p_val = 1;
    }
    puts("After updating..");
    printf_matrix(values, 4,3,'i');

    int mid_col = 1;
    int(*q)[3];
    for(q = &values[0]; q < &values[4]; q++){
        (*q)[mid_col] = 28;
    }

    puts("After final update...");
    printf_matrix(values, 4,3,'i');


    return 0;
}

int largest(int array[], size_t len)
{
    int max_val = array[0];

    for (int i = 1; i < len; ++i){
        if(max_val < array[i]){
            max_val = array[i];
        }
    }
    
    return max_val; 
}