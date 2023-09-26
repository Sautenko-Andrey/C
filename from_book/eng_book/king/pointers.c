//POINTERS
#include<stdio.h>
#include<stdlib.h>
#include"common.h"

void price_changer(float *item_price, float new_price);
void* relu(void *value, char type);

int main(void)
{   
    int var_int = 57;
    int *ptr_var_int = &var_int;

    printf("Adress var_int: %p\n", &var_int);
    printf("Adress via ptr: %p\n", ptr_var_int);

    int *x_ptr = NULL;
    printf("Adress x_ptr: %p\n", x_ptr);
    //printf("Value of *x_ptr: %d\n", *x_ptr);

    int x = 2380;
    x_ptr = &x;
    printf("Adress of x: %p\n", &x);
    printf("Adress x_ptr: %p\n", x_ptr);

    (&x == x_ptr) ? puts("Ok") : puts("Problem");

    int some_x = *x_ptr;
    printf("some_x = %d\n", some_x);


    unsigned students = 100;
    unsigned *ptr_students = &students;
    unsigned *ptr_ptr;
    ptr_ptr = ptr_students;

    printf("students: %d\n", students);
    printf("*ptr_students: %d\n", *ptr_students);
    printf("*ptr_ptr: %d\n", *ptr_ptr);

    *ptr_students = 72;
    printf("students: %d\n", students);
    printf("*ptr_students: %d\n", *ptr_students);
    printf("*ptr_ptr: %d\n", *ptr_ptr);

    *ptr_ptr = 1;
    printf("students: %d\n", students);
    printf("*ptr_students: %d\n", *ptr_students);
    printf("*ptr_ptr: %d\n", *ptr_ptr);

    float potato_price = 25.55f;
    float cucumber_price = 19.40f;

    printf("potato: %.2f usd, cucmber: %.2f usd\n", potato_price, cucumber_price);

    price_changer(&potato_price, 23.80);
    price_changer(&cucumber_price, 20.00);
    printf("potato: %.2f usd, cucmber: %.2f usd\n", potato_price, cucumber_price);

    double nod_res = -0.135;
    double *after_relu = relu(&nod_res, 'd');
    printf("%f\n", *after_relu);



    return 0;
}

void price_changer(float *item_price, float new_price)
{
    if(*item_price < 0 || new_price < 0){
        fprintf(stderr, "Price can't be below zero.\n");
        exit(1);
    }

    *item_price = new_price;
}

void* relu(void *value, char type)
{
    type_check(type);

    if (type == 'd'){
        if (*(double*)value < 0){
            return 0;
        }
        else{
            return value;
        }
    }
    else{
        fprintf(stderr, "Use just double.\n");
        exit(1);
    }
}