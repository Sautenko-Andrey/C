#include<stdio.h>
#include<string.h>


int get_data(void)
{
    int temp, array[10];
    for(int i = 0; i < 10; ++i){
        scanf("%d", &temp);
	array[i] = temp;
    }

    return array;
}
