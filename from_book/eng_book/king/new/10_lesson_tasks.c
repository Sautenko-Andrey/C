#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *capitalizeV1(char str[]);
char *capitalizeV2(char *str);
void build_index_url(const char *domain, char *index_url);

int main(void)
{   
    char text[] = "I am feeling headache today...";
    capitalizeV1(text);
    puts(text);

    char text2[] = "Let's take a brief intermission.";
    capitalizeV2(text2);
    puts(text2);


    //building url
    char domain_name[] = "groceryapp";
    char result_url[51];
    build_index_url(domain_name, result_url);
    puts(result_url);
    


    return 0;
}

char *capitalizeV1(char str[])
{
    for(int i = 0; str[i] != '\0'; ++i){
        str[i] = toupper(str[i]);
    }

    return str;
}

char *capitalizeV2(char *str)
{
    // while(*str++){
    //     *str = toupper(*str);
    // }
    while( *str++ = toupper(*str) ){
        ;
    }

    return str;
}

void build_index_url(const char *domain, char *index_url)
{
    char start_url[] = "https://";
    char end_url[] = "/index.html";

    //strcpy(index_url,strcat(start_url, domain));
    
    
}