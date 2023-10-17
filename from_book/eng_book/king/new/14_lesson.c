#include<stdio.h>
#include<stdlib.h>

//for debbuging
#define POINTER_CHECK(pointer) ( (pointer) ? puts("OK") :\
printf("Memory allocation error in line %d\n", __LINE__))

//macros with a variable number of arguments
#define TEST( condition, ... ) ( (condition) ? printf("Passed test %s\n", #condition) :\
printf(__VA_ARGS__) );

//one more macros with a variable number of arguments
#define CHECK_PRICE( price_condition, ... ) ( (price_condition) ? puts("Price exists!") :\
printf(__VA_ARGS__) );


//the __func__ identifier
#define FUNCTION_CALLED() printf("%s called\n", __func__)
#define FUNCTION_RETURNS() printf("%s returns\n", __func__)

double max(double x, double y);

int main(void)
{   

    float voltage = 190.0;
    float max_voltage = 220.0;

    TEST( voltage <= max_voltage, "Voltage %2.f exceeds max_volatge %2.f\n", voltage, max_voltage );

    float potato_price = -29.75f;
    CHECK_PRICE((potato_price > 0.0) , "Potato is out of stock\n" );

    int *ptr = malloc(sizeof(int));
    POINTER_CHECK(ptr);
    free(ptr);

    double f_x = 100.90, f_y = 199.32;
    max(f_x, f_y);




    return 0;
}

double max(double x, double y)
{
    FUNCTION_CALLED();
    FUNCTION_RETURNS();
    return (x > y) ? x : y;
}