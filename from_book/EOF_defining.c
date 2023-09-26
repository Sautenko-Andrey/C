//Определение конца файла.Приминение feof()

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

void read_till_the_end(char *file_name);

int main(void)
{   
    //reading data from file till the EOF
    read_till_the_end("EPL_clubs.txt");

    return 0;
}

void read_till_the_end(char *file_name)
{   
    char club[MAX];
    int i = 1;
    //открываем файл на чтение
    FILE *file_ptr;

    if ( (file_ptr = fopen(file_name, "r")) == NULL ){
        fprintf(stderr, "Error opening file for reading!");
        exit(1);
    }

    while(feof(file_ptr) == 0){
        fgets(club, MAX, file_ptr);
        printf("%s", club);
    }

    putchar('\n');


    fclose(file_ptr);
}