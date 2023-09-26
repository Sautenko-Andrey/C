//Массивы указателей
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_strings(char *pointers[], int amount);

int main(void)
{   
    char *strings[3] = {
        "Good morning!",
        "My name is Andrey.",
        "I am C/C++ and Python developer"
    };

    for (int i = 0; i < 3; ++i){
        printf("%s\n", strings[i]);
    }

    //повторение пройденного по указателям и строкам
    char text[20]; ///выделено памяти на 20 сиволов типа char
    char *message; //выделена паямть под хранение адреса указателя, но не под хранения смс
    
    message = text;
    strncpy(text, "She is a doctor.",19);

    puts(message);

    //еще
    char *sms;
    char *my_sms = malloc(sizeof(char) * 50);
    sms = my_sms;

    strncpy(my_sms, "Explicit conversion and implicit conversion.", 50);
    printf("%s\n%s\n", sms, my_sms);

    //еще
    char sentence[] = "I prefer beautiful butts then big knockers.";
    char *pref = sentence;
    puts(pref);
    //конец повторения

    //продолжаем с массивами указателей char
    char *names[3] = {
        "Alex",
        "Max",
        "John"
    };

    printf("Second name : %s\n\n", *(names + 1));
    for(int i = 0; i < sizeof(names) / sizeof(*names); ++i){
        printf("%s\n", *(names + i));
    }

    //еще один пример
    char *full_sentence[10] = {
        "I prefer ",
        "beer then strong alochol, ",
        "but Alex prefers vodka."
    };

    for(int i = 0; i < 3; ++i){
        printf("%s", full_sentence[i]);
    }
    putchar('\n');
    
    //распечатаем строки через ф-ию
    //объявим массив указателей на строки
    char *all_strings[10] = {
        "We are looking forward our victory this year.",
        "That dumb-asses have dedicated all their lives to rotten lie",
        "Frankly we are hopping for their fright elimimnation."
    };

    //печатаем через ф-ию
    print_strings(all_strings, 3);
    


    return 0;
}

void print_strings(char *pointers[], int amount)
{   
    puts("------------------------------------------");
    for(int i = 0; i < amount; ++i){
        printf("%s\n", pointers[i]);
    }
    puts("------------------------------------------");
}