//Conditional compilation

#include<stdlib.h>
#include<stdio.h>

#define DEBUG 0

//simple functions just for the instance
void switch_values(int *x, int *y);


int main(void)
{   

    int res1 = 100, res2 = 999;
    switch_values(&res1, &res2);

    #if DEBUG    //here we starting debuging and printf works

    printf("After switching res1 = %d, res2 = %d\n", res1, res2);

    #endif     //end of debuging


    return 0;
}

void switch_values(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}