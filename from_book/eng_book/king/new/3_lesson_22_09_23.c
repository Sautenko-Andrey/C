#include<stdio.h>
#include<stdlib.h>

#define TAX 0.2
#define MAX 10


void switch_numbers(int *x, int *y);
void decompose_double(double x, long *int_part, double *fr_part);

//function, where we can return a few values using pointers
void sallary_calculator(double sallary, double *clear_sal, double *clear_tax);

//function which finds min and max value in the array
void min_max(int array[], size_t len, int *max, int *min);

void * max_or_min(void *ptr_array, size_t len, void *min, void *max, char type, char ops);

int main(void)
{   
    int value_1 = 100, value_2 = 333;

    switch_numbers(&value_1, &value_2);
    printf("val1 = %d, val2 = %d\n", value_1, value_2);


    //pointers ops
    int x = 999;
    int *ptr = &x;
    int *ptr2;

    ptr2 = ptr;

    printf("x = %d\n*ptr = %d\n*ptr2 = %d\n", x, *ptr, *ptr2);

    int y = 333;
    int *ptr_y = &y;
    int *ptr_y2;
    //*ptr_y2 = *ptr_y;  tend to be an error.
    //printf("*ptr_y2 = %d\n", *ptr_y2);

    //decomposing double
    double d_value = 100.009;
    long i_val;
    double f_val;

    decompose_double(d_value, &i_val, &f_val);

    printf("i_val = %ld, f_val = %f\n", i_val, f_val);

    //getting two returned values from function
    double clear_sallary, clear_tax_value, sallary = 1000.0;
    sallary_calculator(sallary, &clear_sallary, &clear_tax_value);

    //displaying these two values
    printf("Clear sallary: %.3f usd, clear tax value = %.3f usd.\n", clear_sallary,clear_tax_value);

    //determing largest and smallest value in an array
    //declaring and assigning array of integers
    int massive[MAX];
    int min, max;

    // for(int i = 0; i < MAX; ++i){
    //     printf("Enter a value: ");
    //     scanf("%d", &massive[i]);
    // }

    //applying functiom min_max()
    //min_max(massive, MAX, &max, &min);

    //printf("Max = %d, min = %d\n", max, min);


    //let's try my custom function for determinate max or min value in an array
    int numbers[MAX] = {1,2,3,4,5};
    int *min_val, *max_val;
    max_val = max_or_min(numbers, 5, &min_val, &max_val, 'd', '+');

    printf("max_val = %d\n", *max_val);





    return 0;
}

void switch_numbers(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void decompose_double(double x, long *int_part, double *fr_part)
{
    *int_part = (long)x;
    *fr_part = x - *int_part;
}

void sallary_calculator(double sallary, double *clear_sal, double *clear_tax)
{
    *clear_tax = sallary * TAX;
    *clear_sal = sallary - *clear_tax;
}

void min_max(int array[], size_t len, int *max, int *min)
{
    *max = *min = array[0];

    printf("*max = *min = array[0] = %d\n", *max);
    
    for(int i = 1; i < len; ++i){

        if (array[i] > *max){

            printf("array[i] = %d, *max = %d\n", array[i], *max);

            *max = array[i];
        }
        else if(array[i] < *min){

            printf("array[i] = %d, *min = %d\n", array[i], *min);

            *min = array[i];
        }
    }
}

void * max_or_min(void *ptr_array, size_t len, void *min, void *max, char type, char ops)
{
    if (type != 'd' && type != 'f'){
        fprintf(stderr,"Unsupported type of array.Use int or float.\n");
        exit(1);
    }

    if (ops != '-' && ops != '+'){
        fprintf(stderr, "Please choose - for min and + for max.\n");
        exit(1);
    }

    if (ops == '+'){

        if (type == 'd'){

            *(int *)min = *(int *)max = *(int *)ptr_array;
            for(int i = 1; i < len; ++i){
                if( *((int*)ptr_array + i) > *(int*)max ){
                    *(int*)max = *((int*)ptr_array + i);
                }
                else if( *((int*)ptr_array + i) < *(int*)min ){
                    *(int*)min = *((int*)ptr_array + i);
                }
            }
        }

        else{
            *(float *)min = *(float *)max = *(float *)ptr_array;
            for(int i = 1; i < len; ++i){
                if( *((float*)ptr_array + i) > *(float*)max ){
                    *(float*)max = *((float*)ptr_array + i);
                }
                else if( *((float*)ptr_array + i) < *(float*)min ){
                    *(float*)min = *((float*)ptr_array + i);
                }
            }
        }
    }

    else{
        puts("In progress...");
    }
}