#include<stdio.h>

#define ARGS_MAX 2

int main(void)
{   
    int symbol, i;
    i = 0;
    
    while( (symbol = getchar()) != EOF){
	if(symbol == '\n'){
	    break;
	}

	i++;
        printf("#%d - %c\n", i, symbol);
    }

    return 0;
}
