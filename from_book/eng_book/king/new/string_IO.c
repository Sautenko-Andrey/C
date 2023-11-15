// String I/O

#include<stdlib.h>
#include<stdio.h>

#define DATE_LEN 11
#define NAME_LEN 11

int main(void)
{   
    // Output functions

    char date[DATE_LEN];
    sprintf(date, "%.2d/%.2d/%d", 28, 6, 1989);   //28/06/1989

    puts(date);

    char full_name[NAME_LEN];

    snprintf(full_name, NAME_LEN, "%s %s", "Sautenko", "Andrey");

    puts(full_name);  //Sautenko A


    // Input functions
    char text_from_user[15];
    char first, second;
    printf("Enter some text (maximum 15 letters): ");
    fgets(text_from_user, 15, stdin);
    //extract 2 first bytes
    sscanf(text_from_user, "%c%c", &first, &second);

    printf("first = %c, second = %c\n", first, second);


    char birthday[11];
    int day, month, year;
    printf("Enter date of your BD: ");
    scanf("%.2d/%.2d/%.4d", birthday);

    if ( sscanf(birthday, "%d/%d/%d", &day, &month, &year) == 3){
        printf("Day: %.2d, month: %.2d, year: %d\n", day, month, year);
    }
    else if( sscanf(birthday, "%d-%d-%d", &day, &month, &year) == 3 ){
        printf("Day: %.2d, month: %.2d, year: %d\n", day, month, year);
    }
    else{
        printf("Irrelevant date.\n");
    }


    return 0;
}