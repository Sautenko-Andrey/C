// Error handling

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NDEBUG      //no debugg mode
#include<assert.h>   // detecting possible problems at an early stage

#include<errno.h>



int main(void)
{   
    int positions[10] = {3,7,1,4,8,0,11,15,13,2};
    int i = 3, new_val = 99, i2 = 11;

    assert(0 <= i && i < 10);
    positions[i] = new_val;

    // assert(0 <= i2 && i2 < 10);   will be aborted
    // positions[i2] = new_val;

    char *msg = "Vice versa";
    assert( strcmp(msg, "Vice versa") == 0 );
    puts(msg);



    errno = 0;
    double res = sqrt(100);
    if ( errno != 0 ){
        fprintf(stderr, "sqrt error.program terminated\n");
        if ( errno == EDOM ){
            fprintf(stderr, "Domain error. Argument is outside the function's domain.\n");
        }
        else if( errno == ERANGE ){
            fprintf(stderr, "Range error. Return value is too large.\n");
        }
        exit(EXIT_FAILURE);
    }
    printf("res = %f\n", res);


    errno = 0;
    double x_res = sqrt(10);
    if( errno != 0 ){
        perror("sqrt error");
        exit(EXIT_FAILURE);
    }

    printf("x_res = %.2f\n", x_res);


    errno = 0;
    double pow_res = pow(10.0, 3.0);
    if ( errno != 0 ){
        perror("pow error");
        exit(EXIT_FAILURE);
    }

    printf("pow_res = %.2f\n", pow_res);

    //just printing a text of error
    puts(strerror(ERANGE));  //Numerical result out of range


    


    return 0;
}