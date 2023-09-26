//Работа со стандартными потоками
#include<stdio.h>
#include<string.h>

#define MAX 50

void work_getchar(void);
void print_text(void);
void clear_stream(void);


int main(void)
{   
    //ввод строки и немедленный ее вывод
    //char buffer[256];
    //puts(fgets(buffer, sizeof(buffer),stdin));

    //putchar('\n');

    //work_getchar();

    //print_text();

    int age;
    char name[20];
    puts("Enter your age: ");
    scanf("%d", &age);

    //візов очищающей функции
    clear_stream();

    puts("Enter your name: ");
    scanf("%s", name);

    printf("Age : %d\n", age);
    puts(name);

    return 0;
}

void work_getchar(void)
{   
    char symbol;
    while((symbol = getchar()) != '\n'){
        putchar(symbol);
    }
    putchar('\n');
}

void print_text(void)
{
    char buffer[MAX];

    printf("Enter a text:");
    while(1){
        fgets(buffer, MAX, stdin);

        if(buffer[0] == '\n'){
            break;
        }

        buffer[strlen(buffer) - 1] = '\0';

        puts(buffer);
    }
}

void clear_stream(void)
{
    char box[5];
    fgets(box, 5, stdin);
}

