#include<stdio.h>

void count_down(int num);
void count_up_old_V(int num);
void table_squares(int num);

int main(void)
{   
    count_down(10);
    puts("");
    count_up_old_V(5);
    puts("--------------");
    table_squares(55);
    
    return 0;
}

void count_down(int num)
{   
    int i = 0;

    for (int sum = 0, i = num; i > 0; i--){
        printf("%d\n", i);
        sum += i;
    }

    printf("%d\n", i);
}

void count_up_old_V(int num)
{
    int i = 0;
    for (; i < num; ++i){
        printf("%d\n", i);
    }
    printf("Final : %d\n", i);
}

void table_squares(int num)
{
    if(num < 0){
        puts("Argument must be greather 0");
        return;
    }

    for (int i = 1; i <= num; ++i){
        printf("%d -> %d\n", i, i*i);
    }
}