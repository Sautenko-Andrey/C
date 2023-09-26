#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    
    int origin[20] = {1,2,3,4,5,6,7,8,9,10};

    int copy_orig[10];

    memcpy(copy_orig, origin, 10 * (sizeof(int)));

    for (int i = 0; i < sizeof(copy_orig)/sizeof(*copy_orig); ++i){
        printf("%d ", copy_orig[i]);
    }

    puts("");

    return 0;
}