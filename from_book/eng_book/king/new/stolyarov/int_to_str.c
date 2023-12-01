#include<stdio.h>

#define MAX 32

void int_to_str_V1(void);
void int_to_str_V2(const char *path);

int main(void)
{
    int_to_str_V1();
    puts("------------------------");
    int_to_str_V2("digs.txt");
    
    return 0;
}


void int_to_str_V1(void)
{
    int num, digit, i;
    char buffer[MAX];


    for(;;){

        num = scanf("%d", &digit);
        if(num != 1){
            fprintf(stderr, "Error while scanf works\n");
            return;
        }

        if(digit == 0){
            break;
        }

        i = sprintf(buffer, "%d", digit);

        printf("String: %s, amount: %d\n", buffer, i);
    }

}


void int_to_str_V2(const char *path)
{
    FILE *file;
    char buffer[MAX + 1];
    int nums;

    file = fopen(path, "rb");

    if(!file){
        perror(path);
	return;
    }

    nums = fread(buffer, sizeof(char), MAX, file);
    /*if(nums < MAX){
        fprintf(stderr, "Error: fread can't correctly read data from file.\n");
	return;
    }*/
    printf("nums = %d\n", nums);
    puts(buffer);

    fclose(file);
}
