#include<stdio.h>


void clock(void);
void beaufort_scale(void);
void calc_tax(void);
void large_and_small(void);
void date_compare(void);
void convert_grade(void);
void convert_int_in_word(void);

int main(void)
{   
    //let's call clock function!
    //clock();

    //let's call beafourt scale
    //beaufort_scale();

    //let's call calc tax
    //calc_tax();

    //let's find largest and smallest integer
    //large_and_small();

    //date_compare();

    //convert_grade();

    convert_int_in_word();

    return 0;
}

void clock(void)
{   
    char hours, minutes;

    printf("Enter a 24-time (21:11): ");
    scanf("%hhd:%hhd", &hours, &minutes);

    printf("Equivalent 12-hour time : ");

    switch (hours)
    {
    case 1: case 13: printf("1"); break;
    case 2: case 14: printf("2"); break;
    case 3: case 15: printf("3"); break;
    case 4: case 16: printf("4"); break;
    case 5: case 17: printf("5"); break;
    case 6: case 18: printf("6"); break;
    case 7: case 19: printf("7"); break;
    case 8: case 20: printf("8"); break;
    case 9: case 21: printf("9"); break;
    case 10: case 22: printf("10"); break;
    case 11: case 23: printf("11"); break;
    case 12: printf("12"); break;
    case 24: printf("00");break;
    
    default:
    printf("Input data error!");
        break;
    }

    printf(" : %.2d", minutes);

    switch (hours)
    {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
        printf(" AM\n");
        break;

    case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24:
        printf(" PM\n");
        break;
    }
}

void beaufort_scale(void)
{   
    char knots_speed;
    printf("Enter a wind speed in knots : ");
    scanf("%hhd", &knots_speed);

    if (knots_speed < 1){
        printf("Calm\n");
    }
    else if (knots_speed >= 1 && knots_speed <= 3){
        printf("Light air\n");
    }
    else if (knots_speed >= 4 && knots_speed <= 27){
        printf("Breeze\n");
    }
    else if (knots_speed >= 28 && knots_speed <= 47){
        printf("Gale\n");
    }
    else if(knots_speed >= 48 && knots_speed <= 63){
        printf("Storm\n");
    }
    else if (knots_speed > 63){
        printf("Hurricane\n");
    }
    else{
        printf("Incorrect input!\n");
    }
}

void calc_tax(void)
{   
    const float mand_pay_1 = 7.5f;
    const float mand_pay_2 = 37.5f;
    const float mand_pay_3 = 82.50f;
    const float mand_pay_4 = 142.50f;
    const float mand_pay_5 = 230.00f;

    double income;

    printf("Enter the amount of taxeble income : ");
    scanf("%lf", &income);

    if (income < 750 && income > 0){
        printf("Tax = %.2lf usd\n", income / 100 * 1);
    }
    else if (income >= 750 && income < 2250){
        printf("Tax = %.2lf usd\n", mand_pay_1 + (income /100 * 2));
    }
    else if (income >= 2250 && income < 3750){
        printf("Tax = %.2lf usd\n", mand_pay_2 + (income / 100 * 3));
    }
    else if (income >= 3750 && income < 5250){
        printf("Tax = %.2lf usd\n", mand_pay_3 + (income / 100 * 4));
    }
    else if (income >= 5250 && income < 7000){
        printf("Tax = %.2lf usd\n", mand_pay_4 + (income / 100 * 5));
    }
    else if (income >= 7000){
        printf("Tax = %.2lf usd\n", mand_pay_5 + (income / 100 * 6));
    }
    else{
        printf("Income can't be less then zero!");
    }
}

void large_and_small(void)
{   
    int integers_list[4] = {0, 0, 0, 0};

    int *ptr = integers_list;

    printf("Enter four integers : ");
    scanf("%d %d %d %d", ptr, ptr + 1, ptr + 2, ptr + 3);

    int min_index;
    for (int i = 0; i < 3; ++i){
        min_index = i;

        for(int j = i + 1; j < 4; ++j){
            if(integers_list[min_index] > integers_list[j]){
                min_index = j;
            }
        }

        if (min_index != i){
            int temp = integers_list[i];
            integers_list[i] = integers_list[min_index];
            integers_list[min_index] = temp;
        }
    }

    printf("Largest : %d\nSmallest : %d\n", integers_list[3], integers_list[0]);
}

void date_compare(void)
{   
    int first_month, first_day, first_year;
    int sec_month, sec_day, sec_year;

    printf("Enter first date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &first_month, &first_day, &first_year);
    printf("Enter second date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &sec_month, &sec_day, &sec_year);

    if (first_year < sec_year){
        printf("%d/%d/%d is earlier then %d/%d/%d\n", first_month, first_day, first_year, sec_month, sec_day, sec_year);
    }
    else if (first_year > sec_year){
        printf("%d/%d/%d is earlier then %d/%d/%d\n", sec_month, sec_day, sec_year, first_month, first_day, first_year);
    }
    else{
        if(first_month < sec_month){
            printf("%d/%d/%d is earlier then %d/%d/%d\n", first_month, first_day, first_year, sec_month, sec_day, sec_year);
        }
        else if(first_month > sec_month){
            printf("%d/%d/%d is earlier then %d/%d/%d\n", sec_month, sec_day, sec_year, first_month, first_day, first_year);
        }
        else{
            if (first_day < sec_day){
                printf("%d/%d/%d is earlier then %d/%d/%d\n", first_month, first_day, first_year, sec_month, sec_day, sec_year);
            }
            else{
                printf("%d/%d/%d is earlier then %d/%d/%d\n", sec_month, sec_day, sec_year, first_month, first_day, first_year);
            }
        }
    }
}

void convert_grade(void)
{   
    char grade;

    printf("Enter numerical grade (0 - 100): ");
    scanf("%hhd", &grade);

    if (grade < 0){
        puts("Input error!");
    }

    switch (grade)
    {
    case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: case 100:
        printf("A\n");
        break;

    case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89:
        printf("B\n");
        break;

    case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:
        printf("C\n");
        break;

    case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69:
        printf("D\n");
        break;

    default:
        printf("F\n");
        break;
    }
}

void convert_int_in_word(void)
{   
    int first, sec;
    printf("Enter a two-digit number : ");
    scanf("%d%d", &first, &sec);

    printf("You entered the number ");

    switch (first)
    {
    case 2:printf("twenty");break;
    case 3:printf("thirty");break;
    case 4:printf("fourty");break;
    case 5:printf("fifty");break;
    case 6:printf("sixty");break;
    case 7:printf("seventy");break;
    case 8:printf("eighty");break;
    case 9:printf("ninety");break;
    default:
        break;
    }

    switch (sec)
    {
    case 1:
        printf(" one\n");
        break;
    case 2:
        printf(" two\n");
        break;
    case 3:
        printf(" three\n");
        break;
    case 4:
        printf(" four\n");
        break;
    case 5:
        printf(" five\n");
        break;
    case 6:
        printf(" six\n");
        break;
    case 7:
        printf(" seven\n");
        break;
    case 8:
        printf(" eight\n");
        break;
    case 9:
        printf(" nine\n");
        break;
    default:
        break;
    }

    if (first == 1 && sec == 0){
        printf("ten\n");
    }
    else if(first = 1 && sec == 1){
        printf("eleven\n");
    }
    else if(first = 1 && sec == 2 ){
        printf("twelv\n");
    }
    else if(first = 1 && sec == 3 ){
        printf("therteen\n");
    }
    else if(first = 1 && sec == 4 ){
        printf("fourteen\n");
    }
    else if(first = 1 && sec == 5 ){
        printf("fifteen\n");
    }
    else if(first = 1 && sec == 6 ){
        printf("sizteen\n");
    }
    else if(first = 1 && sec == 7 ){
        printf("seventeen\n");
    }
    else if(first = 1 && sec == 8 ){
        printf("eighteen\n");
    }
    else if(first = 1 && sec == 9 ){
        printf("nineteen\n");
    }
}

