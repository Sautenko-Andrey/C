//ДИРЕКТИВЫ ПРЕПРОЦЕССОРА
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define ZALUPA printf

//get a half of the value
#define HALFOF(value) ( (value) / 2 )

//get average of the five values
#define AVG5(a,b,c,d,e) ( ( (a) + (b) + (c) + (d) + (e) ) / 5 )

//get larger value
#define LARGER(x, y) ( ((x) > (y)) ? (x) : (y) )

//comparing strings
#define EQUAL_STR(x, y) ( strncmp((x),(y),strlen(y)) )

#define OUT(text) printf(#text)

#define NEXT putchar('\n');


int main(void)
{   
    //let's use macros HALFOF
    int res = HALFOF(10);
    printf("%d\n", res);    //5

    int dig = 100;
    int res2 = HALFOF(dig);
    printf("%d\n", res2);   //50

    short dig3 = 12;
    short res_s = HALFOF(dig3);
    printf("%d\n", res_s);        //6

    double res_avg = AVG5(12,21,13,44,57);
    printf("%f\n", res_avg);  //29

    int greater_value = LARGER(5,7);
    printf("%d\n", greater_value);    //7

    char my_name[] = "Andrey";
    int res_eq = EQUAL_STR("Andrey", my_name);
    printf("%d\n", res_eq);

    OUT("Football has occypied my mind");
    putchar('\n');

    NEXT;
    NEXT;
    NEXT;
    OUT("lallalalala");
    NEXT;

    return 0;
}