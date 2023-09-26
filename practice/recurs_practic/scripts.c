#include<stdio.h>
#include<string.h>


//fir
void drawing_fir(unsigned short layers)
{
    //printf("%hu\n", layers);
    if(layers > 0){
        drawing_fir(layers - 1);    	    
    }
    printf("%hu\n", layers);

}
