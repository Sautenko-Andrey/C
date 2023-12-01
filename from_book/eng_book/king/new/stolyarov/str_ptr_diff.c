#include<stdio.h>


int main(void)
{
    /* declaring and initializing char array */
    char word[] = "Hello";
    puts(word);

    /* changing value in word[4] */
    word[4] = 'X';
    puts(word);

    /* Declaring and initializing char pointer */
    char *ptr = "What's up?";
    puts(ptr);

    /* trying to change ptr[0] */
    /*
    ptr[0] = 'X';    error! segmanetation fault.
    puts(ptr);
    */



    return 0;
}
