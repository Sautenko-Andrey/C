//Практика поиска и сортировки с помощью библиотечных функций qsort() bsearch()
//Сортируем структуры


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define AMOUNT 7

//structs

//let's declare structure of phones book
struct phone_book {
    char *name;
    char phone[13];
};


typedef struct phone_book phones;


//methods for phones book

//for printf
void printf_phones(phones book[], size_t max_size);

//sorting
void sort_phones_byName(phones book[], size_t max_size);

//comparing strings
int comp_contacts_byName(const void *contact_1, const void *contact_2);

//search
phones* search_byName(phones book[], size_t max_size, char *contact_name);



int main(void)
{   
    //declaring and assigning our phone book
    phones tel_books[AMOUNT] =  {
        {"Alex Chausov", "095789465"},
        {"Igor Sidorenko", "0664561232"},
        {"Victoria Nayda", "0678971245"},
        {"Angela Makogon", "0501235478"},
        {"Valeriy Kruglenko", "0633579515"},
        {"Calum Chambers", "0974563214"},
        {"William Saliba", "0992587898"}
    };


    //print our phone book before sorting
    printf_phones(tel_books, AMOUNT);

    //let's sort out phones book
    sort_phones_byName(tel_books, AMOUNT);

    printf("\nAfter sorting:\n\n");

    //let's check out what we have got
    printf_phones(tel_books, AMOUNT);

    //let's search name in book
    //for instance we would seek name "Igor Sidorenko"
    phones *searched_person = search_byName(tel_books, AMOUNT, "Igor Sidorenko");

    //let's check adress and name
    printf("Contact: %s, phone: %s, adress: %p\n",\
searched_person->name, searched_person->phone, &searched_person);

    return 0;
}

void printf_phones(phones book[], size_t max_size)
{
    for ( int i = 0; i < max_size; ++i ){
        printf("#%d Name: %s, tel: %s\n", i + 1, book[i].name, book[i].phone);
    }
}

int comp_contacts_byName(const void *contact_1, const void *contact_2)
{
    //сделаем приведение типов указателей

    return ( strcmp( (*(phones*)contact_1).name, (*(phones*)contact_2).name ) );
}

void sort_phones_byName(phones book[], size_t max_size)
{
    //start sorting
    qsort(book, max_size, sizeof(*book), comp_contacts_byName);
}

phones* search_byName(phones book[], size_t max_size, char *contact_name)
{
    //declare pointers
    phones *ptr = NULL;
    char **key;
    key = &contact_name;

    ptr = bsearch(key, book, max_size, sizeof(*book), comp_contacts_byName);

    if ( ptr == NULL ){
        printf("We didn't find contact %s.\n", contact_name);
        exit(1);
    }
    else {
        printf("We found %s.\n", contact_name);
    }

    return ptr;
}