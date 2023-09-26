#include<stdio.h>
#include<string.h>
#define PASSWORD    "0999139599_kris@"
#define LOGIN    "Andrey"
void welcome(void)
{
    puts("Hi, there!\nWelcome to employee's app.");
}

int verifying_password(void)
{
    char login[15], password[25];
    printf("Login: ");
    fgets(login, sizeof(login), stdin);
    login[(strlen(login) - 1)] = '\0';

    int counter = 0;
    while (strcmp(password, PASSWORD) != 0){
	printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strlen(password) - 1] = '\0';

	++counter;
	if(counter > 3){
	    printf("%s , you had only three attempts to log in. Unfortunatly, we decided to block your account temporary.\n", login);
	    return 1;
	}
    }

    puts("Password is correct!");
}

void app_menu(void)
{
    puts("");
    puts("MENU");
    puts("--------------");
    puts("1) My taxes.");
    puts("2) My bonuses.");
    puts("3) Exit.");
    puts("--------------");

}

double calc_taxes(void)
{
    double sallary;
    printf("%s , please enter here your sallary pre month: ", LOGIN);
    scanf("%lf", &sallary);
    float tax_rate = 0.20;
    double result = sallary * tax_rate;
    return result;
}

int main(void)
{
    welcome();
    int respond = verifying_password();
    if (respond == 1){
        puts("Good bye!");
	return 1;
    }

    app_menu();

    puts("continue........");
    return 0;
}
