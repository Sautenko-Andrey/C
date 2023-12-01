#include<stdio.h>

#define LEN 10

int main(void)
{
    char ch_array[LEN + 1];
    int nums;

    nums = scanf("%10s", ch_array);
    if(nums != LEN){
        fprintf(stderr, "Error: read less then 10 symbols\n");
	return 1;
    }

    puts(ch_array);



    return 0;

}
