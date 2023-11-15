// Copying file program

//Copies a file

#include<stdio.h>
#include<stdlib.h>

void ptr_check(void *pointer);

int main(int argc, char *argv[]){

    FILE *source_file, *dest_file;

    int symb;

    //checking arguments amount
    if(argc != 3){
        fprintf(stderr, "Error: write command as <copying_file source_name destination_name>\n");
        exit(EXIT_FAILURE);
    }

    source_file = fopen(argv[1], "rb");
    ptr_check(source_file);

    dest_file = fopen(argv[2], "wb");
    ptr_check(dest_file);

    //copying data
    while( (symb = fgetc(source_file)) != EOF ){
        putc(symb, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    return 0;
}

void ptr_check(void *pointer)
{
    if (pointer == NULL){
        fprintf(stderr, "I can't open file in line %d\n", __LINE__);
        exit(EXIT_FAILURE);
    }
}