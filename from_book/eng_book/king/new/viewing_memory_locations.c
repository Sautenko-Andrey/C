//Viewing memory locations

//Allows the user to view regionsof computer memory


#include<ctype.h>
#include<stdio.h>

typedef unsigned char Byte;

int main(void)
{
    unsigned int addr;
    int i, n;
    Byte *ptr;

    printf("Adress of main function: %x\n", (unsigned int)main);
    printf("Adress of addr variable: %x\n", (unsigned int)&addr);

    printf("Enter a hex adress: ");
    scanf("%x", &addr);
    printf("Enter a number of bytes to view: ");
    scanf("%d", &n);

    putchar('\n');

    printf("Address            Bytes            Characters\n");
    printf("-------            -----            ----------");

    ptr = (Byte*)addr;

    for(; n > 0; n-=10){
        printf("%8X ", (unsigned int)ptr);

        for(i = 0; i < 10 && i < n; ++i){
            printf("%.2X ", *(ptr + i));
        }
        for(; i < 10; ++i){
            printf("    ");
        }
        printf(" ");

        for(i = 0; i < 10 && i < n; ++i){
            Byte ch = *(ptr + i);
            if(!isprint(ch)){
                ch = '.';
            }
            printf("%c", ch);
        }

        putchar('\n');
        ptr += 10;
    }

    return 0;
}