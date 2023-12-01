#include<stdio.h>


int len_str(const char *text);
int len_str_V2(const char *text);
int len_str_V3(const char *text);
int wrong_func(const char *text);

int main(void)
{
    int len;
    char text[] = "12345";

    len = len_str(text);
    printf("Length = %d\n", len);

    len = len_str_V2(text);
    printf("Lebgth 2 = %d\n", len);

    len = len_str_V3(text);
    printf("Lebgth 3 = %d\n", len);

    len = wrong_func(text);
    printf("Wrong res = %d\n", len);  /* returns wrong result */


    return 0;
}

int len_str(const char *text)
{
    int i;
    i = 0;

    while(text[i] != '\0'){
        i++;
    }

    return i;
}

int len_str_V2(const char *text)
{
    int i;
    
    for(i = 0; text[i]; ++i)
        {}   

    return i; 
}

int len_str_V3(const char *text)
{
    const char *ptr;

    for(ptr = text;*ptr;ptr++)
        {}
    
    return ptr - text;
}

int wrong_func(const char *text)
{
    const char *ptr = text;
    while(*ptr++);           /* side effect in condition! */

    return ptr - text;
}
