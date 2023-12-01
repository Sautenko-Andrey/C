#include<stdio.h>

enum ops {hello, bye, watsap, ok};

void say_hello(void);
void say_bye(void);
void say_watsap(void);
void say_ok(void);
void user_select(void);

int main(){
  
    user_select();
    
    return 0;
}

void user_select(void)
{
    int user_command, n_args;

    printf("Enter command (0 - hello, 1 - bye, 2 - wahtsap, 3 -ok) : ");
    n_args = scanf("%d", &user_command);

    if(n_args != 1){
        fprintf(stderr, "Error: arguments amount error in scanf.\n");
	return;
    }

    switch((enum ops)user_command){
        case hello:
	    say_hello();
	    break;
	case bye:
	    say_bye();
	    break;
	case watsap:
	    say_watsap();
	    break;
	case ok:
	    say_ok();
	    break;
    }

}

void say_hello(void)
{
    puts("Hello, user!");
}

void say_bye(void)
{
    puts("Bye, user!");
}

void say_watsap(void)
{
    puts("Whats's up, user?");
}

void say_ok(void)
{
    puts("Ok, user!");
}
