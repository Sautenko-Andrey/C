//miscellaneous directives   #error

#include<stdio.h>


#define LINUX
#define DEBUG

#define PRINT_INT(x) printf("%d\n", x)

#undef puts
#define puts(str) printf("\t%s\n", str) //we can change standart funcs behavior

int cube(int x);

int main(void)
{   
    #if __INT_MAX__ < 2147483647
    #error int type is too small
    #endif

    printf("INT MAX = %d\n", __INT_MAX__);

    #if defined LINUX
    puts("Woking with Linux");
    #elif defined MAC_OS
    puts("Working witn MAC OS");
    #elif defined WIN
    puts("Working with Windows");
    #else
    #error No operating system specified
    #endif


    

    int some_num = -5;
    int res = cube(some_num);
    PRINT_INT(res);

    #if defined DEBUG && defined PRINT_INT && !defined TEST
    puts("Doing debug with macros PRINT_INT");
    #else
    puts("Doing something else");
    #endif



    return 0;
}

int cube(int x)
{
    return x * x * x;
}