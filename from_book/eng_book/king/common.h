#include<time.h>
//funcs
void execution_time(clock_t begin, clock_t end);
void printf_arr(void *arr, size_t length, char type);
void sort_int(int array[], size_t length);
int comparing_val(const void *val_1, const void *val_2);
void sort_library(int array[], size_t length);
void type_check(char type);
void printf_matrix(void *ptr_matrix, size_t rows, size_t columns, char type);
void memCheck(void *ptr);