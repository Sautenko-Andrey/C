#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

bool test_extension(const char *file_name, const char *extension);
void remove_filename(char *url);

int main(void)
{   
    //task1
    char path[] = "docs.py";
    char ext[] = "PY";

    bool res = test_extension(path, ext);
    printf("%d\n", res);

    //task2
    char url[] = "https://groceryapp.com/index.html";
    puts(url);
    remove_filename(url);
    puts(url);


    return 0;
}

bool test_extension(const char *file_name, const char *extension)
{
    while(*file_name != '.'){
        ++file_name;
    }
    
    bool res = true;

    while(*file_name){
        if(*++file_name != tolower(*extension++)){
            res = false;
        }
    }

    return res;
}

void remove_filename(char *url)
{
    while(*url){
        url++;
    }
    while(*url != '/'){
        url--;
    }
    *url = '\0';
}