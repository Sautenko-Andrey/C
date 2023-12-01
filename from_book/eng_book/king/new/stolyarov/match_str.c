#include<stdio.h>


int compare_str(const char *orig_str, const char *user_str);

int main(void)
{
    char orig_text[] = "World, hold on!";

    return 0;
}


int compare_str(const char *orig_str, const char *user_str)
{
    if(!*orig_str || !*user_str){
        return 0;                   /* detect an empty string */
    }

    for(; *orig_str && *user_str; ++orig_str, ++user_str){
        /* some action here */
    }
}
