// File buffering
#include<stdio.h>
#include<stdlib.h>



int main(void)
{   
    FILE *fp;
    fp = fopen("my_file.txt", "a");
    if(fp == NULL){
        fprintf(stderr, "Error: can't open file in line %d.\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    fflush(fp); //flushes data from buffer to file fp right here

    fclose(fp);



    return 0;
}