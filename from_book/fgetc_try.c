#include<stdio.h>
#include<stdlib.h>

int main(void)
{   
    short digs[5];
    short *ptr_digs = digs; 
    for(int i = 0; i < 5; ++i){
        printf("Enter #%d dig: ", i + 1);
        scanf("%hu", &digs[i]);
    }

    for (int i = 0; i < 5; ++i){
        printf("%d ", digs[i]);
    }
    putchar('\n');

    for(int i = 0; i < 5; ++i){
        printf("%d ", *ptr_digs++);
    }
    putchar('\n');

    for(int i = 0; i < 5; ++i){
        printf("Enter a #%d dig: ", i + 1);
        scanf("%hu", ptr_digs + i);
    }

    for(int i = 0; i < 5; ++i){
        printf("%d ", *ptr_digs++);
    }
    putchar('\n');


    return 0;
}