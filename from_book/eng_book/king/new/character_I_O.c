// Character I/O

#include<stdio.h>
#include<stdlib.h>

void ptr_check(void *pointer);

int main(void)
{   
    // Output functions

    FILE *fp;
    fp = fopen("text.txt", "a");
    ptr_check(fp);

    fputc(2806, fp);   

    putc(12345, fp);   //same as above

    fclose(fp);


    // Input functions

    FILE *my_file;
    my_file = fopen("text.txt", "r");
    ptr_check(my_file);

    int number = fgetc(my_file);
    printf("number = %d\n", number);

    // using loop
    int num;
    FILE *nums_file;
    nums_file = fopen("nums.txt", "r");
    ptr_check(nums_file);

    while((num = fgetc(nums_file))!= EOF){
        printf("num = %d\n", num);
    }


    return 0;
}


void ptr_check(void *pointer)
{
    if( pointer == NULL ){
        fprintf(stderr, "Error: Can't open file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}