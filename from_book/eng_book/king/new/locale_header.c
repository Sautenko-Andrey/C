#include<locale.h>
#include<stdio.h>
#include<stdlib.h>



int main(void)
{   
    //getting current locale
    char *curr_locale = setlocale(LC_ALL, NULL);

    printf("Current locale: %s\n", curr_locale);    //Current locale: C

    //changing settings using for another locale
    char *new_locale = setlocale(LC_ALL, "swedish");

    printf("New locale: %s\n", new_locale);    //New locale: swedish



    // calling localeconv function
    struct lconv *locale_info = localeconv();

    printf("Decimal point: %s\n", locale_info->decimal_point);   //Decimal point: ,
    printf("Currency symbol in Sweden: %s\n", locale_info->currency_symbol);   //Currency symbol in Sweden: kr


    // changing locale to Japan
    char *jpn_locale = setlocale(LC_ALL, "jp");   // doesn't work
    if (jpn_locale == NULL){
        fprintf(stderr, "Can't change locale to Japan.\n");
        exit(EXIT_FAILURE);
    }

    

    return 0;
}