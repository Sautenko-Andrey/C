//bit-fields in structures
#include<stdio.h>
#include<string.h>

#define NAME_LEN 25

typedef unsigned char BYTE;   //1 byte type or 8 bits
typedef unsigned short WORD;  // 2 bytes or 16 bits

union digit {
    int i_val;
    char c_val;
};



struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};

union int_date {
    unsigned short i;    //16 bites
    struct file_date fd;    //16 bites
    
};

struct employee {
    char name[NAME_LEN + 1];
    unsigned int id: 8;   //inteeger can occupy 8 bits maximum
};

struct file_time {
    unsigned int : 5;  //not used
    unsigned int minutes: 6;
    unsigned int hours: 5;
};

struct ranks {
    unsigned int : 0;   //0 - lenght bit-field
    unsigned int xR : 5;
    unsigned int yR : 5;
};

union {
    struct {
        WORD ax, bx, cx, dx;
    } word;

    struct {
        BYTE al, ah, bl, bh, ch, cl, dh, dl;
    } byte;
} regs;

void print_date(unsigned short date);

int main(void)
{   
    struct file_date my_bd;
    my_bd.day = 28;
    my_bd.month = 6;
    my_bd.year = 89;

    struct employee Karl;
    strncpy(Karl.name, "Karl",NAME_LEN);
    Karl.id = 200;

    print_date(6289);

    union digit my_dig;
    my_dig.c_val = 15;
    printf("my_dig = %d\n", my_dig.c_val);

    my_dig.i_val = 30000;
    printf("my_dig = %d\n", my_dig.i_val);


    regs.byte.ah = 0x12;  //18
    regs.byte.al = 0x34;  //52
    printf("AX: %hx\n", regs.word.ax);  //AX: 1234





    return 0;
}

void print_date(unsigned short date)
{
    union int_date user_date;
    user_date.i = date;
    printf("%d/%d/%d\n", user_date.fd.month, user_date.fd.day,user_date.fd.year + 1980);
}