#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

#define ROBOT_JOEY  "Joey"
#define SORT_ARRAY  1
#define CALCULATOR  2
#define COPY_ARRAY  3

#define SUM     1
#define SUB     2
#define MULT    3
#define DEV     4

void robot_intro(char user_name[], int length);
int menu(void);
void sort_array(int array[], size_t size_array);
int sum(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int dev(int x , int y);
int calculator(int x, int y, int (*action)(int,int));
int * get_array(int array[], int size);
int * copy_array(int orig[], int size_orig);
void executor(int choice);

int main(void)
{
    //getting name
    char name[15];
    robot_intro(name, sizeof(name));

    //getting user's choice
    int choice = menu();

    //execute user's command
    executor(choice);
    
    return 0;
}

//scripts

void robot_intro(char user_name[], int length)
{
    printf("Hi there! I am a robot and my name is %s .\n", ROBOT_JOEY);
    puts("I can execute your commands!");
    printf("Tell your name : ");
    fgets(user_name, length, stdin);
    user_name[strlen(user_name) - 1] = '\0';
    printf("Pleasure to meet you %s !\n", user_name);
    printf("This is what can I do for you. Pick one!\n");
}

int menu(void)
{
    printf("-----------------------\nMENU\n-------------------------\n");
    printf("#1 Sort array\n#2 Calculator\n#3 Copy array\n--------------------------\n");
    int user_choice;
    printf("Choose command : ");
    scanf("%d", &user_choice);
    puts(" ");
    return user_choice;

}

void sort_array(int array[], size_t size_array)
{
    int min_index;
    for(int i = 0; i < size_array - 1; ++i){
        min_index = i;

        for(int j = i + 1; j < size_array; ++j){
            if(array[min_index] > array[j]){
                min_index = j;
            }
        }

        if(min_index!=i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int sum(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

int mult(int x, int y)
{
    return x*y;
}

int dev(int x , int y)
{
    return (float)x /y;
}

//overall calculator
int calculator(int x, int y, int (*action)(int,int))
{
    return action(x,y);
}

int * get_array(int array[], int size)
{   
    int value;
    for(int i = 0; i < size; ++i){
        printf("enter value for element #%d : ", i + 1);
        scanf("%d", &value);
        array[i] = value;
    }
    puts("");
    return array;
}

int * copy_array(int orig[], int size_orig)
{
    int copy[size_orig];
    for(int i = 0; i < size_orig; ++i){
        copy[i] = orig[i];
    }

    return copy;
}

void executor(int choice)
{
    switch (choice)
    {
    case SORT_ARRAY:
        int array[10];
        int size = sizeof(array)/sizeof(*array);
        
        //sorting
        sort_array(get_array(array,size), size);

        //show results
        for(int i = 0; i < size; ++i){
            printf("%d ", array[i]);
        }
        puts("");
        break;

    case CALCULATOR:
        
        int x, y, res, opearation;
        
        printf("enter x : ");
        scanf("%d", &x);
        puts("");
        printf("enter y : ");
        scanf("%d", &y);
        puts("");

        printf("operation : ");
        scanf("%d", &opearation);
        
        if(opearation == 1){
            res = calculator(x, y, sum);
            printf("%d + %d = %d\n", x, y, res);
        }
        else if (opearation == 2){
            res = calculator(x,y,sub);
            printf("%d - %d = %d\n", x, y, res);
        }
        else if (opearation == 3){
            res = calculator(x,y,mult);
            printf("%d * %d = %d\n", x, y, res);
        }
        else if (opearation == 4){
            res = calculator(x,y,dev);
            printf("%d / %d = %d\n", x, y, res);
        }

    case COPY_ARRAY:
        int orig[10] = {1,2,3,4,5};
        int size = sizeof(orig)/sizeof(*orig);

        
        


        



        
    default:
        puts("good bye!");
        break;
    }
}

