#ifndef __SCRIPTS_H__
#define __SCRIPTS_H__


void sort_array(int array[], int size_array);
void copy_array(int copy_array[], int size_copy, int orig_array[], int size_orig);
void insert_element(int array[], int size_array, int element, int insert_index);
void remove_element(int array[], int size_array, int remove_index);
float calculate_tax(float sallary);
float calculate_clear_sallary(float sallary);
float sallary_operation(float sallary, float(*operation)(float));
void lowercase(char text[]);

#endif
