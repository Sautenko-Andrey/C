// fgetc , putc

#include<stdio.h>
#include<stdlib.h>

static void display_data(FILE *source);
static void pointer_check(void *ptr);
static void copy_file(const char *source, char *dest);


int main(void)
{   
    // FILE *file;
    // file = fopen("nums.txt", "rb");
    // pointer_check(file);


    // display_data(file);

    copy_file("nums.txt", "nums2.txt");

    return 0;
}

static void display_data(FILE *source)
{   
    int symb;

    while( ( symb = fgetc(source) ) != EOF ){
        printf("%u\n", symb);
    }
}

static void pointer_check(void *ptr)
{
    if( ptr == NULL ){
        fprintf(stderr, "Error: can't open file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}

static void copy_file(const char *source, char *dest)
{
    int symb;

    FILE *src_file, *dest_file;

    src_file = fopen(source, "rb");
    pointer_check(src_file);

    dest_file = fopen(dest, "wb");
    pointer_check(dest_file);

    while ( (symb = fgetc(src_file)) != EOF ){
        putc(symb, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);  
}