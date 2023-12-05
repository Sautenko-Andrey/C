#include<stdio.h>
#include<stdlib.h>
#include<time.h>


unsigned get_pseudo_rand_int(void);
int get_random(int from, int to);


int main(void)
{
    unsigned x = get_pseudo_rand_int();
    printf("x = %u\n", x);

    int y = get_random(1, 10);
    printf("y = %d\n", y);
    

    return 0;
}


unsigned get_pseudo_rand_int(void)
{
    srand(time(NULL));
    
    unsigned x = rand();
    return x;
}


int get_random(int from, int to)
{
    srand(time(NULL));
    
    return rand() % to + from;
}
