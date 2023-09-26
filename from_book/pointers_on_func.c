//указатели нафункции
#include<stdio.h>
#include<string.h>

int square(int height, int width);
int mul(int x , int y);

//функция , которая рулит
void regulator_func(int type);
//три похожих шаблона фуекций
void first_ten(void);
void first_twenty(void);
void first_thirty(void);

//или
void executor(void (*ptr)(void));

//объявим указатель на функцию
int (*ptr_to_func)(int x, int y);

void print_strings(char *strings[], int num);
void sort_str(char *strings[], int num);
//указатель на функцию
void (*ptr_strings)(char *strings[], int num);

void just_do(int num);



int main(void)
{   
    //присвоим указателю адрес функции square()
    ptr_to_func = square;

    //теперь можно вызывать функцию через указатель
    int res = ptr_to_func(3, 4);
    printf("Sauqre = %d\n", res);

    ptr_to_func = mul;
    int result = ptr_to_func(10,10);
    printf("result = %d\n", result);


    //в зависимости от аргумента функции будет выполняться
    //определенная логика посредством указателя на другие функции
    regulator_func(10);  //печатаем 1 - 10
    regulator_func(20);  //1 -20
    regulator_func(30);  //1 -30

    char *texts[3] = {
        "Kate loves reaing books.",
        "Andrey prefer coding then playing games.",
        "Fransua has been waiting for this woman since he was twelve."
    };

    ptr_strings = print_strings;
    ptr_strings(texts, 3);

    ptr_strings = sort_str;
    ptr_strings(texts, 3);

    ptr_strings = print_strings;
    ptr_strings(texts, 3);


    just_do(10);
    just_do(20);
    just_do(30);



    return 0;
}

int square(int height, int width)
{
    return height * width;
}

int mul(int x , int y)
{   
    return x*y;
}

void regulator_func(int type){
    //объявляем указатель на функцию
    void (*ptr)(void);

    //в зависимости от аргумента будет выполняться разная функция внутри этой функции
    if (type == 10){
        ptr = first_ten;
    }
    else if (type == 20){
        ptr = first_twenty;
    }
    else if(type == 30){
        ptr = first_thirty;
    }
    else{
        puts("Inapropriate argument!");
    }

    //вызываем ф-ию через указатель
    ptr();
}

void first_ten(void)
{
    for(int i = 1; i <= 10; ++i){
        printf("%d ", i);
    }
    putchar('\n');
}

void first_twenty(void)
{
    for(int i = 1; i <= 20; ++i){
        printf("%d ", i);
    }
    putchar('\n');
}

void first_thirty(void)
{
    for(int i = 1; i <= 30; ++i){
        printf("%d ", i);
    }
    putchar('\n');
}

void print_strings(char *strings[], int num)
{
    for(int i = 0; i < num; ++i){
        printf("#%d %s\n", i + 1, strings[i]);
    }
}

void sort_str(char *strings[], int num)
{   
    char *temp;

    for(int i = 0; i < num - 1; ++i){
        for(int j = i + 1; j < num; ++j){
            if(strcmp(strings[i],strings[j]) > 0){
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

void executor(void (*ptr)(void))
{
    ptr();
}

void just_do(int num)
{
    switch (num)
    {
    case 10:
        executor(first_ten);
        break;

    case 20:
        executor(first_twenty);
        break;

    case 30:
        executor(first_thirty);
        break;
    
    default:
    puts("error!");
        break;
    }
}

