#include<stdio.h>
#include<stdlib.h>


int* calc_numbers(void);


int main(void)
{   

    //lets calc how many digit consist in number
    int *user_dig = calc_numbers();

    printf("user's dig is %d\n", *user_dig);

    free(user_dig);

    return 0;
}

int* calc_numbers(void)
{
    int user_input;
    printf("Enter a number : ");

    scanf("%d", &user_input);

    if (user_input > 0 && user_input < 10){
        printf("The number %d has 1 digit.\n", user_input);
    }
    else if (user_input > 9 && user_input < 100){
        printf("The number %d has 2 digits.\n", user_input);
    }
    else{
        printf("The number %d has 3 or more then 3 digits.\n", user_input);
    }

    int *ptr_dig = malloc(sizeof(int));

    *ptr_dig = user_input;


    return ptr_dig;
}