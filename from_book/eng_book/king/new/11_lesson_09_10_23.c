#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STR_LEN 50

void build_url(const char *domain, char *index_url);
char* build_url_advance(const char *domain);
int read_line(char str[], size_t len);

int main(void)
{   
    printf("My name is Arsene Wenger."
            "I am a former Arsenal manager."
            "It was a a long journey for about 24 years.\n");

    char name2[] = "Andrey";
    name2[0] = 'a';
    puts(name2);
    putchar('\n');

    char fio[29];
    char name[7] = "Andrey";
    char last_name[9] = "Sautenko";
    char dad_name[13] = "Evgeniyovich";

    strcpy(fio, last_name);
    strcat(strcat(strcat(strcat(fio, " "), name)," "),dad_name);
    puts(fio);
    putchar('\n');


    char full_url[52];
    char *ptr = full_url;
    const char *domain = "groceryapp";
    char start[9] = "https://";
    char end[12] = "/index.html";

    strcpy(full_url, start);
    puts(full_url);
    strcat(full_url, domain);
    puts(full_url);
    strcat(full_url, end);
    puts(full_url);
    puts(ptr);

    char endpoint[STR_LEN + 1];
    build_url("football.ua", endpoint);
    puts(endpoint);

    putchar('\n');

    char *endpoint2 = build_url_advance("groceryapp.com");
    puts(endpoint2);
    free(endpoint2);

    char *pp;
    char club[] = "Arsenal";
    char city[] = "London";
    char manager[] = "Mikel Arteta";
    pp = club;
    puts(pp);
    pp = city;
    puts(pp);
    pp = manager;
    puts(pp);

    pp = "abcdef";
    puts(pp);

    //testing read_line
    char my_name[10];
    printf("Enter your name: ");
    read_line(my_name, 9);
    puts(my_name);
    

    return 0;
}

void build_url(const char *domain, char *index_url)
{
    strcat(strcat(strcpy(index_url, "https://"), domain),"/index.html");
}

char* build_url_advance(const char *domain)
{   
    char start[] = "https://";
    char end[] = "/index.html";

    size_t length = strlen(domain);
    char *ptr = malloc(sizeof(char) * length + sizeof(start) + sizeof(end));

    strcat(strcat(strcpy(ptr, start), domain), end);

    return ptr;
}

int read_line(char str[], size_t len)
{
    int symbol, i = 0;
    while( (symbol = getchar()) != '\n'){
        if(i < len){
            str[i++] = symbol;
        }
    }
    str[i] = '\0';

    return i;
}