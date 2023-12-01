#include<stdio.h>

enum modes {int_mode, double_mode};

union temp_var {
    int i_var;
    double d_var;
};

void switch_places(void *x, void *y, enum modes user_mode);

int main()
{
    /* Testing function for int variables */
    int val_1 = 1, val_2 = 99;
    printf("Before: val_1 = %d, val_2 = %d\n", val_1, val_2);
    enum modes user_mode = int_mode;
    switch_places(&val_1, &val_2, user_mode);
    printf("After: val_1 = %d, val_2 = %d\n\n", val_1, val_2);

    /* Testing function for double varables */
    double v1 = 0, v2 = 111;
    printf("Before: v1 = %.2f, v2 = %.2f\n", v1, v2);
    user_mode = double_mode;
    switch_places(&v1, &v2, user_mode);
    printf("After: v1 = %.2f, v2 = %.2f\n\n",v1, v2);


    return 0;
}

void switch_places(void *x, void *y, enum modes user_mode)
{
    union temp_var temp;

    switch(user_mode){

        case int_mode:
            /* Process with integer variables */
	    temp.i_var = *(int*)x;
	    *(int*)x = *(int*)y;
	    *(int*)y = temp.i_var;
	    break;

	case double_mode:
	    /* Process with double variables */
	    temp.d_var = *(double*)x;
	    *(double*)x = *(double*)y;
	    *(double*)y = temp.d_var;
	    break;
    }
}
