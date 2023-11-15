// Block I/O

#include<stdlib.h>
#include<stdio.h>

#define LEN 10
#define LEN_TEXT 236

static void check_ptr(void *ptr);

int main(void)
{   

    // Writting a data to stream

    int array[LEN] = {11,2,3,45,5,6,7,81,9,10};

    FILE *message;
    message = fopen("message.txt", "wb");
    check_ptr(message);

    size_t n = fwrite(array, sizeof(int), LEN, message);

    if(n < LEN){
        fprintf(stderr, "Error: while writting data\n");
        exit(EXIT_FAILURE);
    }

    fclose(message);


    // Reading a data from stream

    int my_array[LEN];

    FILE *fp;
    fp = fopen("message.txt", "rb");
    check_ptr(fp);

    size_t n2 = fread(my_array, sizeof(int), LEN, fp);
    if(n2 != LEN){
        fprintf(stderr, "Error: while reading data\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    for(int i = 0; i < LEN; ++i){
        printf("%d ", my_array[i]);
    }
    putchar('\n');


    // Reading a big text using fread
    FILE *fp_text;
    char my_msg[LEN_TEXT];
    fp_text = fopen("big_text.txt", "r");
    check_ptr(fp_text);

    size_t nums = fread(my_msg, sizeof(char), LEN_TEXT, fp_text);
    if (nums < LEN_TEXT){
        fprintf(stderr, "Error: while reading big text\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp_text);

    puts(my_msg);




    return 0;
}

static void check_ptr(void *ptr)
{
    if( ptr == NULL ){
        fprintf(stderr, "Error: can't open a file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}