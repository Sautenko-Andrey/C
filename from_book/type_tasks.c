#include<stdio.h>
#include<string.h>
#include<ctype.h>


void phone_number_definer(void);
int* scrabble(void);
int count_vowels(void);
void rewrite_name(void);
double strange_calculator(void);
float average_word(void);
int factorial(void);

int main(void)
{   
    //phone_number_definer();
    //printf("a = %d, z = %d\nA = %d, Z = %d\n", 'a', 'z', 'A', 'Z');
    //int *ptr_sum = scrabble();

    //int res = count_vowels();
    //rewrite_name();
    //strange_calculator();
    //float res = average_word();
    //printf("Average word length = %.1f\n", res);
    //int res = factorial();
    //printf("Res = %d\n", res);


    

    return 0;
}


void phone_number_definer(void)
{
    char phone[100] = {};
    printf("Enter phone number (Uppercase) : ");
    fgets(phone, sizeof(phone),stdin);
    puts(phone);
    for(int i = 0; i < strlen(phone); ++i){
        switch (phone[i])
        {
        case 'A': case 'B': case 'C':
            putchar('2');
            break;
        
        case 'D': case 'E': case 'F':
            putchar('3');
            break;

        case 'G': case 'H': case 'I':
            putchar('4');
            break;

        case 'J': case 'K': case 'L':
            putchar('5');
            break;

        case 'M': case 'N': case 'O':
            putchar('6');
            break;

        case 'P': case 'R': case 'S':
            putchar('7');
            break;

        case 'T': case 'U': case 'V':
            putchar('8');
            break;

        case 'W': case 'X': case 'Y':
            putchar('9');
            break;

        default:
            printf("%c", phone[i]);
            break;
        }
    }
    putchar('\n');
}

int* scrabble(void)
{
    char word[100] = {};
    printf("Enter a word : ");
    fgets(word, sizeof(word), stdin);

    int total_points = 0;
    int *ptr = &total_points;

    for(int i = 0; i < strlen(word) - 1 ; ++i){
        
        /*if(word[i] < 'A' || 'a' > word[i] > 'Z' || word[i] > 'z'){
            puts("Input error!");
            return 0;
        }*/
        if(tolower(word[i])){
            word[i] = toupper(word[i]);
        }

        switch (word[i])
        {
        
        case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U': 
            ++total_points;
            break;
        

        case 'D': case 'G': 
            total_points += 2;
            break;

        case 'B': case 'C': case 'M': case 'P':
            total_points += 3;
            break;
        
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            total_points += 4;
            break;

        case 'K': 
            total_points += 5;
            break;

        case 'J': case 'X': 
            total_points += 8;
            break;

        case 'Q': case 'Z': 
            total_points += 10;
            break;

        default:
        printf("Input error");
            return 0;
        }

    }
    printf("Scrabble value = %d\n", total_points);
    return ptr;
}

int count_vowels(void)
{   
    char text[200] = {};

    printf("Enter a sentence : ");
    fgets(text, sizeof(text), stdin);

    int vowels_total = 0;

    for(int i = 0; i < strlen(text); ++i)
    {   
        if(toupper(text[i])){
            text[i] = tolower(text[i]);
        }

        switch (text[i])
        {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            ++vowels_total;
            break;
        
        default:
            break;
        }
    }

    printf("Your sentence contains %d vowels.\n", vowels_total);

    return vowels_total;
}

void rewrite_name(void)
{   
    char full_name[50] = {};

    printf("Enter a first and a last name : ");
    fgets(full_name, sizeof(full_name), stdin);
    full_name[strlen(full_name) - 1] = '\0';

    int space_index;

    for(int i = 0; i < strlen(full_name); ++i){
        if (full_name[i] == ' '){
            space_index = i;
        }
    }
    for(int i = space_index + 1; i < strlen(full_name); ++i){
        printf("%c", full_name[i]);
    }
    printf(" , %c.\n", full_name[0]);
}

double strange_calculator(void)
{   
    char expression[100] = {};
    printf("Enter an expression : ");
    fgets(expression, sizeof(expression), stdin);
    

    for (int i = 0; i < strlen(expression); ++i){
        switch (expression[i])
        {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            /* code */
            break;
        
        default:
            break;
        }
    }
    return 0;

}

float average_word(void)
{   
    char text[200] = {};
    printf("Enter a sentence : ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    int total_symbols = 0;
    int total_spaces = 0;

    for(int i = 0; i < strlen(text); ++i){
        if(text[i] != ' '){
            ++total_symbols;
        }
        else if(text[i] == ' '){
            ++total_spaces;
        }
        else{
            continue;
        }
    }

    return (float)total_symbols / (total_spaces + 1);
}

int factorial(void)
{   
    int number;
    printf("Enter a positive integer : ");
    scanf("%d", &number);

    while(number < 0){
        printf("Enter a positive integer : ");
        scanf("%d", &number);
    }

    int base = 1;
    for(int i = 1; i <= number; ++i){
        base *= i;
    }
    printf("Factorial of %d = %d\n", number, base);
    return base;
}