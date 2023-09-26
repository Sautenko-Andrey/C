#include<stdio.h>
#include<string.h>
#include<ctype.h>

void show_symbols_numbers(void);
void show_symbol(char number);
void all_acii_symbols(void);
void name_in_num(char name[], size_t len_name);
void detail_view_string(char string[], size_t len_string);
void upperA(char text[]);


int main(void)
{   
    char names[][25] = {
        "Andrey",
        "Alex",
        "Kate",
        "Segey"
    };

    size_t length = sizeof(names) / sizeof(*names);

    for(int i = 0; i < length; ++i){
        puts(names[i]);
    }

    //let's watch ASCII codes
    show_symbols_numbers();

    //let's chek ascii symbols
    char value = 97;
    printf("As a symbol = %c, as a number = %d\n", value, value);

    //using show_symbol()
    show_symbol(100);

    //let's see all ascii symbols
    all_acii_symbols();


    //name_in_num()
    name_in_num("Andrey", 6);

    puts("");


    //using detail_view_string()
    detail_view_string("Andrey", 7);

    //using upperA()
    char some_text[] = "I love Arsenal.";
    puts(some_text);
    upperA(some_text);
    puts(some_text);

    

    return 0;
}

void show_symbols_numbers(void)
{   
    char start_symbol = 'a';
    char len_alphabet = 25;
    for(int i = 0; i <= len_alphabet; ++i){
        printf("%d ",start_symbol++);
    }
    putchar('\n');

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < strlen(alphabet); ++i){
        alphabet[i] = tolower(alphabet[i]);
        printf("%d ",alphabet[i]);
    }
    putchar('\n');
}
//65 90
//97 122
void show_symbol(char number)
{
    if(65 > number > 90 && 97 > number > 122){
        puts("Incorrcet input!");
        return;
    }

    printf("%c\n", number);
}

void all_acii_symbols(void)
{
    char start = 180, finish = 204;
    for(int i = start; i < finish; ++i){
        printf("%c ", start++);
    }
    putchar('\n');
}

void name_in_num(char name[], size_t len_name)
{
    for(int i = 0; i < len_name; ++i){
        printf("%d ", name[i]);
    }
}

void detail_view_string(char string[], size_t len_string)
{
    for(int i = 0; i < len_string; ++i){
        
        printf("%c\n", string[i]);
    }
    putchar('\n');
}


void upperA(char text[])
{
    char *ptr = text;
    for(int i = 0; i < strlen(text); ++i){
        switch (*(ptr + i))
        {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            *(ptr + i) = toupper(*(ptr + i));
            break;
        
        case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
            *(ptr + i) = tolower(*(ptr + i));
            break;

        default:
            break;
        }
    }
}
