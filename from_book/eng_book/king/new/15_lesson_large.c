//just for fun
#include<stdio.h>

#include"my_func.h"

extern int mutual_var;

int main(void)
{

    do_somth();
    display_val();
    get_data();

    printf("mutual_var = %d\n", mutual_var);

}