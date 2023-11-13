//Standart library. <stddef.h>

#include<stddef.h>
#include<stdio.h>

/*
    
    <stddef.h> - объявление часто используемых типов и макросов,
                    не объявляет никаких функций.

                Типы:

                ptrdiff_t - тип для результата вычитания одного указателя из другого

                size_t - тип данных, возвращаемый оператором sizeof

                whar_t - тип данных, позволяющий работать с любым символом (в любой локации)

                Макросы:

                NULL - нулевой указатель

                offsetof(type, member-designator) - вычисляет количество байт между началом
                                                    структуры и обозначенного члена этой 
                                                    же структуры
                                                    type -тип структуры
                                                    memeber-designator - член структуры
                    
    */

struct product {
    char *item_name;           
    unsigned int on_hand;      
    unsigned int price;
};


int main(void)
{   

    //ptrdiff_t
    int x = 100, y = 200;
    int *ptr_x = &x;
    int *ptr_y = &y;

    ptrdiff_t diff = ptr_x - ptr_y;
    printf("diff = %ld\n", diff);    //diff = -1
    
    //offsetof(type, member-designator)
    int bytes_dif1 = offsetof(struct product, item_name);
    printf("Distance = %d bytes\n", bytes_dif1);   //Distance = 0 bytes

    int bytes_dif2 = offsetof(struct product, on_hand);
    printf("Distance = %d bytes\n", bytes_dif2);   //Distance = 8 bytes


    int bytes_dif3 = offsetof(struct product, price);
    printf("Distance = %d bytes\n", bytes_dif3);   //Distance = 12 bytes



    return 0;
}