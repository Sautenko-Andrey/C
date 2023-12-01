#include<stdio.h>

#define MAX_LINE 10


int main(int argc, char *argv[])
{
    int symbol, line_counter;

    FILE *original, *copy;
    
    if( argc != 3 ){
        fprintf(stderr,"Error: Too few arguments\n");
	return 1;
    }

    /* Open original for reaing */
    original = fopen(argv[1], "rb");
    if(!original){
        perror(argv[1]);
	return 2;
    }

    /* Opening copy for writing */
    copy = fopen(argv[2], "wb");
    if(!copy){
        perror(argv[2]);
	return 3;
    }
    
    line_counter = 0;

    while( (symbol = fgetc(original)) != EOF ){
	fputc(symbol, copy);
        if(symbol == '\n'){
	    ++line_counter;
	}
	if(line_counter >= MAX_LINE){
	    break;
	}
    }

    return 0;
}
