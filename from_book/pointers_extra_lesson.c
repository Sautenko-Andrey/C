//Дополнительные сведенья об указателях
#include<stdio.h>

int main(void)
{
    //declaring variable and pointer for it
    int value = 100;

    int *ptr_value = &value;

    //declare a new pointer on pointer ptr_value
    int **ptr_ptr_value = &ptr_value; 

    //let's adjust variable via ptr_ptr_value
    //now value = 100
    printf("value via pointer = %d\n", *ptr_value);
    //or
    printf("direct value = %d\n", value);

    **ptr_ptr_value = -50;
    
    //and after this value has changed
    printf("new value  = %d\n", value);
    //or
    printf("value via ptr_ptr_value = %d\n", **ptr_ptr_value); //note ** before pointer's name
    //or
    printf("value via ptr_value  = %d\n", *ptr_value);



    /*Указатели на многомерные массивы*/
    //declearing multiple array
    int matrix[2][4] = {
        {1,2,3,4},
        {5,6,7,8}
    };

    //let's display pointer's adresses
    printf("matrix = %d\n", matrix);
    printf("matrix[0] = %d\n", matrix[0]);
    printf("matrix[0][0] = %d\n", &matrix[0][0]);

    //let's watch sizes
    printf("size of matrix = %d bytes\n", sizeof(matrix));
    printf("size of matrix[0] = %d bytes\n", sizeof(matrix[0]));
    printf("size of matrix[0][0] = %d bytes\n", sizeof(matrix[0][0]));

    //with adress ariphmetic
    printf("the adress of matrix = %d\n", matrix);
    printf("the adress of matrix + 1 = %d\n", matrix + 1);
    printf("the adress of matrix[1] = %d\n", &matrix[1]);

    //let's print value of matrix[0][0]
    printf("first value = %d\n", **matrix);
    //or
    printf("first value = %d\n", *matrix[0]);
    //or
    printf("first value = %d\n", matrix[0][0]);


    //declare value-pointer on matrix
    int (*ptr_matrix)[4];   //єто указатель на массив

    //ptr follows first value in matrix
    ptr_matrix = matrix;
    
    return 0;
}