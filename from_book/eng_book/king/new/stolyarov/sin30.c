#include<stdio.h>
#include<math.h>


int main(void)
{
    FILE *file;
    int grad;
    
    file = fopen("sin_cos.txt", "wb");
    if(!file){
        perror("sin_cos.txt");
	return 1;
    }

    for( grad = 0; grad < 360; ++grad ){
        double rads, s, c;
	rads = (double)grad * M_PI / 180.0;
	s = sin(rads);
	c = cos(rads);
	fprintf(file, "%03d % 7.5f % 7.5f\n", grad, s, c);
    }

    fclose(file);

    return 0;
}
