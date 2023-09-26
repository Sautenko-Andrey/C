/*Коллоквиум.Программа для выплат по займу.

Для работы программы ей необходимы следующие данные:
    - какая сумма взята в долг ;
    - годовой процент;
    - срок займа в месяцах.*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{   
    float cash; //loan value
    float rate; //annual rate
    unsigned loan_duration;  //loan duration in months

    //ввод данных с клавиатуры
    while(1){
        //ввод данных о займе
        printf("Enter the load amount: ");
        scanf("%f", &cash);

        printf("Enter the annual interest rate: ");
        scanf("%f", &rate);

        //приведение процента в удобную для расчетов форму
        rate /= 100;

        //приведение к месячной процентной ставке
        rate /= 12;

        printf("Enter the loan duration in months: ");
        scanf("%u", &loan_duration);

    }

    return 0;
}