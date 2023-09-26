#include<stdio.h>


typedef struct {
    char name[25];
    short id;
} EMP;

void get_and_show_date(void);

void* max_value(int array[], size_t length);


int main(void)
{   
    get_and_show_date();

    EMP sautenko = {"Andrey Sautenko", 2806};

    printf("Employee: %s\nID: %d\n", sautenko.name, sautenko.id);

    //find max value in array
    int digs[10] = {1,13,2,4,87,9,1,0,-13};
    int *ptr_max = max_value(digs, sizeof(digs) / sizeof(*digs));

    printf("max value must be 87 , we got %d\n", *ptr_max);

    return 0;
}


void get_and_show_date(void)
{   
    int mm, dd, yyyy;

    printf("Enter a date (mm/dd/yyyy) : ");
    scanf("%i/%d/%d", &mm, &dd, &yyyy);

    printf("You entered the date %d%i%d\n",yyyy, mm, dd);
}

void* max_value(int array[], size_t length)
{
    size_t min_index;

    for (int i = 0; i < length - 1; ++i){
        min_index = i;

        for (int j = i + 1; j < length; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }

        if (min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }

    return array + (length - 1);
}