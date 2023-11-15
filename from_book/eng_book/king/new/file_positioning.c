// File positioning

#include<stdio.h>
#include<stdlib.h>

static void check_ptr(void *ptr);

int main(void)
{   
    FILE *fp;
    long file_pos;

    fp = fopen("big_text.txt", "a");
    check_ptr(fp);

    // Determing file position
    file_pos = ftell(fp); 
    printf("file position = %ld\n", file_pos);  //265

    //set file position to the begining
    fseek(fp,0,SEEK_SET);
    // Determing file position
    file_pos = ftell(fp); 
    printf("file position = %ld\n", file_pos);  //0

    //writitng a text
    char add_text[] = "Hello!";

    size_t n = fwrite(add_text, sizeof(char), sizeof(add_text)/sizeof(char), fp);

    if(n != sizeof(add_text)/sizeof(char)){
        fprintf(stderr, "Error: while addint a new message.\n");
        exit(EXIT_FAILURE);
    }

    //to the start
    rewind(fp);

    fclose(fp);





    return 0;
}

static void check_ptr(void *ptr)
{
    if( ptr == NULL ){
        fprintf(stderr, "Error: can't open a file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}