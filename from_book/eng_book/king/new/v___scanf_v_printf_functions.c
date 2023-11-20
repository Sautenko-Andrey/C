//   v..printf and v..scanf functions
#include<stdarg.h>
#include<stdio.h>

int errorf(const char *format, ...);

int main(void)
{   
    // v..printf

    errorf("func error in line %d, %d and %d", 1,2,3);
    errorf("stream error in line %d", __LINE__);

    return 0;
}

int errorf(const char *format, ...)
{
    static int num_errors = 0;
    int n;
    va_list args_list;

    num_errors++;

    fprintf(stderr, "**Error %d:", num_errors);

    va_start(args_list, format);

    n = vfprintf(stderr, format, args_list);
    va_end(args_list);

    fprintf(stderr,"\n");

    return n;
}