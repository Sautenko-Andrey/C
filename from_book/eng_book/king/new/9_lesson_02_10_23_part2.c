//string idioms

#include<stdio.h>
#include<string.h>

//computing length of the string
size_t my_strlen(const char *str);

//copying a string


int main(void)
{   

    //testing my_strlen
    char name[7] = "Andrey";
    size_t len = my_strlen(name);
    printf("Length = %ld\n", len);
    


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