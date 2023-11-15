//Input/output

#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "vocabulary.dat"



int main(void)
{
    FILE *file_ptr_1, *file_ptr_2;


    //Opening a file
    FILE *file;
    file = fopen("my_file.txt", "r");  //opens my_file.txt for reading
    if(file == NULL){
        fprintf(stderr, "Error: open file in line %d\n", __LINE__);
    }
    fclose(file);



    //Opening and closing file
    FILE *fp;
    fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        fprintf(stderr, "Can't open file %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    /* other statements */
    fclose(fp);


    //Attaching a file to an open stream
    printf("This massage appears on the screen\n");
    FILE *fr_file;
    fr_file = freopen("my_file.txt","a", stdout);
    if(fr_file == NULL){
        fprintf(stderr, "Can't open file my_file.txt\n");
        exit(EXIT_FAILURE);
    }
    printf("This will be written to file\n");
    fclose(fr_file);

    return 0;
}