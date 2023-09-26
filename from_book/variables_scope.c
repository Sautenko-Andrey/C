//Область действия переменных
#include<stdio.h>

int outer_var = 100;
int outer_null;

void print_outer_var(void);

int main(void)
{       
    //правилo хорошего тона используем глобальную переменную через extern
    extern int outer_var;

    printf("This is using outer_var = %d\n", outer_var);

    //using func
    print_outer_var();

    //should print null
    printf("0 = %d\n", outer_null);

    return 0;

}

void print_outer_var(void)
{   
    //согласно правилу хорошего тона
    extern int outer_var;
    printf("Printing outer_var by function ---> outer_var = %d\n", outer_var);
}