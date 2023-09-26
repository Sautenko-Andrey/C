#include<stdio.h>
#include"common.h"
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

int main(void)
{
    int buffer;
    int repeated[10] = {0};
    char str_int[MAX];
    

    printf("Enter a number:");
    scanf("%d", &buffer);
    sprintf(str_int, "%d", buffer);
    size_t length = strlen(str_int);

    int mod_buff[length];

    int i = 0;
    while(buffer > 0){
        int mode = buffer % 10;
        mod_buff[length - 1 - i] = mode;
        ++i;
        buffer /= 10;
    }

    for (int i = 0; i < length; ++i){
        if(mod_buff[i] || !mod_buff[i]){
            repeated[mod_buff[i]] += 1;
        }

    }
    //printf_arr(repeated, length, 'i');

    printf("Repeated digits: ");
    for (int i = 0; i < 10; ++i){
        if (repeated[i] > 1){
            printf("%d ", i);
        }
    }
    putchar('\n');

    return 0;
}