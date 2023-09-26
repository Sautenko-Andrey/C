#include<stdio.h>
#include "scripts.h"

int main(void)
{
    int array[10] = get_data();
    for (int i = 0; i < 10; ++i){
        printf("%d ", array[i]);
    }
    puts("");
	
    return 0;
}
