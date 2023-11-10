//Using bitwise operators to access bit-fields

#include<stdio.h>

int main(void)
{   
    //modifying a bit-field
    //store binary value 101 in bits 4-6 of value 
    {
        unsigned value = 112;  //01110000
        value = value & ~0x0070 | 0x0050;
        printf("value = %u\n", value);  //01010000   //80
    }

    //retreaving a bit-field (fetching)
    {
        //retreaving bits 0 - 2
        unsigned value = 15;  //00001111
        unsigned fetched;

        fetched = value & 0x0007;  //111  //7
        printf("value = %u\n", fetched);
    }

    {
        //retreaving bits 4 - 6
        unsigned value = 112;  //01110000
        unsigned fetched;

        fetched = (value >> 4) & 0x0007;  //111   //7
        printf("value = %u\n", fetched);

    }





    return 0;
}