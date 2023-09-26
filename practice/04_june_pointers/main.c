#include<stdio.h>
#include<stdlib.h>


void change_side(int *ptr_x, int *ptr_y);


int main(void)
{
    int first = 100;
    int second = 200;

    printf("First = %d\nSecond = %d\n", first, second);

    //change values
    change_side(&first, &second);
    
    //show result
    printf("First = %d\nSecond = %d\n", first, second);


    puts("-------------------------------------------");
    putchar('\n');

    //work with pointers

    float beer_price = 20.00f;
    float *ptr_beer = &beer_price;

    printf("ptr_beer = %p\n*ptr_beer = %.2f\n", ptr_beer, *ptr_beer);


    //объявим еще один указатель и присвоим ему значение указателя ptr_beer
    float another_beer;
    float *ptr_another_beer = &another_beer;
    
    printf("ptr_another_beer = %p\n*ptr_another_beer = %.2f\n", ptr_another_beer, *ptr_another_beer);
    *ptr_another_beer = *ptr_beer;
    printf("ptr_another_beer = %p\n*ptr_another_beer = %.2f\n", ptr_another_beer, *ptr_another_beer);

    //изменим значение указателя ptr_beer
    *ptr_beer = 100.00f;
    //посмотрим теперь на поведение указателся ptr_another_beer
    printf("ptr_another_beer = %p\n*ptr_another_beer = %.2f\n", ptr_another_beer, *ptr_another_beer);

    printf("*ptr_beer = %.2f , *ptr_another_beer = %.2f\n", *ptr_beer, *ptr_another_beer);

    //объявим массив
    int marks[10] = {1,2,3,4,5};
    printf("marks[7] = %d\n", marks[7]);

    marks[0] = 100;
    printf("marks[0] = %d\n", marks[0]);

    //объявим указатель на функцию
    void (*func_ptr)(int *, int *);
    func_ptr = change_side;

    int a = 333;
    int b = 777;

    func_ptr(&a,&b);
    printf("a = %d, b = %d\n", a, b);


    return 0;
}

void change_side(int *ptr_x, int *ptr_y)
{
    int temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
}

