#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct coord
{
    int x;
    int y;
} first_dot, second_dot;

struct rectangle
{
    struct coord topleft;
    struct coord topright;
};

struct coord_3D
{
    int x;
    int y;
    int z;
};

struct current_data
{
    char day;
    char month;
    char year;
};

struct employee
{
    char name[20];
    int id;
};

struct product
{
    int id;
    int amount;
    float price;
};

struct products_set
{
    struct product first_item;
    struct product second_item;
};

struct numbers
{
    int nums[10];
    char values[5];
};

struct new_employee
{
    int id;
    char fname[20];
    char lname[25];
};

typedef struct coord_3D DOT_3D;
typedef struct current_data DATA;
typedef struct employee EMP;
typedef struct rectangle RECT;
typedef struct products_set SET;
typedef struct numbers NUMBERS;
typedef struct new_employee NEW_EMP;


void draw_line_3D(void);
char* new_employee(void);

int main(void)
{   
    struct coord_3D dot_matrix;

    dot_matrix.x = 10;
    dot_matrix.y = 20;
    dot_matrix.z = 123;

    printf("Dot's coordinats:\nx =%d\ny = %d\nz = %d\n", dot_matrix.x, dot_matrix.y, dot_matrix.z);

    struct coord_3D dot_matrix_2;
    //скопируем 
    dot_matrix_2 = dot_matrix;
    printf("Dot's coordinats:\nx =%d\ny = %d\nz = %d\n", dot_matrix_2.x, dot_matrix_2.y, dot_matrix_2.z);

    //draw line
    //draw_line_3D();

    //rectangle
    RECT figure;
    figure.topleft.x = 100;
    figure.topleft.y = 200;
    figure.topright.x = -254;
    figure.topright.y = -1;


    //products set
    SET my_set;
    my_set.first_item.id = 123;
    my_set.first_item.amount = 150;
    my_set.first_item.price = 15.99;
    my_set.second_item.id = 222;
    my_set.second_item.amount = 3;
    my_set.second_item.price = 1034.50;

    //NUMBERS
    NUMBERS my_numbers;
    my_numbers.nums[3] = 17;
    my_numbers.values[1] = -3;

    //let's print this NUMBERS struct
    for(int i = 0; i < 10; ++i){
        printf("%d ", my_numbers.nums[i]);
    }
    putchar('\n');
    for(int i = 0; i < 5; ++i){
        printf("%d ", my_numbers.values[i]);
    }
    putchar('\n');


    return 0;
}

void draw_line_3D(void)
{
    DOT_3D first_dot, sec_dot;
    
    printf("Enter 3 coordinats for the first 3D dot (x, y, z) : ");
    scanf("%d%d%d", &first_dot.x, &first_dot.y, &first_dot.z);

    printf("Enter 3 coordinats for the second 3D dot (x, y, z) : ");
    scanf("%d%d%d", &sec_dot.x, &sec_dot.y, &sec_dot.z);

    printf("\n---------------\n");
    printf("Drawing line from with coordinats (%d, %d, %d) to (%d, %d, %d)\n",\
    first_dot.x, first_dot.y, first_dot.z,sec_dot.x, sec_dot.y, sec_dot.z);
}

char* new_employee(void)
{
    NEW_EMP user;

    printf("Enter id, user name and last name with spaces: ");
    scanf("%d %s %s", &user.id, user.fname, user.lname);

    if(user.id < 0 || user.id > 10000){
        puts("ID error. Innapropriate!");
    }

    puts("User's info:");
    puts(user.fname);
    puts(user.lname);
    printf("%d\n", user.id);

}



