#include<stdio.h>

enum {max_length = 25};

#if USE_INDEX_IN_STRING_COPY
void copy_str(char *dest, const char *source, int num)
{
    int i;
    for(i = 0; source[i] && i < num; i++){
        dest[i] = source[i];
    }

    dest[i] = '\0';
}
#else
void copy_str(char *dest, const char *source, int num)
{
    int i;
    for(i = 0; *dest && i < num; dest++, source++, i++){
        *dest = *source;
    }

    *dest = '\0';
}
#endif

int main(void)
{
    char orig[max_length] = "Let's disrupt it!";
    char copy[max_length + 1];
    
    copy_str(copy, orig, max_length);
    
    printf("Orig: %s\nCopy: %s\n",copy, orig ); 


    return 0;
}
