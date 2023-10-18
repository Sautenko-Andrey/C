//macros exercises
#include<stdio.h>

#define CUBE(x) ( (x) * (x) * (x) )
#define REMAINDER4(n) ( (n) % 4 )
#define HUNDRED_COND(x,y) ( ( x * y < 100 ) ? 1: 0 )
#define NELEMS(array) ( sizeof(array) / sizeof(*array) )
#define DISP(f,x) ( printf("%s(%d) = %d\n", #f, x, f(x) ))
#define DISP2(f,x,y) ( printf("%s(%d,%d) = %d\n", #f, x, y, f(x,y)))
#define CHECK(x,y,n) ( ((x > 0 && x < (n - 1)) && (y > 0 && x < (n - 1))) ? 1: 0 )
#define MEDIAN(x, y, z) ( ((x) + (y) + (z)) / 3 )
#define POLYNOMIAL(x) ( (3*((x) * (x) * (x) * (x) * (x))) + (2*( (x) * (x) * (x) * (x) )) \
- (5 * ( (x) * (x) * (x) ) ) - ( (x)*(x) ) + 7*(x) - 6 )

#define ERROR(item) ( fprintf(stderr, "Range error: index = %d\n", item) )
#define M2(x,y) #x #y

#define ENGLISH



int main(void)
{   
    //testing CUBE()
    printf("x = %d\n", CUBE(2));

    //testing remainder4()
    printf("remainder = %d\n", REMAINDER4(10));

    //testing HUNDRED_COND()
    printf("return value = %d\n", HUNDRED_COND(23, 4));

    //testing NELEMS()
    int my_array[] = {0,1,2,3,4};
    printf("Elements in array: %ld\n", NELEMS(my_array));

    //testing DISP()
    DISP(CUBE, 3);

    //testing DISP2()
    DISP2(HUNDRED_COND, 33,4);

    //testing CHECK()
    printf("return value = %d\n",CHECK(35,72,28));

    //testing MEDIAN()
    printf("Median value = %d\n",MEDIAN(11,2,37));

    //testing POLYNOMIAL()
    printf("polynimial = %d\n", POLYNOMIAL(3));

    //testing ERROR()
    ERROR(100);

    //testing M2
    puts(M2(ab, cd));

    #if defined ENGLISH
    puts("Insert Disk 1");
    #elif defined FRENCH
    puts("Inserez le disque 1");
    #elif defined SPANISH
    puts("Inserte el disco 1");
    #else
    puts("No mode defined!");
    #endif


    



    return 0;
}