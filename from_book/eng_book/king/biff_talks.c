#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define A '4'
#define B '8'
#define E '3'
#define I '1'
#define O '0'
#define S '5'
#define EXL_MARKS "!!!!!!!!!!"
#define MAX 100


int main(void){

    char user_text[MAX];

    printf("Enter message: ");
    fgets(user_text, MAX, stdin);

    user_text[strlen(user_text) - 1] = '\0';
    puts(user_text);

    for(int i = 0; i < MAX; ++i){
        if (tolower(user_text[i])){
            user_text[i] = toupper(user_text[i]);
        }
        switch (user_text[i])
        {
        case 'A':
            user_text[i] = A;
            break;
        case 'B':
            user_text[i] = B;
            break;
        case 'E':
            user_text[i] = E;
            break;
        case 'I':
            user_text[i] = I;
            break;
        case 'O':
            user_text[i] = O;
            break;
        case 'S':
            user_text[i] = S;
            break;
        default:
            break;
        }
    }

    strcat(user_text, EXL_MARKS);

    printf("In B1FF-speak: ");
    puts(user_text);

    return 0;
}