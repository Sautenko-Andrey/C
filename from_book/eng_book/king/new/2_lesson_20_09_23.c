#include<stdio.h>
#include<stdlib.h>

void product_info(void);
void ISBN_separate(void);
void convert_tel_number(void);
void reverse_dig(void);
void reverse_3dig(void);
void calc_num_digs(void);
void convert_time(void);
void convert_time2(void);
void biggest_number(void);
int cmp_val(const void* arg1, const void* arg2);
int main(void)
{   
    //second task
    //product_info();

    //third task
    //ISBN_separate();

    //fourth task
    //convert_tel_number();

    //fifth task
    //reverse_dig();

    //sixth task
    //reverse_3dig();

    //seventh task
    //calc_num_digs();

    //8 task
    //convert_time2();

    //9 task
    biggest_number();


    return 0;
}

void product_info(void)
{   
    int item_number;
    float unit_price;
    int month, day, year;


    printf("Enter item number: ");
    scanf("%d", &item_number);
    if(item_number < 0){
        fprintf(stderr, "Item number can't be negative.\n");
        exit(1);
    }
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    if(unit_price < 0 || unit_price > 9999.99){
        fprintf(stderr, "Value of unit price is incorrect.\n");
        exit(1);
    }
    printf("Enter purchase data (mm//dd/yyyy): ");
    scanf("%d/%d/%d",&month, &day, &year);
    if (month > 12 || month < 0 || day < 0 || day > 31 || year < 0 || year > 2100){
        fprintf(stderr, "Date is invalid.\n");
        exit(1);
    }

    printf("Item\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t$%.2f\t\t%d\\%d\\%d\n", item_number,unit_price,month, day,year);
}

void ISBN_separate(void)
{   
    int gsi_prefix, group_identifier,publisher_code, item_number, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_identifier, &publisher_code,\
&item_number, &check_digit);

    printf("GSI prefix: %d\nGroup identifier: %d\nPublisher code: %d\n\
Item number: %d\nCheck digit: %d\n",gsi_prefix, group_identifier, publisher_code,\
item_number, check_digit);
}

void convert_tel_number(void)
{   
    int first_gr, sec_gr, third_gr;

    printf("Enter phone number [(xxx) xxx-xxxx]");
    scanf("(%d) %d-%d", &first_gr, &sec_gr, &third_gr);
    printf("You entered %d.%d.%d\n", first_gr, sec_gr, third_gr);
}

void reverse_dig(void)
{   
    int dig;

    printf("Enter a two-digit number: ");
    scanf("%d", &dig);
    if (dig < 10 || dig > 99){
        fprintf(stderr, "dig should be 9 < dig < 100\n");
        exit(1);
    }

    int leftover = dig % 10;
    int main_part = dig / 10;
    printf("The reversal is: %d%d\n", leftover, main_part);
}

void reverse_3dig(void)
{
    int dig;

    printf("Enter a three-digit number: ");
    scanf("%d", &dig);
    if (dig < 100 || dig > 1000){
        fprintf(stderr, "dig should be 99 < dig < 1000\n");
        exit(1);
    }

    int main_part = dig / 100;
    int mid = (dig % 100) / 10;
    int tail = (dig % 100) %10;
    printf("The reversal is : %d%d%d\n", tail, mid, main_part);
}

void calc_num_digs(void)
{   
    int user_dig,copy, count = 0;

    printf("Enter a number: ");
    scanf("%d", &user_dig);

    copy = user_dig;
    while (copy >= 1){
        ++count;
        copy/=10;
    }

    printf("The number %d has %d digs\n", user_dig, count);
}

void convert_time(void)
{
    int hours, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    printf("Equivalent 12-hour time: ");

    if (hours < 12){
        if (hours < 10){
            if(minutes < 10){
                printf("0%d:0%d am.\n", hours, minutes);
            }
            else{
                printf("0%d:%d am.\n", hours, minutes);
            }
           
        }
        else{
            if(minutes < 10){
                printf("0%d:0%d am.\n", hours, minutes);
            }
            else{
                printf("%d:%d am.\n", hours, minutes);
            }
            
        }
    }
    else if(hours == 12){
        if(minutes < 10){
            printf("12:0%d p.m.\n", minutes);
        }
        else{
            printf("12:%d p.m.\n", minutes);
        }
    }
    else{
        switch (hours)
        {
        case 13:
            printf("1:%d p.m.\n", minutes);
            break;
        case 14:
            printf("2:%d p.m.\n",minutes);
            break;
        case 15:
            printf("3:%d p.m.\n",minutes);
            break;
        case 16:
            printf("4:%d p.m.\n",minutes);
            break;
        case 17:
            printf("5:%d p.m.\n",minutes);
            break;
        case 18:
            printf("6:%d p.m.\n",minutes);
            break;
        case 19:
            printf("7:%d p.m.\n",minutes);
            break;
        case 20:
            printf("8:%d p.m.\n",minutes);
            break;
        case 21:
            printf("9:%d p.m.\n",minutes);
            break;
        case 22:
            printf("10:%d p.m.\n",minutes);
            break;
        case 23:
            printf("11:%d p.m.\n",minutes);
            break;
        case 0:
            printf("12:%d p.m.\n",minutes);
            break;
        
        default:
            printf("Error!\n");
            break;
        }
    }

}

void convert_time2(void)
{
    int hours, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    printf("Equivalent 12-hour time: ");

    if (hours < 12){
        if (hours < 10){
            printf("0%d:", hours);
        }
        else{
            printf("%d:", hours);
        }

        if (minutes < 10){
            printf("0%d a.m.\n", minutes);
        }
        else{
            printf("%d a.m.\n", minutes);
        }
    }
    
    else if(hours == 12){
        printf("12:");

        if (minutes < 10){
           printf("0%d p.m.\n", minutes);
        }
        else{
            printf("%d p.m.\n", minutes);
        }
    }

    else{
        switch (hours)
        {
        case 13:
            printf("1:");
            break;
        case 14:
            printf("2:");
            break;
        case 15:
            printf("3:");
            break;
        case 16:
            printf("4:");
            break;
        case 17:
            printf("5:");
            break;
        case 18:
            printf("6:");
            break;
        case 19:
            printf("7:");
            break;
        case 20:
            printf("8:");
            break;
        case 21:
            printf("9:");
            break;
        case 22:
            printf("10:");
            break;
        case 23:
            printf("11:");
            break;
        case 0:
            printf("12:");
            break;
        default:
            printf("Error!\n");
            break;
        }

        if(minutes < 10){
            printf("0%d p.m.\n", minutes);
        }
        else{
            printf("%d p.m.\n", minutes);
        }
    }
}

int cmp_val(const void *arg1, const void *arg2)
{
    return ( *(float *)arg1 - *(float *)arg2 );
}

void biggest_number(void)
{   
    float buffer[1];

    float *ptr = malloc(sizeof(float));
    if(ptr == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    float number;
    int counter = 0;

    for(;;){
        printf("Enter a number: ");
        scanf("%f", &number);

        *(ptr + counter) = number;
        ++counter;


        ptr = realloc(ptr, (sizeof(ptr) + sizeof(float) * counter));
        if (ptr == NULL){
            fprintf(stderr, "Memory allocation with realloc problem.\n");
            exit(1);
        }

        if(number <= 0){
            break;
        }
    }

    //sorting array and find biggest number
    qsort(ptr, counter, sizeof(float), cmp_val);

    printf("The largets number entered was %.2f\n", *(ptr + (counter - 1)));
    
}