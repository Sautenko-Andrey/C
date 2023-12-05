#include<stdio.h>
#include<stdarg.h>


void sum_double(char *name, ... );


int main(void)
{
    sum_double("Utility bills", 150.0, 25.0, 125.0);

    return 0;
}


void sum_double(char *name, ... )
{
    double cur_value, total = 0.0;
    va_list args_list;
    va_start(args_list, name);

    while( (cur_value = va_arg(args_list, double)) != 0.0 ){
        total += cur_value;
    }
    
    va_end(args_list);

    printf("%s = %.2f\n", name, total);
}
