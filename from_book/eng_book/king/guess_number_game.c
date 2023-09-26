#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN 1
#define MAX 100

//external variable
int secret_number;

//prototypes
void init_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);


int main(void)
{   
    char command;

    printf("Guess the secret number between %d and %d:\n", MIN, MAX);

    init_number_generator();

    do
    {
        choose_new_secret_number();
        printf("A new secret number has been chosen.\n");
        read_guesses();
        printf("Play again? (Y/N): ");
        scanf(" %c", &command);
        putchar('\n');

    } while (command == 'Y' || command == 'y');

    return 0;
}

void init_number_generator(void)
{
    srand((unsigned)time(NULL));
}

void choose_new_secret_number(void)
{
    secret_number = rand() % MAX + 1;
}

void read_guesses(void)
{
    int counter = 0, guess;

    for(;;){
        counter++;
        printf("Enter guess: ");
        scanf("%d", &guess);

        if (guess == secret_number){
            printf("You won in %d attemps.\n", counter);
            return;
        }
        else if(guess < secret_number){
            printf("Too low.Try again.\n");
        }
        else{
            printf("Too high.Try again.\n");
        }
    }
}