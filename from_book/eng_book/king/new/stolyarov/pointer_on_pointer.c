#include<stdio.h>

#define MAX 5


int main(void)
{
    int value = 100;
    int *ptr = &value;
    int **ptr_ptr = &ptr;
   
    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);
    printf("**ptr = %d\n", **ptr_ptr);

    /* With arrays */
    char *names[MAX] = {"Andrey","Igor","Svetlana","Kate", "Alex"};
    
    /* Getting names one by one */
    for(int i = 0; i < MAX; i++){
        printf("#%d\t%s\n", i + 1, *(names + i));
    }
    
    /* Getting access to every name */
    char **name = names;
    printf("%c\n", **name);
    printf("%c\n", *(*name + 1));

    



    return 0;
}
