#include<stdio.h>
#include<stdlib.h>

#define MAX 20
#define LEN 20

#define COMMAND_SORT '0'
#define COMMAND_MAX '1'
#define COMMAND_MIN '2'

#define DEBUG
//#define GREETINGS_DEBUG




int read_char(void);
void read_word(char *word, int len);
char greetings(void);
char get_type(void);
int get_len(void);
void* get_array(void);
void type_defin(void *array, char type, int len);


int main(void)
{   
    #if defined GREETINGS_DEBUG
    char user_choice = greetings();
    printf("User has selected command #%c\n", user_choice);
    #endif


    // int my_len;
    // get_array(&my_len);
    // #ifdef DEBUG
    // printf("my_len = %d\n", my_len);
    // #endif

    // int my_len = get_len();
    // printf("my_len = %d\n", my_len);

    short *my_arr = get_array();
    for(int i = 0; i < 10; ++i){
            printf("%hu ", *(my_arr + i));
        }
        putchar('\n');

    free(my_arr);


    return 0;
}

int read_char(void)
{
    int symbol = getchar();
    if (symbol == '\n' || symbol == '\t'){
        return ' ';
    }
    return symbol;
}

void read_word(char *word, int len)
{
    int symbol;
    int position = 0;

    while( (symbol = read_char()) == ' ' ){
        puts("While works!");
        ;
    }
    while ( symbol != ' ' && symbol != EOF ){
        if(position < len){
            word[position++] = symbol;
        }
        symbol = read_char();
    }

    word[position] = '\0';
    puts(word);
}

char greetings(void)
{
    char user_choice;

    printf("\nWelcome!\n--------\nCommand's menu:\n0 - 'Sort array'\n"
          "1 - 'Find max value'\n2 - 'Find min value'\n");

    printf("Choose one: ");
    user_choice = getchar();

    //validation
    if( user_choice != COMMAND_SORT && user_choice != COMMAND_MAX && user_choice != COMMAND_MIN){
        fprintf(stderr, "Command error. Please choose proper command from Menu.\n");
        exit(1);
    }

    return user_choice;
}

// void* get_array(int *len)
// {   
//     int length;
//     char type;

//     printf("Please specify length of the array: ");
//     scanf("%d", &length);
//     #if defined DEBUG
//     printf("Length = %d\n", length);
//     #endif

//     //validation length
//     if ( length < 1 ){
//         fprintf(stderr, "Length error. You specifed array with undefined length.\n");
//         exit(1);
//     }

//     *len = length;

//     //getting type
//     type = get_type();
//     printf("type: %c\n", type);

// }

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

void* get_array(void)
{   
    char type = get_type();
    int len = get_len();

    if ( type == 's' ){
        //we work with short type

        //let's allocate memory for array
        short *array = malloc(sizeof(short) * len);

        //let's fill this array

        for(int i = 0; i < len; ++i){
            printf("Enter value #%d: ", i + 1);
            scanf("%hu", array + i);
        }

        #if defined DEBUG
        for(int i = 0; i < len; ++i){
            printf("%hu ", *(array + i));
        }
        putchar('\n');
        #endif

        return array;
    }
}

void type_defin(void *array, char type, int len)
{
    if (type == 'i'){
        
        for(int i = 0; i < len; ++i){
            printf("%d ", *(int*)(array + i));
        }


    }
}