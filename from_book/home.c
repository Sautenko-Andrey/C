/*This is imitation of the web-site GroceryApp*/

#include<stdio.h>
#include<stdlib.h>
#include"groceryapp.h"

char user[] = "Sautenko";

int main(void)
{   
    //getting user's request
    char *product = user_request();

    //searching item
    NN_job(product);

    free(product);

    return 0;
}