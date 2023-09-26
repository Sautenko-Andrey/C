#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    puts("Hello, world!");

    //let's check size of type char
    char x;
    printf("%ld byte\n", sizeof(x));

    //short
    short y;
    printf("%ld byte\n", sizeof(y));

    //int
    int t;
    printf("%ld byte\n", sizeof(t));

    //long
    long int q;
    printf("%ld bytes\n", sizeof(q));

    //long long
    long long int e;
    printf("%ld bytes\n", sizeof(e));

    //float
    float f;
    double d;
    long double ld;
    printf("float = %ld bytes\ndouble = %ld bytes\nlong double = %ld bytes\n", sizeof(f), sizeof(d),sizeof(ld));


    int first = 100;
    int second = 999;

    int *ptr_f = &first;
    int *ptr_s = &second;

    int temp = *ptr_f;
    *ptr_f = *ptr_s;
    *ptr_s = temp;

    
    printf("First = %d\nSecond = %d\n", first, second);


    return EXIT_SUCCESS;
}
