//just for fun
#include<stdio.h>

#define MSG(func) printf("Call %s() function\n", #func)


void do_somth(void)
{
    MSG(do_somth);
}

void display_val(void)
{
    MSG(display_val);
}

void get_data(void)
{
    MSG(get_data);
}