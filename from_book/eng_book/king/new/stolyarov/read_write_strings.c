#include<stdio.h>

#define MAX 50

void string50(FILE *file_1, FILE *file_2);

int main(void)
{

    FILE *orig, *copy;
    orig = fopen("orig_text.txt", "rb");
    if(!orig){
        perror("orig_text.txt");
	return 1;
    }

    copy = fopen("copy_text.txt", "wb");
    if(!copy){
        perror("copy_text.txt");
	return 2;
    }

    string50(orig, copy);

    fclose(orig);
    fclose(copy);

    return 0;
}


void string50(FILE *file_1, FILE *file_2)
{
   char buffer[MAX + 1];
   
   while( (fgets(buffer, sizeof(buffer), file_1)) ){
       int i;
       int nlpos = -1;

       for(i = 0; i < sizeof(buffer) && buffer[i]; ++i){
           if(buffer[i] == '\n'){
	       nlpos = i;
	       break;
	   }
       }

       if(nlpos == -1){
           int c;
	   fputc('\n', file_2);
	   while( (c = fgetc(file_1)) != EOF ){
	       if(c == '\n'){
	           break;
	       }
	   }
       }
       else{
           buffer[nlpos] = '\0';
	   fprintf(file_2, "[%s]\n", buffer);
       }
   } 
}
