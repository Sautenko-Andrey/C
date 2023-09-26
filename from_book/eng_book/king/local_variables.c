#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//automatic and static local variables

void calc_calls(int num);

int main(void)
{
    calc_calls(5);  //10
    calc_calls(5);  //20
    calc_calls(5);  //30

    srand(time(NULL));

    int val1 = rand() % 10;
    int val2 = rand() % 10;

    if(val1 > val2){
        static int x = 1;
    }
    else{
        int y = 0;
    }




    return 0;
}

void calc_calls(int num)
{
    static int calls = 0;    //static means that variable save value from call to call func

    for (int i = 0; i < num; ++i){
        printf("%d\n", i);
        calls += i;
    }

    printf("calls = %d\n", calls);
}