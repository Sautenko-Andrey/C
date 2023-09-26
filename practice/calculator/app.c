#include<stdio.h>
#include "scripts.h"

int main(void)
{    

    int respond = ask_user();
    if (respond == 0){
        sorting_array();
    }
    else{
        puts("Good bye!");
    }
    
    return 0;
}
