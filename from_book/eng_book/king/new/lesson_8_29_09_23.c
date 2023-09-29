#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 50

char digit_to_hex_char(int digit);
unsigned count_spaces(const char str[]);
unsigned count_spaces2(const char *str);
unsigned count_vowels(const char *str);

int main(void)
{   
    char one_a = "abc"[0];
    printf("a = %c\n", one_a);

    char res = digit_to_hex_char(13);
    printf("res = %c\n", res);


    // char *p = "some text";   WRONG!
    // *p = "another text";
    // puts(p);


    //we need string with 50 charcters
    char some_str[SIZE + 1];   //+1 for \0

    char text_1[7] = "Andrey";
    printf("length = %ld\n", strlen(text_1));   //6


    //array declaration versus pointer declaration
    //array declaration
    char text[7] = "abcdef";
    puts(text);
    //can we change character c to w?
    text[2] = 'w';  
    puts(text);    //yes, we allowed to do it

    //pointer declaration
    char *ptr_text = "abcdef";
    puts(ptr_text);
    // *(ptr_text + 1) = 'w';  we cant do it
    // puts(ptr_text);

    //but can point to another variable
    char mess[10] = "1234";
    ptr_text = mess;

    puts(ptr_text);


    char str[] = "I am a sotware developer and have been coding by Python since 2022.";
    printf("%s\n", str);

    //printing first 7 characters
    printf("%.7s\n", str);

    //or we can nudge it to the right
    printf("%10.7s\n", str);

    // char buffer[11];
    // printf("Enter a text:");
    // fgets(buffer,11,stdin);
    // for (int i = 0; i < 11; ++i){
    //     if(buffer[i] == '\0'){
    //         printf("space");
    //     }
    //     printf("%c\n", buffer[i]);
    // }

    clock_t start = clock();
    unsigned spaces = count_spaces("i love Python.");
    printf("spaces = %u\n", spaces);
    clock_t end = clock();
    printf("%f sec\n",(double)(end - start) / CLOCKS_PER_SEC);

    clock_t start2 = clock();
    unsigned spaces2 = count_spaces2("i love Python.");
    printf("spaces2 = %u\n", spaces2);
    clock_t end2 = clock();
    printf("%f sec\n",(double)(end2 - start2) / CLOCKS_PER_SEC);

    unsigned res_vow = count_vowels("Andrey");
    printf("vowels amount = %u\n", res_vow);

    

    return 0;
}

char digit_to_hex_char(int digit)
{   
    if( digit < 0 || digit > 15 ){
        fprintf(stderr, "Out of range. Use ints from 0 to 15.\n");
        exit(1);

    }

    return "0123456789ABCDEF"[digit];
}

unsigned count_spaces(const char str[])
{
    unsigned counter = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            ++counter;
        }
    }

    return counter;
}

unsigned count_spaces2(const char *str)
{
    unsigned counter = 0;

    while(*(str++) != '\0'){
        if(*str == ' '){
            counter++;
        }
    }
    return counter;
}

unsigned count_vowels(const char *str)
{
    unsigned vowels_amount = 0;

    for(; *(str) != '\0'; str++){
        if(*str == 'A' || *str == 'e' || *str == 'y'){
            vowels_amount++;
        }
    }

    return vowels_amount;
}