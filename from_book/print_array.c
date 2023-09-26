#include<stdio.h>

void print_int_array(int array[], size_t len_array);
void draw_square(int row, int column);
void display_one_sentence(char text[], size_t len_text);
void menu(void);
void step_3_for(int num);
void step_3_while(int num);
void mul_int(void);
void cube(int *dig);


int main(void)
{   
    int my_array[10] = {1,2,3,4,5,6,7,8,9,10};

    print_int_array(my_array, sizeof(my_array) / sizeof(*my_array));

    draw_square(1,3);

    char my_text[] = "I would like to play beach volleyball.After war i will change all my mindset.";
    display_one_sentence(my_text, sizeof(my_text) / sizeof(*my_text));

    //menu();
    step_3_for(20);

    step_3_while(20);

    mul_int();

    int x = 10;
    printf("x before = %d\n", x);
    cube(&x);
    printf("x after = %d\n", x);
    
    return 0;
}

void print_int_array(int array[], size_t len_array)
{
    for(int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void draw_square(int row, int column)
{
    if(row < 1 || column < 1){
        puts("Argument's error!");
        return;
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            printf("X ");
        }
        putchar('\n');
    }
}

void display_one_sentence(char text[], size_t len_text)
{   
    int i = 0;
    while(text[i] != '.'){
        putchar(text[i]);
        ++i;
    }
    puts(".");
}

void menu(void)
{   
    int user_choice;
    do
    {   
        putchar('\n');
        puts("_______MENU_______");
        printf("#1 Add\n#2 Sub\n#3 Mul\n");
        printf("\n_________________\n");
        scanf("%d", &user_choice);
    } while (user_choice > 3 || user_choice < 1);
    
}

void step_3_for(int num)
{
    for(int i = 0; i < num; i += 3){
        printf("%d ", i);
    }
    putchar('\n');
}

void step_3_while(int num)
{
    int i = 0;
    while(i <= num){
        printf("%d ", i);
        i += 3;
    }
    putchar('\n');
}

void mul_int(void)
{
    int x, y;
    printf("Enter x and y in format (x y) :");
    scanf("%d %d", &x, &y);
    printf("%d\n", x * y);
}

void cube(int *dig)
{
    *dig = *dig * *dig * *dig;
}
