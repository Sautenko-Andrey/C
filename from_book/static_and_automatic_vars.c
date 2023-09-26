//Статические и автоматические переменные
#include<stdio.h>

void count_times(void);
void count_times_V2(void);

static char global_static_text[] = "You can see me only at this page, not at others";

int main(void)
{   
    //let's make loop with operator for
    for(int i = 0; i < 10; ++i){
        puts("We are doing something...");
        count_times();
    }

    puts("_____________________");

    //let's make loop with operator for
    for(int i = 0; i < 5; ++i){
        puts("We are doing something...");
        count_times_V2();
    }

    puts(global_static_text);

    return 0;
}

void count_times(void)
{
    static int counter = 1; //сохраняет свое значение между вызовами этой функции
    int regular_var = 1; // не сохраняет свое значение между вызовами функции
    printf("You have used this function %d time(s) and regular_var = %d\n", counter, regular_var);
    counter++;
    regular_var++;
}

void count_times_V2(void)
{
    static int x;
    int y;
    printf("Ты использовал эту функцию %d раз, переменная y = %d\n", x, y);
    x++;
    y++;
}
