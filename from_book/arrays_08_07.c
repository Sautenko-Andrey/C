#include<stdio.h>
#include<stdlib.h>

#define MONTHS  12
#define ROW 5
#define COL 5



float* utility_bills(void);
void print_array_float(float array[], size_t len_array);
void showX(int row, int column);
void random_array(void);
int* add_arrays(int array_1[], int array_2[], size_t length);
void show_variable_adress(int var);



int main(void)
{   
    //решим записать все расходы за год
    /*float *all_bills = utility_bills();
    print_array_float(all_bills, MONTHS);

    free(all_bills);*/

    showX(5,5);
    random_array();

    putchar('\n');

    int goals[10] = {1,2,3,4,5,6,7,8,9,10};
    int all_one[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    char counter = 10;

    int *sum_array = add_arrays(goals, all_one, counter);

    for (int i = 0; i < counter; ++i){
        printf("%d ", *(sum_array + i));
    }
    putchar('\n');
    free(sum_array);

    int val = 1;
    show_variable_adress(val);



    return 0;
}

float* utility_bills(void)
{   

    float *ptr = malloc(sizeof(float) * MONTHS);

    for(int i = 0; i < MONTHS; ++i){
        printf("Enter 12 bills for each month: ");
        scanf("%f", (ptr + i));
    }

    return ptr;
}

void print_array_float(float array[], size_t len_array)
{
    for (int i = 0; i < len_array; ++i){
        printf("%.2f ", array[i]);
    }
    putchar('\n');
}

void showX(int row, int column)
{   
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            printf("X ");
        }
        putchar('\n');
    }
}

void random_array(void)
{
    unsigned char array[ROW][COL] = {0};
    
    for (int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            array[i][j] = rand();
        }
    }

    for (int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            printf("%d ", array[i][j]);
        }
        putchar('\n');
    }
}

int* add_arrays(int array_1[], int array_2[], size_t length)
{
    int *ptr = malloc(sizeof(int) * length);

    for(int i = 0; i < length; ++i){
        *(ptr + i) = (array_1[i] + array_2[i]); 
    }

    return ptr;
}

void show_variable_adress(int var)
{
    printf("Adress : %p\n", &var);
}