#include<stdio.h>
#include<stdarg.h>
#include<string.h>


//drfine func with variable amount arguments
int total_sum(int count, ...);
float get_money(float *deposit, int count, ...);
float calc_utility_bills(int count, ...);
void print_args(int count, ...);
void add_stars(char text[]);
void cut_fuck(char text[]);

int main(void)
{
    int sum = total_sum(2, 10, 10);
    printf("sum = %d\n", sum);

    //bank account
    float numbered_account = 1000.0f;

    get_money(&numbered_account, 5, 100.0, 100.0, 100.0, 100.0, 100.0);
    printf("Leftowers money : %.2f usd\n", numbered_account);

    //utility bills
    float water = 150.0f;
    float gas = 75.0f;
    float light = 200.0f;

    float my_bills = calc_utility_bills(3, water, gas, light);
    printf("I need to pay off %.2f\n", my_bills);

    print_args(3, "i love beer", "Docker is a cool app", "C is better then Java");

    char name[10] = "Andrey";
    add_stars(name);
    puts(name);

    //cutting bad word
    char some_text[100] = "She wants to fuck this man";
    puts(some_text);
    cut_fuck(some_text);
    puts(some_text);


    return 0;
}


//scripts
int total_sum(int count, ...)
{
    int total = 0;
    //special va_list pointer
    va_list arg_ptr;

    //initialize arg_ptr
    va_start(arg_ptr, count);

    for (int i = 0; i < count; ++i){
        //func va_arg returns current value of arg_ptr and move it further
        total += va_arg(arg_ptr, int);
    }

    va_end(arg_ptr);
    return total;
}

float get_money(float *deposit, int count, ...)
{
    va_list ptr_arg;

    va_start(ptr_arg, count);
    
    for(int i = 0; i < count; ++i){
        *deposit -= va_arg(ptr_arg, double);
    }

    va_end(ptr_arg);
    return *deposit;
}


float calc_utility_bills(int count, ...)
{
    float res = 0;
    va_list ptr;
    va_start(ptr, count);
    for(int i = 0; i < count; ++i){
        res += va_arg(ptr, double);
    }
    va_end(ptr);
    return res;
}

void print_args(int count, ...)
{
    va_list ptr;
    va_start(ptr, count);
    for(int i = 0; i < count; ++i){
        printf("#%d argument = %s\n", i + 1, va_arg(ptr, char *));
    }
    va_end(ptr);
}


void add_stars(char text[])
{
    size_t len_text = strlen(text);

    //adding * in the top
    for(int i = len_text; i > 0; --i){
        text[i] = text[i - 1];
    }
    text[0] = '*';

    //adding * in the end
    text[len_text + 1] = '*';
}

void cut_fuck(char text[])
{
    size_t len_text = strlen(text);
    for (int i = 0; i < len_text; ++i){
       if (text[i] == 'f'){
           if (text[i + 1] == 'u'){
	       if (text[i + 2] == 'c'){
	           if(text[i + 3] == 'k'){
		       text[i] = text[i - 1];
		       text[i + 1] = text[i - 1];
		       text[i + 2] = text[i - 1];
		       text[i + 3] = text[i - 1];

		       //deliting spaces
		       for (int k = 0; k < 5; ++k){
		           for(int j = i; j < len_text; ++j){
		               text[j] = text[j + 1];
			   }    
		       }
		   }
	       }
	   }
       }
    }
}



















