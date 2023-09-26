#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 100

void init_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{   
    char command;
    int secret_number;

    printf("Guess the secret number: ");
    init_number_generator();
    do
    {
        secret_number = new_secret_number();
        printf("A new secret number has been chosen.\n");
        read_guesses(secret_number);
        printf("Play again (Y/N) ?");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'Y' || command == 'y');
    

    return 0;
}

void init_number_generator(void)
{
    srand((unsigned)time(NULL));
}

int new_secret_number(void)
{
    return rand() % MAX + 1;
}

void read_guesses(int secret_number)
{
    int guess, num_guesses = 0;

    for(;;){
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if(guess == secret_number){
            printf("You done with %d attmpts.\n", num_guesses);
            return;
        }
        else if(guess > secret_number){
            puts("Too high. Try again.");
        }
        else{
            puts("Too low. Try again.");
        }
    }
}