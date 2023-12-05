#include<stdio.h>
#include<string.h>
#define MAX_LEN 10

int len(const char *string);
void copy_str(char *dest, const char *source, int num);
int compare_str(const char *string_1, const char *string_2, int nums);
char *find_symbol(const char *string, int symbol);

int main(void)
{
    int res_len;
    res_len = len("12345");

    printf("len = %d\n", res_len);
    
    char my_str[MAX_LEN];
    copy_str(my_str, "abcdef", 6);
    puts(my_str);

    int res = compare_str("12345", "22345", 5);
    if(res){
        puts("Strings are equal.");
    }
    else{
        puts("Strings are different.");
    }

    /*char *symbol = find_symbol("12345", '3');
    printf("Adress of symbol: %p\n", &symbol);*/

    char *res2 = strchr("12345", '3');
    if(res2){
        printf("res = %d\n", *res2);
    }
    
    
    return 0;
}


int len(const char *string)
{
    const char *ptr;

    for(ptr = string; *ptr; ptr++)
        {}
    
    return ptr - string;
}


void copy_str(char *dest, const char *source, int num)
{
    int i;

    for(i = 0; *source && i < num; dest++, source++, i++){
        *dest = *source;
    }

    *dest = '\0';
}


int compare_str(const char *string_1, const char *string_2, int nums)
{
    int i;

    for( i = 0; *string_1 && *string_2 && i < nums; string_1++, string_2++, i++ ){
        if(*string_1 != *string_2){
            return 0;
        }
    }

    return 1;
}


/*char *find_symbol(const char *string, int symbol)
{
    
}*/
