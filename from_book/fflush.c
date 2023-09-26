//Обработка лишних символов с помощью fflush()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void get_n_show_info(void);
void instance_from_book(void);

int main(void)
{   
    //get_n_show_info();

    //instance_from_book();

    printf("%.7s\n","Alex is a pathetic alky.");

    int x = 1, y = 2;
    printf("%*d\n", x, y);

    printf("[%15s]\n", "12345678910");
    
    


    return 0;
}

void get_n_show_info(void)
{
    int age;
    char name[20];

    printf("Enter your age: ");
    //scanf("%d", &age);

    //очистка потока во избежании ошибок
    //fseek(stdin, 0, SEEK_END);    DOESN'T WORK!!!!!!!!!!!!!!!!
    //instead it we use next one
    scanf("%d",&age);
    
    char clear_box[10];
    fgets(clear_box, sizeof(clear_box), stdin);

    while(age < 0 || age > 100){
        printf("Age must be greater then 0 and less then 100. Try one more time!");
        scanf("%d",&age);
        fgets(clear_box, sizeof(clear_box), stdin);
    }

    printf("Enter your name: ");
    scanf("%s", name);
    size_t last_index = strlen(name) - 1;
    if(name[last_index] == '\n'){
        name[last_index] = '\0';
    }

    printf("Your name is %s, and you are %d years old.\n", name, age);
    printf("Clear box consists %s\n", clear_box);
}

void instance_from_book(void)
{
    int age;
    char name[20];

    /* Запрос возраста пользователя. */
    puts("Enter your age.");
    scanf("%d", &age);

    /* Очистка stdin от лишних символов. */
    fflush(stdin);

    /* Запрос имени пользователя. */
    puts("Enter your first name.");
    scanf("%s", name);

    /* Вывод данных. */
    printf("Your age is %d.\n", age);
    printf("Your name is %s.\n", name);
}