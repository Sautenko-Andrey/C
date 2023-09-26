#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SYMB    26
#define LENGTH_STR  250
#define NAME_LEN    20


void show_alphabet(void);
char* string_from_keyboard(void);
void string_from_scanf(void);
void diff_data(void);
void copy_array(char original[], char copy[], size_t len_copy);
char* longest_string(char first_str[], char sec_str[]);
char* conc_strings(char first_str[], char sec_str[]);

int main(void)
{   
    /*int *ptr = malloc(sizeof(int) * 10);
    if (ptr == NULL){
        puts("Memory is not allocated. Error!");
        return 1;
    }

    free(ptr);

    //alphabet
    show_alphabet();

    //getting string from keyboard
    char *text = string_from_keyboard();
    puts(text);
    free(text);

    //strings from scanf
    string_from_scanf();

    //diff data
    diff_data(); 


    //let's use copy func
    char text[] = "I am an engineer. Who are you ?";
    char copy_text[18];

    copy_array(text, copy_text, 18);
    puts(copy_text); 

    //longest string
    char str_1[] = "When the football becomes art.";
    char str_2[] = "When the football becomes art.";
    puts(longest_string(str_1, str_2)); */

    //concatenate strings
    char text[] = "I love";
    char club[] = "Arsenal.";
    char *res = conc_strings(text, club);
    puts(res);
    free(res);

    return 0;
}

void show_alphabet(void)
{
    char *ptr = malloc(SYMB * sizeof(char));
    if(ptr == NULL){
        puts("MEMORY ERROR!");
        return;
    }

    char *exec;
    exec = ptr;

    int start = 65, finish = 90;


    for (int i = start; i <=90; ++i){
        *exec++ = i;
    }

    //добавление окончания символа конца строки по последнему адресу
    *exec = '\0';

    //ptr у нас по-прежнему указівает на начало нашей строки . Его и и сопльзуем для печати.
    puts(ptr);

    free(ptr);
}

char* string_from_keyboard(void)
{
    char *ptr = malloc(sizeof(char) * LENGTH_STR);

    printf("Enter text : ");
    fgets(ptr, LENGTH_STR, stdin);

    return ptr;
}

void string_from_scanf(void)
{
    char *ptr1 = malloc(sizeof(char) * LENGTH_STR);
    char *ptr2 = malloc(sizeof(char) * LENGTH_STR);
    char *ptr3 = malloc(sizeof(char) * LENGTH_STR);

    printf("Enter 3 strings : ");
    scanf("%s%s%s", ptr1, ptr2, ptr3);

    //display strings
    puts(ptr1);
    puts(ptr2);
    puts(ptr3);

    free(ptr1);
    free(ptr2);
    free(ptr3);
}

void diff_data(void)
{
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    int id;

    printf("Enter first name, last name and id using spaces beetwen them: ");
    scanf("%s%s%d", first_name, last_name, &id);

    printf("\nUser info\n_________________\n");
    printf("Name : %s\n, Last name : %s\nID : %d\n", first_name, last_name, id);
}

void copy_array(char original[], char copy[], size_t len_copy)
{
    for(int i = 0; i < len_copy - 1; ++i){
        copy[i] = original[i];
    }
    copy[len_copy] = '\0';
}

char* longest_string(char first_str[], char sec_str[])
{   
    char *ptr;

    if(strlen(first_str) > strlen(sec_str)){
        ptr = first_str;
    }
    else if(strlen(first_str) < strlen(sec_str)){
        ptr = sec_str;
    }
    else{
        puts("Strings are equal!");
        ptr = first_str;
    }

    return ptr;
}

char* conc_strings(char first_str[], char sec_str[])
{
    size_t mutual_length = strlen(first_str) + strlen(sec_str) + 1;

    char *ptr = malloc(sizeof(char) * mutual_length);
    char *executor;
    executor = ptr;

    for (int i = 0; i < strlen(first_str); ++i){
        *executor++ = first_str[i];
    }
    *executor = ' ';
    *executor++ = ' ';

    for(int i = 0; i < strlen(sec_str); ++i){
        *executor++ = sec_str[i];
    }
    *executor = '\0';

    return ptr;
}