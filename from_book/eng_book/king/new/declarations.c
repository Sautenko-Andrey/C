//Declarations

#include<stdio.h>
#include<string.h>

char digit_to_hex(int digit);   //slow version
char digit_to_hexFast(int digit);   //fast version

void call_me(void);

static int counter = 0;

//using register

double compute_sum(double *array, size_t len);

extern int cmp_int(const void *x, const void *y);   //no effect

static int cmp_ch(const void *symb_1, const void *symb_2);  //no axcess from other files
/*use static with func declaration if this function doesn't pretend to be called from
another file*/

//using inline with functions
inline int max_int(int x, int y);

inline static int min_int(int x , int y);


int main(void)
{   
    extern int x;  //will define somewhere later

    
    call_me();
    call_me();
    call_me();

    //testing function with a register variable
    double prices[4] = {15.00, 44.75, 96.35, 10.9};
    double total = compute_sum(prices, 4);
    printf("Total = %.2f $\n", total); 


    //complex declaration
   int* (*ptr_funcs[10])(void); /* this is array of pointers to functions without 
   parameters what return pointer on type int */
    


    return 0;
}

char digit_to_hex(int digit)
{
    const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}

char digit_to_hexFast(int digit)
{
    static const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}

void call_me(void)
{
    puts("Hi!");
    ++counter;
    printf("You called me %d times!\n", counter);
}

double compute_sum(double *array, size_t len)
{
    register int i;         //using register for speed
    double sum_res = 0;

    for(i = 0; i < len; ++i){
        sum_res += *(array + i);
    }

    return sum_res;
}

static int  cmp_ch(const void *symb_1, const void *symb_2)
{
    return strcmp( *(char**)symb_1, *(char**)symb_2 );
}

inline int max_int(int x, int y)
{
    return (x > y)? x: y;
}

inline static int min_int(int x , int y)
{
    return (x < y)? x:y;
}