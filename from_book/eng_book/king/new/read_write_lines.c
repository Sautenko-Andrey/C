// Lines I/O


#include<stdlib.h>
#include<stdio.h>

static void check_ptr(void *ptr);


int main(void)
{       
    // Writting

    FILE * fp;
    fp = fopen("message.txt", "w");
    check_ptr(fp);

    fputs("This is the first message.", fp);

    fclose(fp);

    


    // Reading
    char some_text[50];
    
    FILE * fp2;
    fp2 = fopen("message.txt", "r");
    check_ptr(fp);

    fgets(some_text, sizeof(some_text), fp2);

    fclose(fp2);

    puts(some_text);


    return 0;
}

static void check_ptr(void *ptr)
{
    if( ptr == NULL ){
        fprintf(stderr, "Error: can't open a file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}