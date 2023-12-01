#include<stdio.h>
#include<stdlib.h>



int main(void)
{
    FILE *file;

    file = fopen("data2.txt", "rb");

    if (!file){
        perror("data.txt");
	exit(1);
    }
    
    fclose(file);

    return 0;
}
