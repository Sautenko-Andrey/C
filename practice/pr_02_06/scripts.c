//all scripts what i might use

#include<string.h>
#include<stdlib.h>


//sorting array
void sort_array(int array[], int size_array)
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
}

//copying array
void copy_array(int copy_array[], int size_copy, int orig_array[], int size_orig)
{
    for (int i = 0; i < size_copy; ++i){
        copy_array[i] = orig_array[i];
    }
}

//insert element in array
void insert_element(int array[], int size_array, int element, int insert_index)
{
    for (int i = size_array - 1; i > insert_index; --i){
        array[i] = array[i - 1];
    }
    
    array[insert_index] = element;
}

//remove element from array
void remove_element(int array[], int size_array, int remove_index)
{
    for (int i = remove_index; i < size_array; ++i){
        array[i] = array[i + 1];
    }
}

//calculate tax

float calculate_tax(float sallary)
{
    return sallary * 0.2;
}

//calculate clear sallary

float calculate_clear_sallary(float sallary)
{
    return sallary - (sallary * 0.2);
}

//define pointer which arrow to the function

float sallary_operation(float sallary, float(*operation)(float))
{
    return operation(sallary);
}

//scripts wich work with strings

void lowercase(char text[])
{
    int length_text = strlen(text);
    char *ptr = text;

    char upper_symb[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_symb[] = "abcdefghijklmnopqrstuvwxyz";

    const char *upper_ptr = upper_symb;
    const char *lower_ptr = lower_symb;

    for(int i = 0; i < length_text; ++i){
        for (int j = 0; j < sizeof(upper_symb) / sizeof(*upper_symb); ++j){
	    if (ptr[i] == upper_ptr[j]){
	        ptr[i] = lower_ptr[j];
	    }
	}
    }

}

















