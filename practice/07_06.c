#include<stdio.h>
#include<string.h>
#include<stdarg.h>

#define ATB    0
#define EKO    1
#define VARUS    2
#define SILPO    3
#define NOVUS    4
#define ASHAN    5
#define METRO    6
#define NK    7
#define FOZZY    8


float min_fl_value(float array[], size_t size);
int best_market(float array[], size_t size, float best_price);
void clarify_market(int index);
void copy(float copy[], float orig[], size_t size_orig);
void text_changer(char ptr_text[], size_t size);


int main(void)
{   
    //объявим наши 9 маркетов
    const char *markets[9] = {"atb", "eko", "varus", "silpo", "novus", "ashan", "metro", "nk", "fozzy"};

    //объявим 9 цен на картошку
    float potato_prices[9] = {
        19.99, 21.01, 19.50, 19.00, 18.99, 20.00, 21.55, 21.75, 22.00
        };
    size_t size_potato_prices = sizeof(potato_prices)/sizeof(*potato_prices);

    //сделаем копию неотсортированного массива
    float copy_potato_prices[9];
    copy(copy_potato_prices, potato_prices, size_potato_prices);
    for(int i = 0; i < size_potato_prices; ++i){
        printf("%.2f ", copy_potato_prices[i]);
    }
    puts("");

    //нужно узнать минимальную цену
    float best_price = min_fl_value(potato_prices, size_potato_prices);
    printf("best price must be 18.99, we got : %.2f\n", best_price);

    copy(copy_potato_prices, potato_prices, size_potato_prices);
    for(int i = 0; i < size_potato_prices; ++i){
        printf("%.2f ", copy_potato_prices[i]);
    }
    puts("");

    //узнаем в каком именно маркете минимальная цена
    
    clarify_market(best_market(copy_potato_prices, size_potato_prices, best_price));



    char text[25] = "Andrey";
    size_t size = 15;
    puts(text);
    text_changer(text, size);
    puts(text);

    //printf("%p\n", text);
    //printf("%c\n", *text);

    return 0;
}

//нахождение минимально цены в массиве
float min_fl_value(float array[], size_t size)
{
    int min_index;
    for(int i = 0; i < size - 1; ++i){
        min_index = i;
        for(int j = i + 1; j < size; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }
        if (min_index != i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
    //минимальное значение находится в индексе 0
    return array[0];
}

//определение маркета с минимальной ценой
int best_market(float array[], size_t size, float best_price)
{   
    int atb = 0, eko = 1, varus = 2, silpo = 3, novus = 4,ashan = 5, metro = 6, nk = 7, fozzy = 8;
    int best_index;

    
    for (int i = 0; i < size; ++i){
        if (array[i] == best_price){
            best_index = i;
        }

        if (best_index == atb){
            return best_index;
        }
        else if (best_index == eko){
            return best_index;
        }
        else if (best_index == varus){
            return best_index;
        }
        else if (best_index == silpo){
            return best_index;
        }
        else if (best_index == novus){
            return best_index;
        }
        else if (best_index == ashan){
            return best_index;
        }
        else if (best_index == metro){
            return best_index;
        }
        else if (best_index == nk){
            return best_index;
        }
        else if (best_index == fozzy){
            return best_index;
        }
        else {
            puts("Error!");
        }
    } 
}

void clarify_market(int index)
{
    switch (index)
    {
    case ATB:
        puts("ATB");
        break;
    case EKO:
        puts("EKO");
        break;    
    case VARUS:
        puts("VARUS");
        break;
    case SILPO:
        puts("Silpo");
        break; 
    case NOVUS:
        puts("NOVUS");
        break;  
    case ASHAN:
        puts("Ashan");
        break;  
    case METRO:
        puts("Metro");
        break;
    case NK:
        puts("NK");
        break;  
    case FOZZY:
        puts("Fozzy");
        break;       
    default:
        break;
    }
}

void copy(float copy[], float orig[], size_t size_orig)
{
    for (int i = 0; i < size_orig; ++i){
        copy[i] = orig[i];
    }
}

void text_changer(char ptr_text[], size_t size)
{   
    char surname[] = "Andrey Sautenko";

    /*for (int i = 0; i < size; ++i){
        ptr_text[i] = surname[i];
    }*/
    strncpy(ptr_text,surname,size);

}


