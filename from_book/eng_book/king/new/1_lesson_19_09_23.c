//Introducing
#include<stdio.h>
#include<stdlib.h>

void print_asteriks(void);
void compute_volume(float radius);
void add_tax(void);
void polinominal(void);
void pay_way(void);
void bank_loan(void);
void convert_date(void);

int main(void)
{
    //printf("To C, or not to C: that is the question.\n");
    
    //first task
    //print_asteriks();

    //second task
    //compute_volume(10);

    //third task
    //add_tax();

    //fourth task
    //polinominal();

    //fifth task
    //pay_way();

    //sixth task
    //bank_loan();

    // printf("\"quotation marks\"\n");
    // printf("i want to use \\ here.\n");

    // //scanf trick
    // int i, j;
    // float x,y;
    // scanf("%d%d%f%f", &i, &j, &x, &y);
    // printf("i = %d, j = %d, x = %f, y = %f\n", i,j,x,y);

    //seventh task
    convert_date();


    return 0;
}

void print_asteriks(void)
{
    printf("       *\n      *\n     *\n*   *\n * *\n  *\n");
}

void compute_volume(float radius)
{   
    float pi = 3.14f;
    float r_cub = radius * radius * radius;

    float volume = 4.0f/3.0f * pi * r_cub;

    printf("Volume = %f\n", volume);
}

void add_tax(void)
{   
    //declearing variables
    float dollars, tax;


    //getting dollars and tax value from user
    printf("Enter an amount: ");
    scanf("%f",&dollars);
    printf("Enter a tex value: ");
    scanf("%f", &tax);

    //checking arguments
    if (dollars < 0 || tax < 0){
        fprintf(stderr, "Arguments must be greater 0.");
        exit(1);
    }

    //if arguments are correct we are going to compute value
    float value = dollars + (dollars / 100.0 * tax);

    //finally, we're displaying value
    printf("With tax added: $%.2f\n", value);
}

void polinominal(void)
{
    int x;

    printf("Enter x value: ");
    scanf("%d", &x);

    int polinominal = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x -x*x + 7*x - 6;
    printf("Polinominal = %d\n", polinominal);
}

void pay_way(void)
{   
    int dollar_amount;
    int twenty = 20, ten = 10, five = 5, one = 1;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollar_amount);

    //computing how many 20$ we need
    int dev_twenty = dollar_amount / twenty;

    //how many 10$ we need
    int leftovers = dollar_amount - (twenty * dev_twenty);
    
    int dev_ten = leftovers / ten;
    
    //how may 5$ we need
    leftovers = leftovers - (ten * dev_ten);
   
    int dev_five = leftovers / five;

    //how many 1$ we need
    leftovers = leftovers - (five * dev_five);
  
    int dev_one = leftovers / one;

    //dsiplayin result
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n",dev_twenty,\
dev_ten, dev_five, dev_one);

}

void bank_loan(void)
{   
    float loan,rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float rate_per_month = rate / 100 / 12;
    
    float after_1st_month = (loan + (loan * rate_per_month)) - monthly_payment;
    float after_2nd_month = (after_1st_month + (after_1st_month * rate_per_month)) - monthly_payment;
    float after_3d_month = (after_2nd_month + (after_2nd_month*rate_per_month)) - monthly_payment;

    printf("Balance remaining after first payment: $%.2f\n",after_1st_month);
    printf("Balance remaining after second payment: $%.2f\n",after_2nd_month);
    printf("Balance remaining after third payment: $%.2f\n",after_3d_month);

}

void convert_date(void)
{   
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("month = %d, day = %d, year = %d\n", month, day, year);

    if (month < 10){
        printf("You entered the date: %d0%d%d\n", year, month, day);
    }
    else if(day < 10){
        printf("You entered the date: %d%d0%d\n", year, month, day);
    }
    else if(month > 10 && day > 10){
        printf("%d%d%d\n",year, month, day);       
    }
    else{
        puts("!");
        printf("You entered the date: %d0%d0%d\n", year, month, day);
    }
}