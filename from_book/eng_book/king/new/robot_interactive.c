#include<stdio.h>
#include<stdlib.h>
#include"robot_interactive.h"

#define COMMAND_SORT '0'
#define COMMAND_MAX '1'
#define COMMAND_MIN '2'

char greetings(void)
{
    char user_choice;

    printf("\nWelcome!\n--------\nCommand's menu:\n0 - 'Sort array'\n"
          "1 - 'Find max value'\n2 - 'Find min value'\n");

    printf("Choose one: ");
    user_choice = getchar();

    //validation
    if( user_choice != COMMAND_SORT && user_choice != COMMAND_MAX && user_choice != COMMAND_MIN){
        fprintf(stderr, "Please choose proper command from Menu.\n");
        exit(1);
    }

    return user_choice;
}

char get_type(void)
{
    //getting type
    printf("Please select type of array:\n"
           "short - s, int - i, unsigned - u, float - f, double - d\nChoose one: ");
    
    int type = getchar();

    //validation
    if(type != 's' && type != 'i' && type != 'u' && type != 'f' && type != 'd'){
        fprintf(stderr, "Type error! Undefined type.\n");
        exit(1);
    }

    return type;
}

int get_len(void)
{
    int length;

    printf("Please specify length of the array: ");
    scanf("%d", &length);
    #if defined DEBUG
    printf("Length = %d\n", length);
    #endif

    //validation length
    if ( length < 1 ){
        fprintf(stderr, "Length error. You specifed array with undefined length.\n");
        exit(1);
    }

    return length;
}

void* get_array(char type, int len)
{   
    //char type = get_type();
    //int len = get_len();

    if ( type == 's' ){
        //we work with short type

        //let's allocate memory for array
        short *array = malloc(sizeof(short) * len);

        //let's fill this array

        for(int i = 0; i < len; ++i){
            printf("Enter value #%d: ", i + 1);
            scanf("%hu", array + i);
        }

        //testing

        #if defined DEBUG
        for(int i = 0; i < len; ++i){
            printf("%hu ", *(array + i));
        }
        putchar('\n');
        #endif

        return array;
    }
}