#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void introducing(void)
{
    char user_name[15];
    printf("Hi there! Text your name here : ");
    fgets(user_name, sizeof(user_name), stdin);

    user_name[strlen(user_name) - 1] = '\0';

    printf("Welcome to our app, %s !\n", user_name);
}

float get_value(void)
{
    float value;
    printf("value : ");
    scanf("%f", &value);

    return value;
}

float calc_utility_bills(float electric, float gas, float water, float heating)
{
    float total = electric + gas + water + heating;
    return total;
}

int main(void)
{
    introducing();

    float electric, gas, water, heating, result;

    electric = get_value();
    gas = get_value();
    water = get_value();
    heating = get_value();
    
    result = calc_utility_bills(electric, gas, water, heating);
    printf("You have to pay %.2f usd this month.", result);
    puts("");


    return 0;
}
