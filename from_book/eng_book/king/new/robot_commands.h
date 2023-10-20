#ifndef ROBOT_COMMANDS_H
#define ROBOT_COMMANDS_H


/*
    sort_array: Sorts any digital array
*/

void sort_array(void *array, char type, int len);

/*
    find_max: Finds maximum value in the any digital array,
              end returns it.
*/

void* find_max(void *array, char type, int len);

/*
    find_min: Finds minimum value in the any digital array,
              end returns it.
*/

void* find_min(void *array, char type, int len);

#endif