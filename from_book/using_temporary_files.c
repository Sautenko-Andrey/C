//Использование временных файлов
#include<stdio.h>
#include<stdlib.h>


int main(void)
{   
    char buffer[20];

    tmpnam(buffer);

    printf("Temporary file name is %s\n", buffer);

    if ( (remove(buffer)) == 0 ){
        puts("All clean!");
    }
    else{
        puts("Error!");
    }

    return 0;
}