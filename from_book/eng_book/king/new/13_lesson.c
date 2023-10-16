//The preprocessor


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define LOOP for(;;)   #macros of infinity loop //not a good idea

#define MAX(x,y) ( (x) > (y) ) ? (x) : (y)

#define PRINT_INT(x) printf(#x " = %d\n", x)

#define INT_ID(x) i##x

#define GENERIC_MAX(type)        \
type type##_MAX(type x, type y)  \
{                                \
    return ( x > y : x ? y );    \
}

#define ERR "Error!"
#define OK "Nicely!"
#define PTR_CHECK(ptr) ( (!ptr) ? puts(ERR) : puts(OK) )

#define CHECK_MEMORY(ptr){                                                            \
    if(!ptr){                                                                          \
        printf("Memory allocation error in line %d of file %s\n", __LINE__, __FILE__);  \
    }                                                                                    \
    else{                                                                                 \
        puts(OK);                                                                          \
    }                                                                                       \
}

#define JOIN(x,y,z) x##y##z


int main(void)
{   
    int res1 = 100, res2 = 999;

    printf("Biggest is %d\n", MAX(res1, res2));
    
    PRINT_INT(res1);

    int INT_ID(13);  //after preprocessing will be i13

    int *ptr = malloc(sizeof(int) * 10);

    PTR_CHECK(ptr);

    printf("Program was compiled at %s %s\n", __TIME__,__DATE__);

    float *pp = malloc(sizeof(float) * 3);
    CHECK_MEMORY(pp);

    //another way
    assert(pp);

    int f = 7, s = 10;
    assert(s!=0);
    int res = f / s;

    int JOIN(x,1,), JOIN(x,2,), JOIN(x,2,1);

    return 0;
}