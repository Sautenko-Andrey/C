#include<stdio.h>
#include<stdlib.h>

enum mode {i_mode, d_mode, c_mode};

union arr_pointer {
    int *i_ptr;
    double *d_ptr;
    char *c_ptr;
};

/* Functions delcarations */

void* create_arr(size_t len_arr, enum mode arr_mode);
void display_arr(const void *array, size_t len_arr, enum mode arr_mode);

int main(void)
{   
    size_t nums = 10;    /* set numbers of values in array */
    enum mode user_mode = i_mode;  /* set mode */

    int *array = create_arr(nums, user_mode); /* create array of integers with set numbers */

    display_arr(array, nums, user_mode);  /* display array */

    free(array);

    return 0;
}

void* create_arr(size_t len_arr, enum mode arr_mode)
{	
    union arr_pointer ptr;

    switch(arr_mode){
        
	case i_mode:
            ptr.i_ptr = malloc(sizeof(int) * len_arr);
	    if(ptr.i_ptr == NULL){
	        fprintf(stderr, "Error: memory allocation error for int pointer.\n");
		exit(EXIT_FAILURE);
	    }
	    return ptr.i_ptr;

	case d_mode:
	    ptr.d_ptr = malloc(sizeof(double) * len_arr);
	    if(ptr.d_ptr == NULL){
	        fprintf(stderr, "Error: memeory allocation error for double pointer.\n");
		exit(EXIT_FAILURE);
	    }
	    return ptr.d_ptr;

	case c_mode:
	    ptr.c_ptr = malloc(sizeof(char) * len_arr);
	    if(ptr.c_ptr == NULL){
	        fprintf(stderr, "Error: memory allocation error for char pointer.\n");
		exit(EXIT_FAILURE);
	    }
	    return ptr.c_ptr;
    }

    return NULL;
}

void display_arr(const void *array, size_t len_arr, enum mode arr_mode)
{   
    int i;

    switch(arr_mode){
        case i_mode:
	    for(i = 0; i < len_arr; ++i){
	        printf("%d ", *(int*)(array + i));
	    }
	    putchar('\n');
	    break;

	case d_mode:
	    for(i = 0; i < len_arr; ++i){
	        printf("%.2f ", *(double*)(array + i));
	    }
	    putchar('\n');
	    break;

	case c_mode:
	    for(i = 0; i < len_arr; ++i){
	        printf("%c ", *(char*)(array + i));
	    }
	    putchar('\n');
	    break;
    }
}
