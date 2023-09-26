#include<stdio.h>
#include"common.h"

#define LEN 10

int main(void)
{   
    int array[LEN] = {1,2,3,4,5,6,7,8,9,10};

    int *ptr = array;
    int *ptr_tail = &array[LEN - 1];

    printf("*ptr = %d\n", *ptr);
    printf("*ptr_tail = %d\n", *ptr_tail);

    //adding an integer to the pointer
    printf("second = %d\n", *ptr + 1);
    printf("third = %d\n", *ptr + 2);
    printf("fourth = %d\n", *ptr + 3);

    //substracting an integer from a pointer

    printf("*ptr_tail - 1 = %d\n", *ptr_tail - 1);


    //substracting one pointer from another
    int *seven = &array[6];
    int *two = &array[1];

    printf("seven - two = %ld\n", seven - two);   //5
    printf("two - seven = %ld\n", two - seven);   //-5


    //comparing pointers
    printf("seven >= two = %d\n",seven >= two);   //1 (True)
    printf("seven < two = %d\n",seven < two);   //0 (False)

    //compound literals
    int *ptr_x = (int []){33,15,2,9,0,22};

    for (int i = 0; i < 6; ++i){
        printf("%d ", *ptr_x++);
    }
    putchar('\n');


    //processing array with loop
    int nums[LEN] = {10,44,100,-37,1,0,34,96};
    int *ptr_nums;
    int total;

    for(ptr_nums = &nums[0]; ptr_nums < &nums[LEN]; ++ptr_nums){
        total += *ptr_nums;
    }

    printf("total = %d\n", total);

    //another way to get total
    int sum, *p;
    p = nums;
    for(int i = 0; i < LEN; ++i){
        sum += *p++;
    }
    printf("sum = %d\n", sum);


    //combining * and ++ --
    int numbers[LEN] = {100,200,300,400,500};
    int *pointer = numbers;
    int sum2;

    //printf("*pointer++ = %d\n", *pointer++);   //100
    while(*pointer < &numbers[LEN]){
        sum2 += *pointer++;
    }
    printf("sum2 = %d\n", sum2);


    //some experiments

    int arr[5] = {1,2,3,4,5};
    int *p_arr = arr;
    int *rev_p = &arr[4];

   //printf("*++p_arr = %d\n", *++p_arr);

    for(int i = 0; i < (sizeof(arr) / sizeof(*arr)) - 1; ++i){
        printf("%d ", *++p_arr);
    }
    putchar('\n');

    for(int i = 0; i < (sizeof(arr) / sizeof(*arr)) - 1; ++i){
        printf("%d ", *--rev_p);
    }
    putchar('\n');


    //using an array name as a pointer

    int values[5];

    *values = 101;
    *(values + 1) = 222;
    *(values + 2) = 345;
    for (int i = 0; i < 5; ++i){
        printf("%d ", values[i]);
    }
    putchar('\n');

    //all elements = 99;
    for (int i = 0; i < 5; ++i){
        *(values + i) = 99;
    }

    for (int i = 0; i < 5; ++i){
        printf("%d ", values[i]);
    }
    putchar('\n');

    //reverse numbers using pointers

    int rand_nums[LEN];
    int *pt;

    // for(pt = rand_nums; pt < rand_nums + LEN; pt++){
    //     printf("Enter a number: ");
    //     scanf("%d", pt);
    // }

    // for(ptr = rand_nums + LEN - 1; pt >= rand_nums; pt--){
    //     printf("%d ", *pt);
    // }
    // putchar('\n');

    //my version
    for(pt = rand_nums; pt < rand_nums + LEN; pt++){
        printf("Enter a number: ");
        scanf("%d", pt);
    }

    for(pt = rand_nums + LEN - 1; pt >= rand_nums; pt--){
        printf("%d ", *pt);
    }
    putchar('\n');





    return 0;
}