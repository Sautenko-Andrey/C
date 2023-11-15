// Formating I/O

#include<stdio.h>
#include<stdlib.h>

void open_check(void *ptr);
int find_int(const char *file_name);


int main(void)
{   

    //Writting data in file via fprintf

    FILE *fp;
    fp = fopen("my_file.txt", "w");
    open_check(fp);

    //let's write something into file fp via fprintf
    fprintf(fp, "Message from fprintf.\n");
    fclose(fp);


    //Conversion specifications
    int val = 123;
    printf("[%8d]\n", val);    //[     123]
    printf("[%-8d]\n", val);   //[123     ]
    printf("[% 8d]\n", val);   //[     123]
    printf("[%08d]\n", val);    //[00000123]
    printf("[%- 8d]\n", val);   //[ 123    ]


    //reading data from file using fscanf
    FILE *fp2;
    fp2 = fopen("my_file.txt", "r");
    open_check(fp2);

    char symbol;
    fscanf(fp2, "%c", &symbol);
    printf("symbol = %c\n", symbol);    //symbol = M

    fclose(fp2);

    // Detecting EOF and error conditions





    return 0;
}


void open_check(void *ptr)
{
    if(ptr == NULL){
        fprintf(stderr, "Error: can't open file.\n");
        exit(EXIT_FAILURE);
    }
}

int find_int(const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    int n;

    if (fp == NULL){
        return -1;          // can't open file
    }

    while( fscanf(fp, "%d", &n) != 1 ){
        if (ferror(fp)){
            fclose(fp);
            return -2;       // read error (ошибки в потоке)
        }

        if(feof(fp)){
            fclose(fp);
            return -3;  // integernot found
        }
    }
    
}