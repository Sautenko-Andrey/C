#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(void)
{
    
    char name[] = "Andrey";
    char *buff = malloc(sizeof(char) * 15);
    if (buff == NULL){
        fprintf(stderr,"Memory allocation error.\n");
        exit(1);
    }


    printf("Enter a name: ");
    fgets(buff, 15, stdin);

    buff[strlen(buff) - 1] = '\n';

    printf("%s --- %s", name, buff);

    int res = strncmp(buff, name,6);
    printf("%d\n", res);

    if (res == 0){
        puts("Match");
    }
    else{
        puts("Error");
    }
    
    free(buff);
    
    return 0;
}