#include<stdio.h>

#define BLUE 1    //0001  frist bit
#define GREEN 2   //0010   second bit
#define RED 4     //0100   third bit

int main(void)
{   

    //setting , clearing and testing the BLUE bit

    //testing
    {
        unsigned color = 5;   //   0101
    if ( color & BLUE ){
        puts("THE BLUE bit is on!");
    }
    else{
        puts("THe Blue bit is off!");
    }
    }

    //clearing BLUE bit
    {
        unsigned color = 5; // 0101;
        color &= ~BLUE;
        printf("color = %u\n", color);  //4  0100
    }

    //setting BLUE bit
    {
        unsigned color = 4; // 0100; 
        color |= BLUE;
        printf("color = %u\n", color); //5   0101
    }


    //ops with several bits at time

    //testing BLUE and RED bits  (or)
    {   
        unsigned color = 10;  //1010

        if( color & ( BLUE | RED ) ){
            puts("BLUE AND RED are on!");
        }
        else{
            puts("BLUE AND RED are off!");
        }
    }

    //setting BLUE AND RED bits
    {
        unsigned color = 10;  //1010 
        color |= BLUE | RED;
        printf("color = %u\n", color);  //15    1111
    }

    //clearing BLUE and RED bits
    {
        unsigned color = 15;  //1111
        color &= ~( BLUE | RED );
        printf("color = %u\n", color);   //   10    1010
    }


    return 0;
}