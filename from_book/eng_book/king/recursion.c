#include<stdio.h>


void display_num(int num);
int factorial(int num);

int main(void)
{   
    display_num(10);
    int res_factor = factorial(6);
    printf("Factorial = %d\n", res_factor);

    return 0;
}

void display_num(int num)
{
    if (num <= 1){
        printf("%d\n", num);
    }
    else{
        while(num > 0){
            printf("%d ", num);
            --num;
        }
    }
    putchar('\n');
}

int factorial(int num)
{   
    if (num == 1){
        return 1;
    }
    else{
        return num * (factorial(num - 1));
    }
}