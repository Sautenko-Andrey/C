// <stdarg.h>  . Variable arguments

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>

static int max_int(int n, ...);
static void display_args(int arg_nums, ...);
static double avg_double(int nums, ...);

int main(void)
{      
    display_args(3, "one", "two", "three");

    double avg_res = avg_double(5, 10.0, 15.0, 20.0, 55.75, 99.99);
    printf("Average price: %.4f $\n", avg_res);

    return 0;
}

static int max_int(int n, ...)
{
    va_list ap;
    int i, current, largest;

    va_start(ap, n);  //variable-length begins after parametr n

    largest = va_arg(ap, int);  //fetches first argument after n and advances forward to next arg

    for(i = 0; i < n; ++i){
        current = va_arg(ap,int);  //fetches remaining arguments after largest one by one
        if(current > largest){
            largest = current;
        }
    }

    va_end(ap);
    return largest;
}

static void display_args(int arg_nums, ...)
{
    va_list ap;
    char *current_arg;

    va_start(ap, arg_nums);

    for(int i = 0; i < arg_nums; ++i){
        current_arg = va_arg(ap, char *);
        puts(current_arg);
    }

    va_start(ap, arg_nums);// return to the top
    printf("First argument is: %s\n", va_arg(ap, char *));

    va_end(ap);
}

static double avg_double(int nums, ...)
{
    va_list ap;
    double current_arg, total = 0;

    va_start(ap, nums);
    for(int i = 0; i < nums; ++i){
        current_arg = va_arg(ap, double);
        total += current_arg;
    }

    va_end(ap);

    return total / (double)nums;
}
