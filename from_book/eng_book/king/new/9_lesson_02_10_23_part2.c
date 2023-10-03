//string idioms

#include<stdio.h>
#include<string.h>

//computing length of the string
size_t my_strlen(const char *str);

//copying a string
char *my_strcat(char *str1, const char *str2);

int main(void)
{   

    //testing my_strlen
    char name[7] = "Andrey";
    size_t len = my_strlen(name);
    printf("Length = %ld\n", len);

    //testing my_strcat
    char text_orig[20] = "Andrey";
    char add_text[] = " Sautenko";
    my_strcat(text_orig, add_text);
    puts(text_orig);
    


    return 0;
}

size_t my_strlen(const char *str)
{
    const char *start = str;

    while(*str){  //just write *str, coz its equal to *str != '\0', coz '\0' == 0
        str++;
    }
    return str - start;   //substracting adresses.
}

char *my_strcat(char *str1, const char *str2)
{
    char *ptr = str1;

    while(*ptr){
        ptr++;
    }

    while(*ptr++ = *str2++){
        ;
    }

    return str1;
}