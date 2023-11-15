// Obtaining file names from the command line

/*
    Programm: checks whether a file can be opened for reading
*/
#include<stdio.h>
#include<stdlib.h>



int main(int argc, char *argv[])
{   
    FILE *fp;

    //checking number of arguments
    if (argc != 2){
        fprintf(stderr, "Usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    if( (fp = fopen(argv[1], "r")) == NULL ){
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%s can be opened.\n", argv[1]);

    fclose(fp);

    return 0;
}