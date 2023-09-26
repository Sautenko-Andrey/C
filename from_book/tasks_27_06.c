#include<stdio.h>
#include<stdbool.h>

//constants for switch statement
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5

//functions
void replace_digs(void);
void replace_3digs(void);
int pow_int(int number, int pow);
void customers_survey(void);
void date_in_legal_form(void);


int main(void)
{   
    //replace_digs();
    //replace_3digs();

    int x = 10;
    int y = 12;

    int res = x > y;
    printf("Here must be 0, we got %d\n", res);

    int res2 = x < y;
    printf("Here must be 1, we got %d\n", res2);

    int result = pow_int(5,-5);
    printf("result = %d\n", result);

    //TERNARY OPERATOR
    short val_1 = 10;
    short val_2 = 20;

    short val_tot = (val_1 > val_2) ? val_1 : val_2;
    printf("val_tot = %d\n", val_tot);


    //Boolean variables
    _Bool flag;
    _Bool flag_2;
    flag = 5;   //it assigned as 1
    flag_2 = 0; //it assigned as 0
    printf("flag should be 1, we got : %d\n", flag);
    printf("flag_2 should be 0, we got : %d\n", flag_2);

    (flag) ? puts("True") : puts("False");
    (flag_2) ? puts("True") : puts("False");


    //if we include stdbool.h in directive it allows us to use bool instead _Bool
    bool my_flag;
    my_flag = 33;
    (my_flag) ? puts("True") : puts("False");

    //also it supplies true and false values
    bool value, scratch;
    value = true;
    scratch = false;

    printf("value = %d, scratch = %d\n", value, scratch);
    (value > scratch) ? puts("1 > 0") : puts("1 < 0");

    //this opportunity is more comfortable instead _Bool

    //switch statement
    //customers_survey();

    //correct date
    //date_in_legal_form();


    int i = 2, j = 3, k;
    k = i * j == 6;
    printf("must get 1, got %d\n", k);

    int i2 = 5, j2 = 10, k2 = 1;
    printf("must get 1 , got %d\n", k2 > i2 < j2);

    int i3 = 3, j3 = 2, k3 = 1;
    printf("must get 1, got %d\n", i3 < j3 == j3 < k3);

    int i4 = 3, j4 = 4, k4 = 5;
    printf("must get , got %d\n", i4 % j4 + i4 < k4);





    return 0;
}



void replace_digs(void)
{
    int x, y;
    printf("Enter a two-digit number : ");
    scanf("%1d%1d", &x, &y);

    printf("The reversal is : %d%d\n", y, x);
}

void replace_3digs(void)
{
    int x, y, z;
    printf("Enter a three-digit number : ");
    scanf("%1d%1d%1d", &x, &y, &z);

    printf("The reversal is : %d%d%d\n", z, y, x);
}

int pow_int(int number, int pow)
{   
    if (number < 0 || pow < 0){
        puts("AttributeError!");
        return -1;
    }

    if(pow == 0){
        return 1;
    }
    else if(pow == 1){
        return number;
    }
    else{
        int res = 1;
        for (int i = 0; i < pow; ++i){
            res*=number;
        }
        return res;
    }
}

void customers_survey(void)
{   
    int respond;
    printf("How you can evaluate our service from 1 to 5 ? ");
    scanf("%d", &respond);

    //verify input

    if (respond < 1 || respond > 5){
        puts("Input error!");
        return;
    }

    switch (respond)
    {
    case ONE:
        puts("Utterly negative experience.");
        break;

    case TWO:
        puts("A low assessment!");
        break;

    case THREE:
        puts("A median assessment.");
        break;

    case FOUR:
        puts("A good assessment! Good job!");
        break;

    case FIVE:
        puts("Excellent! Well done!");
        break;

    default:
        puts("Error!");
        break;
    }
}

void date_in_legal_form(void)
{
    int month, day, year;

    printf("Enter date (mm/dd/year) : ");
    scanf("%d /%d /%d", &month, &day, &year);

    printf("Dated this %d", day);

    switch (day)
    {
    case 1: case 21: case 31:
        printf("st");
        break;
    
    case 2: case 22:
        printf("nd");
        break;

    case 3: case 23:
        printf("rd");
        break;
    
    default:
        printf("th");
        break;
    }

    printf(" day of ");

    switch (month)
    {
    case 1: printf("January"); break;
    case 2: printf("February"); break;
    case 3: printf("March"); break;
    case 4: printf("April"); break;
    case 5: printf("May"); break;
    case 6: printf("June"); break;
    case 7: printf("July"); break;
    case 8: printf("August"); break;
    case 9: printf("September"); break;
    case 10: printf("October"); break;
    case 11: printf("November"); break;
    case 12: printf("December"); break;
    }

    printf(", 20%.2d.\n", year);


}