#include<stdio.h>
#include<stdlib.h>

void read_data(const char *path);


int main(void)
{
    read_data("data.txt");

    return 0;
}


void read_data(const char *path)
{
    FILE *file;
    int symbol;

    file = fopen(path, "rb");

    if(!file){
        perror("path");
	exit(EXIT_FAILURE);
    }

    while( (symbol = fgetc(file)) != EOF ){
        putchar(symbol);
    }

}
