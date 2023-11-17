// Nonlocal jumps
// Tests setjmp / longjump

#include<stdio.h>
#include<setjmp.h>


jmp_buf env;

void func_1(void);
void func_2(void);


int main(void)
{   
    if(setjmp(env) == 0){
        printf("setjmp returned 0");
    }
    else{
        printf("Program terminates: longjump called\n");
        return 0;
    }

    func_1();
    printf("Program terminates normally\n");

    return 0;
}

void func_1(void)
{
    printf("function_1 begins\n");
    func_2();
    printf("function_1 returns\n");
}

void func_2(void)
{
    printf("function_2 begins\n");
    longjmp(env, 1);
    printf("function_2 returns\n");
}