//ДИРЕКТИВЫ #IF #ELIF #ELSE #ENDIF

#include<stdio.h>
#include<stdlib.h>

#define ENG 1

#if ENG == 1
#include"for_england.h"
#elif BRA == 1
#include"for_brasil.h"
#else
#include<time.h>
#endif


int main(void)
{   
    printf_ENG_squad();

    return 0;
}