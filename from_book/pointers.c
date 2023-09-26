#include<stdio.h>


int main(void)
{   
    int value = 100;
    int *p_value = &value;

    printf("Direct access : %d\n", value);
    printf("Indirect access : %d\n", *p_value);
    
    printf("Adress : %p\n", &value);
    printf("Adress via pointer : %p\n", p_value);

    putchar('\n');

    int data[10] = {10,23,3,4,5,6,7,8,9,10};
    printf("First value in array = %d\n", *data);
    printf("Second value in array = %d\n", *(data + 1));
    printf("Second value in array by another way = %d\n", data[1]);

    int *ptr_data = data;
    printf("First element = %d\n", *ptr_data);
    printf("Second element = %d\n", *(ptr_data + 1));
    printf("Unknown value out of array = %d\n", *(ptr_data - 1));

    int digs[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("Adress 1 = %p, adress 2 = %p, adress 3 = %p\n", &digs[0], &digs[1], &digs[2]);
    printf("Step pre element = %ld bytes\n", &digs[1] - &digs[0]);


    int my_arr[5] = {23,14,1,25,0};
    int *ptr_my_arr = my_arr;
    
    for (int i = 0; i < 5; ++i){
        printf("%d -- %d", *(ptr_my_arr + i), my_arr[i]);
    }
    putchar('\n');

    int some_arr[5] = {1,2,3,4,5};
    int *ptr_some_arr = some_arr;

    for(int i = 0; i < 5; ++i){
        printf("%d ", *ptr_some_arr++);
    }
    putchar('\n');

    float prices[5] = {100, 32.25, 15, 0.369, 1.1};
    float *ptr_prices = prices;

    for(int i = 0; i < 5; ++i){
        printf("%d ", *ptr_prices--);
    }


    return 0;
}