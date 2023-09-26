#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME    "Andrey"
#define SIZE    100
#define SECOND_SIZE    50

int main(void)
{
    //отработаем ввод/вывод строк
    char text[SIZE];
    printf("%s , please, enter some text here : ", NAME);
    
    fgets(text, sizeof(text), stdin);

    //уберем символ переноса строки
    text[strlen(text) - 1] = '\0';

    puts(text);

    //отработаем копирование строки
    //задаем новую строку, в которую скопируем введенный пользователем текст
    char text_copy[SIZE];
    strncpy(text_copy, text, SIZE);
    puts(text_copy);

    
    //отработаем слияние двух текстов с помощью strcat и strncat
    //получим второй текст от пользователя
    char second_text[SECOND_SIZE];
    printf("%s, we have to get from you another one text for merging : ", NAME);
    fgets(second_text, SECOND_SIZE, stdin);

    //уберем символ переноса строки
    second_text[strlen(second_text) - 1] = '\0';
    puts(second_text);

    //сначала добавим пробел после первого текста
    strcat(text, " ");
    strcat(second_text, " ");

    //теперь сольем со вторым текстом
    //определим сколько будем добавлять символов в первый текст, чтобы не выйти за пределы массива
    char max_add = sizeof(text) - strlen(text) - 1;

    strncat(text, second_text, max_add);

    puts(text);

    
    //далее отработаем сравнение двух строк strcmp
    if (strcmp(text, second_text) == 0){
        puts("strings text and second_text are equal!");
    }
    else{
        puts("strings text and second_text are different!");
    }

    //проверим текст на сопадение с подстрокой
    if(strncmp(text, "I used to", 9) == 0){
        puts("You've used <I used to> !");
    }


    //поищем симвлы в строке с помощью strchr
    if(strchr(text, 'Z') != NULL){
        puts("You are using prohibited symbol!");
    }
    else{
        puts("Your text is correct.");
    }
    
    //поищем подстроки в строке? к примеру слово fuck
    if (strstr(text, "fuck") != NULL){
        puts("You are using word 'fuck':)");
    }
    else{
        puts("there is no prohibited words here. ");
    }

    //проверим на наличие хотя бы одного подозрительного символа
    char prohibit_symbols[] = "ZV";
    if(strpbrk(text, prohibit_symbols) != 0){
        puts("unfortunatelly u are using bad symbols....");
    }
    else{
        puts("no bad symbols");
    }

    
    //отработка функции sprintf
    size_t size_modern_text = SIZE + 100;
    char *modern_text = malloc(size_modern_text);
    const char format_modern_text[] = "Final text: %s\nWhat we added: %s\n";
    sprintf(modern_text, format_modern_text, text, second_text);
    
    puts(modern_text);

    //возьмем какое-нибудь число у пользователя и преобразим его в строку
    int user_dig;
    printf("%s , please enter any dig what you want : ", NAME);
    scanf("%d", &user_dig);

    //непосредственно преобразование целочисленного числа типа integer в строку
    char str_user_dig[10];
    sprintf(str_user_dig, "%d", user_dig);
    str_user_dig[strlen(str_user_dig) - 1] = '\0';
    puts(str_user_dig);

    //попереводим наоборот из строки в числа
    int int_dig;
    long l_dig;
    long long ll_dig;
    double f_dig;
    char user_digital[10];
    printf("%s,put here string what do you wanna convert into dig:\n ", NAME);
    
    fgets(user_digital, sizeof(user_digital), stdin);
    
    printf("Your string : %s\n", user_digital);
    //уберем символ перевода строки
    user_digital[strlen(user_digital) - 1] = '\0';
    
    //собственно само преобразование
    int_dig = atoi(user_digital);
    l_dig = atol(user_digital);
    ll_dig = atoll(user_digital);
    f_dig = atof(user_digital);

    puts("Результаты преоразований строк в числа приведены ниже");
    printf("int_dig = %d\nl_dig = %ld\nll_dig = %lld\nd_dig = %.2f\n", int_dig, l_dig, ll_dig, f_dig);

    return 0;
}
