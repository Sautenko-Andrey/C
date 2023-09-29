//Using strinc C library


#include<stdio.h>
#include<string.h>


int main(void)
{   
    //strcpy
    char alphabet[27];
    //alphabet = "abcdefghijklmnopqrstuvwxyz";  WRONG
    strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");
    puts(alphabet);

    char destination[100];

    strcpy(destination, alphabet);
    puts(destination);

    printf("size 1: %ld\nsize 2: %ld\n", sizeof(alphabet), sizeof(destination));

    //multicopy
    char restriction[5] = "abcd";
    char defin_1[5], defin_2[5];

    strcpy(defin_2, strcpy(defin_1, restriction));
    puts(defin_2);
    puts(defin_1);
    puts(restriction);

    //more safety way is using strncpy
    char r_text[7] = "Andrey";
    char d_text[7];
    strncpy(d_text, r_text, sizeof(d_text));
    puts(d_text); 

    //and more safety way
    char str1[11];
    char str2[15] = "012345678901234";

    strncpy(str1, str2, sizeof(str1) -1);
    puts(str1);



    //strlen
    char nums[11] = "0123456789";
    printf("len = %ld\n", strlen(nums));   //len = 10 not 11! doesn't include '\0'


    //strcat
    char sent[10];
    strncpy(sent, "abcd", sizeof(sent) - 1);
    strcat(sent, "efghi");
    puts(sent);

    //a more safety way
    char name[16];
    strncpy(name, "Andrey ", sizeof(name) - 1);
    strncat(name, "Sautenko", sizeof(name) - strlen(name) - 1);
    puts(name);


    return 0;
}