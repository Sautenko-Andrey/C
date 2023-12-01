#include<stdio.h>

#define MAX_LEN 50

void copy_str(char *dest_str, const char *orig_str);
void modern_copy(char *dest_str, const char *orig_str, unsigned num);
int str_len(const char *str);


int main(void)
{   
    /* Testing a regular function */

    char orig_text[] = "Did you check a weather forecast?";
    char copied_text[MAX_LEN];
    
    copy_str(copied_text, orig_text);
    
    puts(copied_text);

    /* Testing a modern function */

    char orig_text_3[] = "What evil lurks ?";
    char copied_text_3[MAX_LEN];

    modern_copy(copied_text_3, orig_text_3, 10);

    puts(copied_text_3);

    return 0;

}

void copy_str(char *dest_str, const char *orig_str)
{
    const char *ptr;

    for(ptr = orig_str; *ptr; ++ptr,++dest_str){
        *dest_str = *ptr;
    }

    *dest_str = '\0';  /* mark array of cahr as string */
}


void modern_copy(char *dest_str, const char *orig_str, unsigned num)
{
    const char *ptr;
    int i;

    for(ptr = orig_str, i = 0; *ptr && i < num; ++ptr, ++dest_str, ++i){
        *dest_str = *ptr;
    }

    *dest_str = '\0';
}

int str_len(const char *str)
{
    const char *ptr;

    for(ptr = str; *ptr; ptr++)
        {}

    return ptr - str;
}
