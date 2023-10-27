#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SEC 86400

struct {
    double real;
    double imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

struct complex {
    double real;
    double imaginary;
};

struct date {
    int month;
    int day;
    int year;
};

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct color {
    int red;
    int green;
    int blue;
};

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex var_1, struct complex var_2);
int day_of_year(struct date user_date);
int compare_dates(struct date date_1, struct date date_2);
struct time split_time(long total_seconds);
struct color make_color(int red, int green, int blue);
void check_color(int *color);
int getRed(struct color user_color);
bool equal_color(struct color col_1, struct color col_2);
struct color brighter(struct color user_color);
void change_color_to_3(int *color);
void NoGT255(int *color);


int main(void)
{   
    c1 = c2;
    printf("c1 real = %.2f, c1 imaginary = %.2f\n", c1.real, c1.imaginary);

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("c3 real = %.2f, c3 imaginary = %.2f\n", c3.real, c3.imaginary);

    struct complex c_1, c_2, c_3;


    double x = 100.0, pi = 3.14;
    struct complex my_complex_var = make_complex(x,pi);
    printf("x = %.2f, pi = %.2f\n", my_complex_var.real, my_complex_var.imaginary); 


    struct complex x1 = {1.0, 2.0}, x2 = {1.0, 2.0}, res;
    res = add_complex(x1, x2);

    printf("res.real = %.2f, res.imaginary = %.2f\n", res.real, res.imaginary);
    

    struct date some_date = {6, 28, 1989};
    int day = day_of_year(some_date);
    printf("My bday is %d in year\n", day);

    struct date my_bd = {6, 28, 1989};
    struct date her_bd = {7, 15, 1990};

    int date_res = compare_dates(my_bd, her_bd);

    if (date_res = -1){
        puts("My bd i earlier.");
    }
    else if(date_res == 1){
        puts("Her bd is earlier.");
    }
    else{
        puts("Same day!");
    }

    struct time time_x = split_time(85500);
    printf("%.2d:%.2d:%.2d\n", time_x.hours, time_x.minutes, time_x.seconds);

    const struct color MAGENTA = {255, 0, 255};
    const struct color MAGENTA2 = {.red = 255, .blue = 255};
    printf("green = %d\n", MAGENTA2.green);

    struct color my_color = make_color(155, 50, 30);
    printf("my_color = {%d %d %d}\n", my_color.red, my_color.green, my_color.blue);

    struct color color1 = {0, 0, 255}; 
    struct color color2 = {0, 0, 255}; 
    bool comp_res = equal_color(color1, color2);
    if (comp_res){
        puts("Equal");
    }
    else{
        puts("Different.");
    }


    return 0;
}

struct complex make_complex(double real, double imaginary)
{
    struct complex var;

    var.real = real;
    var.imaginary = imaginary;

    return var;
}

struct complex add_complex(struct complex var_1, struct complex var_2)
{
    struct complex add_result;
    add_result.real = var_1.real + var_2.real;
    add_result.imaginary = var_1.imaginary + var_2.imaginary;

    return add_result;
}

int day_of_year(struct date user_date)
{   

    //check date
    if (user_date.month < 1 || user_date.month > 12){
        fprintf(stderr, "Month value error.\n");
        exit(1);
    }
    if (user_date.day < 1 || user_date.day > 31){
        fprintf(stderr, "Day value error.\n");
        exit(1);
    }
    if (user_date.month == 2 && user_date.day > 28){
        fprintf(stderr, "Day value error. Maximum days on February is 28.\n");
        exit(1);
    }


    int jan = 31, feb = 28, mar = 31, apr = 30, may = 31, jun = 30, jul = 31,
    aug = 31, sep = 30, oct = 31, nov = 30, dec = 31;

    switch (user_date.month)
    {
    case 1:
        return user_date.day;
        break;
    case 2:
        return jan + user_date.day;
        break;

    case 3:
        return jan + feb + user_date.day;
        break;

    case 4:
        return jan + feb + mar + user_date.day;
        break;

    case 5:
        return jan + feb + mar + apr + user_date.day;
        break;

    case 6:
        return jan + feb + mar + apr + may + user_date.day;
        break;

    case 7:
        return jan + feb + mar + apr + may + jun + user_date.day;
        break;

    case 8:
        return jan + feb + mar + apr + may + jun + jul + user_date.day;
        break;
    case 9:
        return jan + feb + mar + apr + may + jun + jul + aug + user_date.day;
        break;
    case 10:
        return jan + feb + mar + apr + may + jun + jul + aug + sep + user_date.day;
        break;
    case 11:
        return jan + feb + mar + apr + may + jun + jul + aug + sep + oct + user_date.day;
        break;
    case 12:
        return jan + feb + mar + apr + may + jun + jul + aug + sep + oct + nov + user_date.day;
        break;
    default:
        fprintf(stderr, "Month Error!\n");
        exit(1);
        break;
    }
}

int compare_dates(struct date date_1, struct date date_2)
{
    if (date_1.year < date_2.year){
        return -1;
    }
    else if(date_1.year > date_2.year){
        return 1;
    }
    else{
        if(date_1.month < date_2.month){
            return -1;
        }
        else if(date_1.month > date_2.month){
            return 1;
        }
        else{
            if(date_1.day == date_2.day){
                return 0;
            }
            else if(date_1.day < date_2.day){
                return -1;
            }
            else{
                return 1;
            }
        }
    }
}

struct time split_time(long total_seconds)
{   

    if (total_seconds > MAX_SEC){
        fprintf(stderr, "Value Error! In 24 hours there is only 86400 seconds.\n");
        exit(1);
    }

    struct time regular_time;
    
    int hours = (total_seconds / 60) / 60;
    int minutes = (total_seconds / 60) % 60;
    int seconds = ((total_seconds / 60) % 60 ) /60;

    regular_time.hours = hours;
    regular_time.minutes = minutes;
    regular_time.seconds = seconds;

    return regular_time;
}

void check_color(int *color)
{
    if(*color < 0){
        *color = 0;
    }
    else if(*color > 255){
        *color = 255;
    }
}

struct color make_color(int red, int green, int blue)
{
    check_color(&red);
    check_color(&green);
    check_color(&blue);

    struct color new_color = {.red = red, .green = green, .blue = blue};

    return new_color;
}

int getRed(struct color user_color)
{
    return user_color.red;
}

bool equal_color(struct color col_1, struct color col_2)
{
    if( col_1.red != col_2.red || col_1.green != col_2.green || col_1.blue != col_2.blue ){
        return false;
    }

    return true;
}

void change_color_to_3(int *color)
{
    if (0 < *color < 3){
        *color = 3;
    }
}

void NoGT255(int *color)
{
    if (*color > 255){
        *color = 255;
    }
}

struct color brighter(struct color user_color)
{   
    if (!user_color.red && !user_color.green && !user_color.blue){
        user_color.red = 3;
        user_color.green = 3;
        user_color.blue = 3;
    }

    change_color_to_3(&user_color.red);
    change_color_to_3(&user_color.green);
    change_color_to_3(&user_color.blue);

    user_color.red /= 0.7;
    user_color.green /= 0.7;
    user_color.blue /= 0.7;


    NoGT255(&user_color.red);
    NoGT255(&user_color.green);
    NoGT255(&user_color.blue);

    return user_color;
}