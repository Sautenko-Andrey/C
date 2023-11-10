//Low-level programming

#include<stdio.h>

int main(void)
{   
    //bitwise operators

    //bitwise shift operators
    unsigned short i,j;

    i = 13;         //i is    0000000000001101
    j = i << 2;     // i is now 52    0000000000110100
    j = i >> 2;     //i is now 3    0000000000000011    


    unsigned x, res;
    x = 5;            //0000000000000101

    res = x << 1;   // res = 0000000000001010   = 10
    printf("res = %d\n", res);   //10

    res = x >> 1; //0000000000000010 = 2
    printf("res = %d\n", res);

    unsigned y = 10;   //0000000000001010
    y >>= 3;      //0000000000000001     //1
    printf("y = %d\n", y);
    y <<= 4;      //0000000000010000    //16
    printf("y = %d\n", y);


    //bitwise complement ~  zeros replaced by ones, ones replaced by zeros
    unsigned t = 5; //0000000000000101
    unsigned result_t;
    result_t = ~t;   //1111111111111010   //
    printf("result_t = %u\n", result_t);   //4294967290


    //bitwise and &
    unsigned p = 4;   //0000000000000100
    unsigned a = 3;   //0000000000000011
    unsigned res_p;
    res_p = p & a;    //0000000000000000
    printf("res_p = %u\n", res_p);  //0

    unsigned x2 = 10;   //0000000000001010
    unsigned x3 = 11;   //0000000000001011
    unsigned res_x2_3;
    res_x2_3 = x2 & x3; //0000000000001010  //10
    printf("res_x2_3 = %u\n",res_x2_3);


    //bitwsie exclusive or ^
    unsigned d = 15;        //00001111
    unsigned n = 13;        //00001101
    unsigned res_dn = d ^ n;//00000010  //2
    printf("res_dn = %u\n", res_dn);

    //bitwise inclusive or |
    unsigned c = 10;   //00001010
    unsigned b = 12;   //00001100
    unsigned res_cb = c | b;   //00001110  //14
    printf("res_cb = %u\n", res_cb);



    //with compound assignment operators

    unsigned f = 10;   //1010
    unsigned xf = 2;   //0010

    unsigned f2 = 0xA;  //1010

    printf("%d = %d\n", f, f2);

    f &= xf;  //0010  //2
    printf("f = %d\n", f);

    f =~ f;  //1111111111111101  //4294967293
    printf("f = %u\n", f);

    f = ~f;
    printf("f = %u\n", f); //2

    xf = 5;
    //0010
    //0101
    f |= xf;  //0111 //7

    printf("%u\n", f);


    xf = 10;
    
    //1010
    //0111

    f ^= xf;  //1101  //13
    printf("%u\n", f);



    //Using the bitwise operators to access bits

    //setting a bit
    unsigned short val_i = 0x0000;   //0000000000000000
    printf("val_i = %hu\n", val_i);

    //let's set bit #5
    val_i |= 0x0020;
    printf("%hu\n", val_i);  //32

    //or
    val_i = 0x0000;
    val_i |= 1 << 5;
    printf("%hu\n", val_i); //32


    //we have 
    unsigned rr = 146;
    rr |= 1 << 6;
    printf("%hu\n", rr);  //210

    rr = 0x0092;   //146
    printf("%hu\n", rr);
         //00b2
    rr |= 0x00b2;
    printf("%hu\n", rr);  //178








    return 0;
}