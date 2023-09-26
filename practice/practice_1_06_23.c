#include<stdio.h>
#include<string.h>

#define NAME_SIZE    15
#define SORT_ARRAY    1
#define COPY_ARRAY    2
#define INS_EL    3
#define DEL_EL    4
#define ARR_SIZE    10

void get_name(char name[], int len_name, char surname[], int len_surname);

void show_menu(void);

unsigned int get_choice(void);

void sort_array(int array[], size_t size_array);

void copy_array(int copy[], size_t len_copy, int original[], size_t len_original);

void insert_element_in_array(int array[], size_t len_array, int element, size_t insert_index);

void remove_element_from_array(int array[], size_t len_array, size_t del_index);

void get_array_from_user(int array[]);

int main(void)
{
    //here will be calling some functions
    
    //let's define user's name and surname:
    char user_name[NAME_SIZE];
    char user_surname[NAME_SIZE];

    //get and put name and surname in memory:
    get_name(user_name, NAME_SIZE, user_surname, NAME_SIZE);

    //showing info in console:
    printf("\nUser info :\n--------------\nName : %s\nLast name : %s\n\n", user_name, user_surname);
    
    //showing menu for user:
    show_menu();

    //take from user his choice
    int user_choice = get_choice();
    printf("User pic number of menu - %d\n", user_choice);

    //excuting user's command
    switch (user_choice){
	case SORT_ARRAY :
	    	    
	    int array[100] = {};

	    get_array_from_user(array);
            
	    size_t len_array = sizeof(array) / sizeof(*array);
	    sort_array(array, len_array);
           
	    break;

	default :
	    break;
    }    

    return 0;
}



//scripts


void get_name(char name[], int len_name, char surname[], int len_surname)
{
    printf("Hello! Please, tell us your name: ");
    fgets(name, len_name, stdin);
    name[strlen(name) - 1] = '\0';

    printf("Please, tell us your last name: ");
    fgets(surname, len_surname, stdin);
    surname[strlen(surname) - 1] = '\0';
}

void show_menu(void)
{
    printf("MENU\n***************\n#1 Sort array\n#2 Copy array\n#3 Insert element in array\n#4 Remove element from array\n**************\n");
}

unsigned int get_choice(void)
{
    int user_choice;
    printf("Please pic menu number : ");
    scanf("%d", &user_choice);
    puts("");
    return user_choice;
}

void sort_array(int array[], size_t size_array)
{
    int min_index;
    for (int i = 0; i < size_array - 1; ++i){
        min_index = i;

	for (int j = i + 1; j < size_array; ++j){
	    if(array[min_index] > array[j]){
	        min_index = j;
	    }
	}

	if (min_index != i){
	    int temp = array[i];
	    array[i] = array[min_index];
	    array[min_index] = temp;
	}
    }

    for (int i = 0; i < size_array; ++i){
        printf("%d ", array[i]);
    }
    puts("");
}


void copy_array(int copy[], size_t len_copy, int original[], size_t len_original)
{
    for (int i = 0; i < len_original; ++i){
        copy[i] = original[i];
    }
}

void insert_element_in_array(int array[], size_t len_array, int element, size_t insert_index)
{
    for (int i = len_array - 1; i > insert_index; --i){
        array[i] = array[i - 1];
    }

    array[insert_index] = element;
}

void remove_element_from_array(int array[], size_t len_array, size_t del_index)
{
    for (int i = del_index; i < len_array; ++i){
        array[i] = array[i + 1];
    }
}

void get_array_from_user(int array[])
{
    size_t len_array;
    printf("We should get array from you. Please enter it's size : ");
    scanf("%zu", &len_array);
    puts("");
    
    int value;
    for (int i = 0; i < len_array; ++i){
        printf("enter %d-value : ", i);
	scanf("%d", &value);
	array[i] = value;
	puts("");
    }

    printf("We have received from you this array : ");
    for(int i = 0; i < len_array; ++i){
        printf("%d ", array[i]);
    }

    puts("");

}
