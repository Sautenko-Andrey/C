#include<stdio.h>

void count_down(int number);
void count_up(int number);
void numbers_int(int number);
void numbers_intV2(int number);

int main(void)
{   
    count_down(10);
    puts("--------------------------");
    count_up(17);
    puts("--------------------------");
    numbers_int(0);
    puts("--------------------------");
    numbers_intV2(111111);


    return 0;
}

void count_down(int number)
{
    do
    {
        printf("%d\n", number--);
    } while (number > 0);
    
}

void count_up(int number)
{
    int start = 1;
    do
    {
        printf("%d\n", start++);
    } while (start <= number);
    
}

void numbers_int(int number)
{
    int count = 0, devider = 10;


    do
    {
        number /= devider;
        ++count;
    } while (number > 0);

    printf("Integer consist of %d numbers\n", count);
    
}

void numbers_intV2(int number)
{
    int count = 0, devider = 10;

    while(number > 0){
        number /= devider;
        ++count;
    }
    printf("Integer consist of %d numbers\n", count);
}
