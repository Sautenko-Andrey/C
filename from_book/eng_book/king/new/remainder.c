#include<stdio.h>
#include<string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], size_t nums);

int main(void)
{   
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];

    int day, i, j, num_remind = 0;  //num_remind is a counter of reminders

    //all start with infinity loop
    for(;;){
        //checking if we approach max reminders
        if(num_remind == MAX_REMIND){
            printf("--No space left--\n");
            break;
        }

        //getting day from user
        printf("Enter day and reminder:");
        scanf("%2d", &day); //%2d means read only 2 digs
        if(day == 0){
            break;        //if user puts 0 the loop terminates
        }

        //converting int day into str day_str
        sprintf(day_str, "%2d", day);

        //getting reminder from user
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++){
            if ( strcmp(day_str, reminders[i]) < 0){
                printf("%s --- %s\n", day_str, reminders[i]);
                break;
            }
        }

        for(j = num_remind; j > i; j--){
            strcpy( reminders[j], reminders[j - 1] );
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay reminder\n");
    for(i = 0; i < num_remind; i++){
        printf("%s\n", reminders[i]);
    }

    return 0;
}

int read_line(char str[], size_t nums)
{
    int symbol, i = 0;

    while( (symbol = getchar()) != '\n' ){
        if ( i < nums ){
            str[i++] = symbol;
        }
    }
    str[i] = '\0';

    return i;
}