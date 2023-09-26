#include<stdio.h>
#include<stdlib.h>

int* sum_digs(void);
int* sum_digs_modern(void);

int main(void)
{   
    /*
    printf("Enter a number : ");
    int number;
    scanf("%d", &number);

    int i = 1;
    while(i <= number){
        printf("%d -> %d\n", i, i * i);
        ++i;
    }
    */


    //let's get sum of integers
    //int *res_sum = sum_digs();
    //printf("Total = %d\n", *res_sum);

    int *result = sum_digs_modern();
    printf("Total = %d\n", *result);

}

int* sum_digs(void)
{   
    int sum = 0;
    printf("Enter integers (0 to terminate) :");

    int user_number;
    scanf("%d", &user_number);
    while(user_number != 0){
        sum += user_number;
        printf("Enter integers (0 to terminate) :");
        scanf("%d", &user_number);
    }

    int *ptr_sum = &sum;

    return ptr_sum;
}

int* sum_digs_modern(void)
{
    int *sum = malloc(sizeof(int));
    int user_number;
    printf("Enter integers (0 to terminate) :");
    scanf("%d", &user_number);

    while(user_number != 0){
        *sum += user_number;
        printf("Enter integers (0 to terminate) :");
        scanf("%d", &user_number);
    }
    return sum;
}
