//Using union to provide multiple views of data


#include<stdio.h>


typedef unsigned char BYTE;    //1 byte   8 bites
typedef unsigned short WORD;   //2 bytes  16 bites


struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};

//viewing a block memory in a two ways
union int_date {
    unsigned short i;
    struct file_date fd;
};

//registers
union {

    struct {
        WORD AX;
        WORD BX;
        WORD CX;
        WORD DX;
    } word;

    struct {
        BYTE AL, AH;
        BYTE BL, BH;
        BYTE CL, CH;
        BYTE DL, DH;
    } byte;
} regs;



void printf_date(unsigned short user_date);


int main(void)
{   

    regs.byte.AH = 0x12;
    regs.byte.AL = 0x34;

    printf("AX = %hx\n", regs.word.AX);   ///AX = 1234


    return 0;
}

void printf_date(unsigned short user_date)
{
    union int_date new_date;
    new_date.i = user_date;

    printf("%d/%d/%d\n", new_date.fd.day, new_date.fd.month, new_date.fd.day);
}