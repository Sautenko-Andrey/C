#include<stdio.h>
#include<setjmp.h>

void say_hello(void);
void say_bye(void);


jmp_buf environment;

int main(void)
{   
    int val_setjmp = setjmp(environment);

    printf("setjmp(environment) = %d\n", val_setjmp);   // 0

    if (val_setjmp != 0){
        puts("Programm ends.");
        return 0;
    }

    printf("Doing something!!!\n");
    say_hello();





    return 0;
}

void say_hello(void)
{
    printf("Hello, user\n");
    say_bye();
}
void say_bye(void)
{
    printf("Good bye, user\n");
    longjmp(environment, 1);
}