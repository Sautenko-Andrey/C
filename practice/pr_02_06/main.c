#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "scripts.h"

#define LEN_TEXT    100


int main(void)
{
    //here we can use all our customize functions:

    //let's sort array:
    //user's array:
    int user_array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int length = sizeof(user_array) / sizeof(*user_array);

    //let's show it in console:
    printf("User's array looks now: ");
    for(int i = 0; i < length; ++i){
        printf("%d ", user_array[i]);
    }
    puts("");
    
    //sorting:
    sort_array(user_array, length);

    //let's watch what we got:
    printf("After sorting array looks like: ");
    for(int i = 0; i < length; ++i){
        printf("%d ", user_array[i]);
    }
    puts("");

    //let's make coppy of array:
    int size_copy = 5;
    int my_copy_array[size_copy];

    copy_array(my_copy_array, size_copy, user_array, length);
    //let's watch what we got:
    printf("This is our copy with %d elements: ", size_copy);
    for(int i = 0; i < size_copy; ++i){
        printf("%d ", my_copy_array[i]);
    }
    puts("");

    //let's insert element in array
    int insert_index = 5;
    int element = 100;
    int orig_arr[20] = {1,2,3,4,5,6,7,8,9,10};

    insert_element(orig_arr, 20, element, insert_index);

    //let's watch what we got:
    printf("We've inserted %d in index %d, so we got:  ", element, insert_index);
    for(int i = 0; i < 20; ++i){
        printf("%d ", orig_arr[i]);
    }
    puts("");

    //let's remove element from array
    remove_element(orig_arr, 20, insert_index);

    //let's watch what we got:
    printf("We've removed %d in index %d, so we got:  ", element, insert_index);
    for(int i = 0; i < 20; ++i){
        printf("%d ", orig_arr[i]);
    }
    puts("");


    //let's make text's copy

    char original_text[] = "I am not hungry. Just these food smell delicious.";
    char copy_text[150];
    
    strncpy(copy_text, original_text, strlen(original_text));
    puts(copy_text);

    //let's concatenate two textes
    //first of all we attach space to current text
    strcat(copy_text, " ");

    //we are ready to attach another text
    char another_text[] = "I am missing reading regular books. I am tired because of technicall books.";

    //let's define free space in copy_text
    int free_space = sizeof(copy_text) - strlen(copy_text) - 1;

    strncat(copy_text, another_text, free_space);
    puts(copy_text);

    //let's find symbol in text
    char path[] = "https://groceryapp.com";
    if (strchr(path, 'g') != NULL){
        puts("We found g in text!");
    }
    else{
        puts("Symbol g is not in text!");
    }


    //let's find substring in text
    char sentance[] = "Put this fucking mug on the table!";
    char *ptr = strstr(sentance, "fuck");

    if (ptr!=0){
        puts("fuck is here");
    }
    else{
        puts("clear text.");
    }

    //find substr without pointers
    char login[] = "Andrey";
    if(strstr(login, "dre")!= NULL){
        puts("ok");
    }
    else{
        puts("got a problem.");
    }


    //check spec symbols
    char spec_symbols[] = "!@#$%^&*()_-./";
    char password[] = "Habarovskaya@3496";

    char *pointer = strpbrk(password, spec_symbols);
    if (pointer != NULL){
        puts("symbols are here");
    }
    else{
        puts("no symbols");
    }

    //work with sprintf()
    double apple = 14.99, orange = 34.60, coconut = 100.00;
    char view[100];
    const char format[] = "orange : %.2f uah, apple : %.2f uah, coconut : %.2f uah";
    sprintf(view, format, orange, apple, coconut);
    puts(view);


    //let's convert digs in string
    int x = 100;
    char str_x[20];
    sprintf(str_x, "%d", x);
    puts(str_x);


    //let's convert strings into digs
    int int_res = atoi("1050");
    long int li_res = atol("100000");
    long long int lli_res = atoll("10000007");
    double d_res = atof("999.99");

    printf("int_res = %d\nli_res = %ld\nlli_res = %lld\nd_res = %.2f\n", int_res, li_res, lli_res, d_res);



    //let's use functions with pointers in arguments
    //let's work with employee's sallary
    //calculate his tax
    float emp_salary_before_tax = 30000.00;

    //tax
    float tax = calculate_tax(emp_salary_before_tax);
    printf("Your tax value : %.2f uah\n", tax);

    //clear sallary
    float clear_sallary = calculate_clear_sallary(emp_salary_before_tax);
    printf("Your sallary after tax: %.2f uah\n", clear_sallary);

    //another way
    float sal = 20000.00;
    float res = sallary_operation(sal, calculate_tax);
    printf("res = %.2f\n", res);

    //let's make text low
    char my_text[] = "I love Arsenal FC. AND LET ME TELL YOU SOMETHING ABOUT SPURS...";
    puts(my_text);
    lowercase(my_text);
    puts(my_text);    

    return 0;
}

