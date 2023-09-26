#include<stdio.h>

#define SIZE 5
#define INDEX_1 1
#define INDEX_2 2
#define INDEX_3 3
#define INDEX_4 4

int main(void)
{   
    int matrix[SIZE][SIZE];
    int total_rows[SIZE], total_columns[SIZE];

    for(int i = 0; i < SIZE; ++i){
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &matrix[i][0],\
&matrix[i][INDEX_1], &matrix[i][INDEX_2], &matrix[i][INDEX_3], &matrix[i][INDEX_4]);
    }

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            total_rows[i] += matrix[i][j];
            total_columns[i] +=matrix[j][i];
        }
    }

    printf("Row totals: ");
    printf_arr(total_rows, SIZE, 'i');
    printf("Column totals: ");
    printf_arr(total_columns, SIZE, 'i');

    return 0;
}