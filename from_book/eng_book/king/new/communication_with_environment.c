// Comunication with environment

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdarg.h>

#define MIN 0
#define MAX 50

void before_exit(void);
double deposit(int nums, ...);
long long gen_index(int nums, ...);

int main(void)
{      
    // Testing deposit
    double users_money = deposit(5, 110.00, 250.00, 500.00, 50.00, 100.0);
    printf("Total at this moment: %.2f $\n", users_money);

    // Testing gen_index
    int user_index = gen_index(3, 34,10,79);
    printf("User's index = %d\n", user_index);

    return 0;
}

void before_exit(void)
{
    puts("Call before terminating");
}

double deposit(int nums, ...)
{   
    static double total = 0;
    va_list args_list;

    va_start(args_list, nums);

    for(int i = 0; i < nums; ++i){
        double current_value = va_arg(args_list, double);
        total += current_value;
    }

    va_end(args_list);

    // Calling atexit function
    atexit(before_exit);

    return total; 
}

long long gen_index(int nums, ...)
{
    long long index = 0;
    va_list args_list;

    srand(time(NULL));
    va_start(args_list, nums);

    for (int i = 0; i < nums; ++i){
        int cur_rand_val = (rand() % (MAX + 1 - MIN) + MIN) + va_arg(args_list, int);
        index += cur_rand_val;
    }

    va_end(args_list);

    if(index < 0){
        exit(EXIT_FAILURE);   //same as return 1
    }

    //displaying path
    char *path = getenv("PATH");
    printf("Path: %s\n", path);

    atexit(before_exit);

    return index;
}