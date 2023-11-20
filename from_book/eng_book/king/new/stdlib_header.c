// stdlib header: generall utilities
// tets C89 numeric vonversion functions

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

#define CHECK_VALID printf( "    %s        %s\n",\
                           errno != ERANGE ? "Yes": "No",\
                           *ptr == '\0' ? "Yes":"No")


int main(int argc, char *argv[])
{   
    char *ptr;

    if(argc != 2){
        printf("usage: <function name> <string>\n");
        exit(EXIT_FAILURE);
    }

    printf("Function    Return value\n");
    printf("--------    ------------\n");
    printf("atof        %g\n", atof(argv[1]));
    printf("atoi        %d\n", atoi(argv[1]));
    printf("atol        %ld\n\n", atol(argv[1]));

    printf("Function  Return Value  Valid?  String Consumed?\n"
          "--------  ------------   ------  -----------------\n");
    
    errno = 0;
    printf("strtod  %-12g", strtod(argv[1], &ptr));
    CHECK_VALID;

    errno = 0;
    printf("strtol  %-12ld", strtol(argv[1], &ptr, 10));
    CHECK_VALID;

    errno = 0;
    printf("strtoul  %-12lu", strtol(argv[1], &ptr, 10));
    CHECK_VALID;

    return 0;
}