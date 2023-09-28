//Practicing pointers with arrays

#include<stdio.h>
#include<string.h>
#include"common.h"
#include<ctype.h>
#include<stdbool.h>

#define SIZE 100
#define NEXT putchar('\n')

void reversal_message(void);
void palindrome_message(void);

int main(void)
{   
    //first task
    //reversal_message();

    //second task
    palindrome_message();


    //clean text
    char text[SIZE] = "I love Python.";
    // puts(text);

    //let's delete spaces
    char new_text[strlen(text) - 1];
    int i,j;
    
    for(i = 0, j = 0; i < strlen(text) - 1; ++i){
        if(text[i] != ' '){
            new_text[j++] = text[i];
        }
    }
    new_text[j] = '\0';

    puts(new_text);

    return 0;
}

void reversal_message(void)
{   
    char buffer[SIZE];
    char *ptr;

    printf("Enter a message: ");
    fgets(buffer,SIZE, stdin);
    
    //reversed version
    ptr = &buffer[strlen(buffer) - 1];

    for(; ptr >= buffer; ptr--){
        printf("%c", *ptr);
    }

    NEXT;
}

void palindrome_message(void)
{   
    char buffer[SIZE];
    char *ptr = buffer;
    bool resp;

    printf("Enter a message: ");
    fgets(buffer, SIZE, stdin);
    buffer[strlen(buffer)] = '\0';
    int middle_index = (strlen(buffer) - 1) / 2;
    char *ptr_last = &buffer[strlen(buffer) - 2];
    int length = strlen(buffer) - 1;

    printf("first = %c\n", *ptr);
    printf("last = %c\n", *ptr_last);
    printf("length = %d\n", length);
    printf("middle index = %d\n", middle_index);

    //deleting weird symbols
    resp = true;
    for(int i = 0; i < middle_index; ++i){


        printf("%c --- %c\n", *(ptr + i), *(ptr_last - i));
        if( *(ptr + i) != *(ptr_last - i) ){
            resp = false;
            break;
        }
    }

    if (resp){
        puts("Palindrome.");
    }
    else{
        puts("Not a palindrome.");
    }
}