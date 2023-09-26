//Перенаправление ввода-вывода
#include<stdio.h>


void send_message_to_file(void);

int main(void)
{   
    send_message_to_file();

    return 0;
}

void send_message_to_file(void)
{   
    char text[51];
    printf("Message: ");
    fgets(text, sizeof(text), stdin);

    printf("Your message:\n%s\n", text);
}