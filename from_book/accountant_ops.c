#include<stdio.h>

char get_command(void);
float pure_sallary(void);
float bonus(void);
void infinite_loop(void);

int main(void)
{   
    char command = get_command();

    switch (command)
    {
    case 0:
        puts("Good bye!");
        break;

    case 1:
        float res = pure_sallary();
        printf("You pure sallary is %.2f usd\n", res);
        break;

    case 2:
        float user_bonus = bonus();
        printf("Your bonus is %.2f usd\n", user_bonus);
        break;
    case 3:
        infinite_loop();
        break;
    }

    return 0;
}


//scripts
char get_command(void)
{   
    const char start = 0;
    const char finish = 3;
    char user_command;

    puts("Hi, there! Please pic a command below.");
    printf("____MENU____\n#1 Calculate sallary after taxes\n#2 Calculate annual bonus\n#4 Infinite loop\n");
    printf("#0 Exit\n");
    printf("----------------------------------\n");

    scanf("%hhd", &user_command);
    while(user_command < start || user_command > finish){
        printf("Menu error! only 0,1,2,3 are available.\n");
        scanf("%hhd", &user_command);
    }

    return user_command;
}

float pure_sallary(void)
{
    float gunt_sallary;
    float tax = 0.2;

    printf("Enter you overall sallary: ");
    scanf("%f", &gunt_sallary);
    while(gunt_sallary < 0){
        printf("Sallary must be greater then 0 : ");
        scanf("%f", &gunt_sallary); 
    }

    return gunt_sallary - (gunt_sallary * tax); 
}

float bonus(void){

    float sallary, bonus_rate = 0.15;
    printf("Enter you sallary after taxes : ");
    scanf("%f", &sallary);

    while(sallary < 0){
       printf("Sallary must be greater then 0 : ");
        scanf("%f", &sallary); 
    }

    return sallary * bonus_rate;
}

void infinite_loop(void)
{   
    long counter = 1;

    for(;;){
        printf("This is infinite loop! I show it %ld time(s)\n", counter);
        counter += 1;
    }
}