#include<stdio.h>

void read_kb_v1(void);
void read_kb_Modern(void);
void read_kb_count_lines(void);
void read_and_put(void);


int main(void)
{
    /*read_kb_v1();*/
    /*read_kb_Modern();*/
    /*read_kb_count_lines();*/
    read_and_put();

    return 0;
}


void read_kb_v1(void)
{
    int symbol;

    symbol = getchar();

    while(symbol != EOF){
        if(symbol == '\n'){
	    puts("OK");
	}

	symbol = getchar();
    }
}

void read_kb_Modern(void)
{
    int symbol;

    while( (symbol = getchar()) != EOF ){
        if(symbol == '\n'){
	    puts("OK");
	}
    }
}


void read_kb_count_lines(void)
{
    int symbol, counter;
    counter = 0;

    while( (symbol = getchar()) != EOF ){
        if(symbol == '\n'){
	    printf("%d\n", counter);
	    counter = 0;
	}
	else{
	    ++counter;
	}
    }
}


void read_and_put(void)
{
    int symbol, flag;

    flag = 1;  /* True */

    while( (symbol = getchar()) != EOF ){

        switch(symbol){
	    case '\n':
	        flag = 1;
		break;
	    case ' ':
		flag = 0;
		break;
	    default:
		if (flag){
		    putchar(symbol);
		}
	}
    }
}
