#include<stdio.h>

void intfilesum(FILE *file, int *sum, int *count);

int main(void)
{
    FILE *file;
    int total, amount;
    file = fopen("digs.txt", "rb");
    if(!file){
        perror("digs.txt");
	return 1;
    }

    intfilesum(file, &total, &amount);
    fclose(file);
    printf("Total: %d\nAmount: %d\n", total, amount);

    /* Using stdin */
    intfilesum(stdin, &total, &amount);
    printf("Total: %d\nAmount: %d\n", total, amount);
    
    file = fopen("digs.txt", "ab");
    if(!file){
        perror("digs.txt");
	return 2;
    }

    fprintf(file, "Total: %d, amount: %d", total, amount);
    fclose(file);



    return 0;
}


void intfilesum(FILE *file, int *sum, int *count)
{
    int n;
    *sum = 0;
    *count = 0;

    while(fscanf(file, "%d", &n) == 1){
        *sum += n;
        (*count)++;
    }
}
