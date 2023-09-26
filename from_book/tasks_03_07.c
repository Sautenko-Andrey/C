#include<stdio.h>
#include<stdlib.h>


void biggest_value(void);

int main(void)
{   
    biggest_value();

    return 0;
}

void biggest_value(void)
{
    double *ptr_user_input = malloc(sizeof(double));
    double array[100] = {};
    int counter = 0, min_index;

    for(int i = 0; ;++i){
        printf("Enter a number: ");
        scanf("%lf", ptr_user_input);
        array[i] = *ptr_user_input;
        if(*ptr_user_input == 0){
            break;
        }
        ++counter;
    }

    for (int i = 0; i < counter; ++i){
        printf("%.2lf ", array[i]);
    }
    puts("");

    for (int i = 0; i < counter; ++i){
        min_index = i;

        for (int j = i + 1; j < counter - 1; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }

        if(min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = array[i];
        }
    }
    puts("Sorted array!");
    for (int i = 0; i < counter; ++i){
        printf("%.2lf ", array[i]);
    }
    puts("");

    printf("Biggest number is %.3lf\n", array[counter - 1]);
    
}