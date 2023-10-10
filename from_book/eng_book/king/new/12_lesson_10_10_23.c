#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int read_line(char strp[], size_t num);
int counts_spaces(char str[]);
int counts_spacesV2(const char *str);
int counts_spacesV3(const char *str);

//customs standatr functions
int my_strlen(const char *str);
int my_strlenV2(const char *str);
char* my_strcat(char *str_1, const char *str_2);
char* my_strcatV2(char *str_1, const char *str_2);

int main(void)
{   
    //counting spaces in the text
    char text[] = "Arsenal beat Man City yesterday.";
    int spaces = counts_spaces(text);
    printf("Spaces in sentence: %d\n", spaces);

    int spaces2 = counts_spacesV2(text);
    printf("Spaces in sentence: %d\n", spaces2);

    int spaces3 = counts_spacesV3(text);
    printf("Spaces in sentence: %d\n", spaces3);

    //testing strcpy
    char dest_text[100];
    char my_msg[] = "You've got a mail!";
    char *ptr = strcpy(dest_text, my_msg);
    puts(ptr);
    puts(dest_text);

    //testing strncpy
    char inbox[21];
    char msg[] = "Thanks for applying!!!!!";   //got more than 20 characters
    strncpy(inbox, msg, sizeof(inbox) - 1);
    inbox[sizeof(inbox) - 1] = '\0';
    puts(inbox);

    //testing strlen
    char sms[100] = "This is simple message.";
    int len = strlen(sms);
    printf("Len = %d symbols\n", len);  //23 symbols, not 100

    //testing strcat
    char name[] = "Bukayo";
    char last_name[] = "Saka";
    char *full_name = strcat(strcat(name, " "), last_name);
    puts(name);
    puts(full_name);

    //testing strncat
    char first_snt[50] = "The weather is nippy today.";
    char sec_snt[] = "You should put on a hat.";
    char *ptr_overall = strncat(first_snt, sec_snt, sizeof(first_snt) - strlen(first_snt) - 1);
    puts(ptr_overall);
    puts(first_snt);

    //testing strcmp
    char first[] = "12345";
    char second[] = "123456";
    int res = strcmp(first, second);
    if (res == 0){
        puts("Strings are equal.");
    }
    else if(res > 0){
        puts("First > Second.");
    }
    else if(res < 0){
        puts("First < Second.");
    }

    //testing my_strlen()
    char some_text[] = "12345";
    int length = my_strlen(some_text);
    printf("Length: %d\n", length);

    //testing my_strlenV2()
    int len2 = my_strlenV2(some_text);
    printf("Length: %d\n", len2);

    //testing my_strcat()
    char f_str[] = "12345";
    char s_str[] = "6789";
    my_strcat(f_str, s_str);
    puts(f_str);

    return 0;
}

int read_line(char strp[], size_t num)
{
    int symb, i = 0;

    while( (symb = getchar()) != '\n' ){
        if (i < num){
            strp[i++] = symb;
        }
    }
    strp[i] = '\0';

    return i;
}

int counts_spaces(char str[])
{   
    int spaces = 0;

    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] == ' '){
            ++spaces;
        }
    }

    return spaces;
}

int counts_spacesV2(const char *str)
{
    int spaces = 0;

    while(*str++){
        if(*str == ' '){
            ++spaces;
        }
    }

    return spaces;
}

int counts_spacesV3(const char *str)
{
    int spaces = 0;

    for(; *str != '\0'; ++str){
        if (*str == ' '){
            ++spaces;
        }
    }

    return spaces;
}

int my_strlen(const char *str)
{   
    int counter = 0;

    while(*str++){
        ++counter;
    }

    return counter;
}

int my_strlenV2(const char *str)
{
    const char *ptr = str;

    while(*str){
        str++;
    }

    return str - ptr;
}

char* my_strcat(char *str_1, const char *str_2)
{
    char *ptr = str_1;
    while(*ptr != '\0'){
        ptr++;
    }
    
    while(*str_2 != '\0'){
        *ptr = *str_2;
        ptr++;
        str_2++;
    }
    *ptr = '\0';

    return str_1;
}

char* my_strcatV2(char *str_1, const char *str_2)
{
    char *ptr = str_1;

    while(*ptr){
        ++ptr;
    }
    while(*ptr++ = *str_2++){
        ;
    }
    return str_1;
}