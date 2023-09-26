#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME    "Andrey"

//при необходимости можно объявлять функции, которые возвращают указатель
const char* find_space(const char* some_string);

const char* get_string(int length);

void sorting_array(short array[], int size);

void concatenate_strings(char first_str[], char second_str[], int max_add);

const char* get_str(int length)
{
    char user_string[length];
    char *pointer = user_string;
    printf("enter text : ");
    fgets(user_string, length, stdin);
    user_string[strlen(user_string) - 1] = '\0';
    return pointer;
}

int main(void)
{
    //воспользуемся функцией для поиска пробела в строке
    char my_string[] = "I love.";
    const char* res = find_space(my_string);
    printf("res = %p\n", res);

    //отсортируем массив
    short array[] = {10,9,1,6,5,7,2,4,3,8};
    int length = sizeof(array)/sizeof(*array);
    
    printf("Your array before sorting : ");
    for(int i = 0; i < length; ++i){
        printf("%hu ", array[i]);
    }
    puts("");

    sorting_array(array, length);
    printf("Your sorted array : ");
    for(int i = 0; i < length; ++i){
        printf("%hu ", array[i]);
    }
    puts("");



    //объединим две строки
    char text_1[100] = "I love Arsenal";
    char text_2[] = "and hate spurs.";
    int max_add = sizeof(text_1) - strlen(text_1) - 1;

    concatenate_strings(text_1, text_2, max_add);
    puts(text_1);

    //получим текст от пользователя
    const char *text_ptr = get_str(100);
    printf("%p\n", text_ptr);
    printf("%c\n", *text_ptr);
    



    return 0;
}



//all scripts
const char* find_space(const char* some_string)
{
    while(*some_string!='\0'){
        if (*some_string == ' ')
            return some_string;

        some_string++;
    }
}

const char* get_string(int length)
{

    char user_string[length];
    char *ptr = user_string;
    printf("%s , text some string here : ", NAME);
    fgets(user_string, sizeof(user_string), stdin);
    user_string[strlen(user_string) - 1] = '\0';

    return ptr;
}

void sorting_array(short array[], int size)
{
    int min_index;
    
    for (int i = 0; i < size - 1; ++i){
        min_index = i;

	for (int j = i + 1; j < size; ++j){
	    if(array[min_index] > array[j]){
	        min_index = j;
	    }
	}

	if(min_index != i){
	    short temp = array[i];
	    array[i] = array[min_index];
	    array[min_index] = temp;
	}
    }
}

void concatenate_strings(char first_str[], char second_str[], int max_add)
{
    strcat(first_str, " ");
    strncat(first_str, second_str, max_add);
}


