//ИАНИПУЛИРОВАНИЕ БЛОКАМИ ПАМЯТИ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define LEN 10
#define MAX 100

void memCheck(void *ptr);

char* use_memset(void);
char* use_memcpy(void);
void* use_memmove(void);


int main(void)
{   
    //ИНИЦИАЛИЗАЦИЯ ПАМЯТИ С ПОМОЩЬЮ memset() - делает все байты выделенного блока
    //памяти равными одному значению
    char* my_set = use_memset();
    for(int i = 0; i < LEN; ++i){
        printf("%c ", *(my_set + i));    //A A A A A A A A A A
    }
    putchar('\n');

    //КОПИРОВАНИЕ БЛОКОВ ПАМЯТИ С ПОМОЩЬЮ memcpy()
    char *block_R = use_memcpy();
    for(int i = 0; i < LEN; ++i){
        printf("%c ", *(block_R++));     //R R R R R R R R R R 
    }
    putchar('\n');


    //ПЕРЕМЕЩЕНИЕ БЛОКОВ ПАМЯТИ С ПОМОЩЬЮ memmove()
    int *my_arr = use_memmove();
    for(int i = 0; i < LEN; ++i){
        printf("%d ", *(my_arr++));
    }
    putchar('\n');

    //еще пример
    char text[11] = "0123456789";
    char copy_text[11];
    memmove(copy_text, text, strlen(text));
    puts(copy_text);

    //еще
    char symb[11] = "0123456789";
    char buffer[11];
    strcpy(buffer, symb);
    puts(buffer);
    //перемещаем блоки памяти
    memmove(buffer + 2, buffer +1, 2);
    puts(buffer);


    return 0;
}

char* use_memset(void)
{   
    unsigned amount = LEN;
    char spec_symbol = 'A';

    //let's allocate memory
    char *ptr = calloc(amount, sizeof(char));

    memCheck(ptr);
    
    //call memset
    memset(ptr, spec_symbol, amount);

    return ptr;
}

char* use_memcpy(void)
{   
    const unsigned size = LEN;

    //allocate memory
    char *ptr = calloc(size, sizeof(char));
    memCheck(ptr);

    //initialize all bytes with symbol R
    memset(ptr, 'R', size);

    //copy memory block
    //before it allocate new memory block
    char *ptr2 = calloc(size, sizeof(char));
    memCheck(ptr2);

    //copying
    memcpy(ptr2, ptr, size);

    return ptr2;
}

void* use_memmove(void)
{
    int *block_1 = malloc(sizeof(int) * LEN);
    memCheck(block_1);

    //fill block

    for(int i = 0; i < LEN; ++i){
        srand(time(NULL));
        int value = rand() % MAX;
        *(block_1 + i) = value;
    }

    
    //memory allocation for second block
    int *block_2 = malloc(sizeof(int) * LEN);
    memCheck(block_2);

    for(int i = 0; i < LEN; ++i){
        printf("%d [%ld] ___ %d [%ld]\n", *(block_1 + i), block_1 + i,*(block_2 + i), block_2 + i);
    }

    //memory move
    //memmove(block_2, block_1, LEN);
    memmove(block_2, block_1, LEN);
    printf("\n\n");
    for (int i = 0; i < LEN; ++i){
        printf("%d [%ld]\n", *(block_2 + i), block_2 + i);
    }

    return block_2;
}

void memCheck(void *ptr)
{
    if (ptr == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
}