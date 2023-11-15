// Remove and rename files

#include<stdio.h>
#include<stdlib.h>


int main(void)
{   

    //opening file
    FILE *file;
    file = fopen("my_file.txt", "r");
    if(file == NULL){
        fprintf(stderr, "Error: can't open file.\n");
        exit(EXIT_FAILURE);
    }

    /* some operations with file */

    fclose(file);

    //renaming file
    int res_rename = rename("my_file.txt", "new_my_file.txt");
    if(res_rename != 0){
        fprintf(stderr, "File wasn't be renamed\n");
        exit(EXIT_FAILURE);
    }
    else{
        puts("Renamed!");
    }
    

    //deleting file
    int remove_res = remove("new_my_file.txt");
    if(remove_res != 0){
        fprintf(stderr, "File wasn't be deleted\n");
        exit(EXIT_FAILURE);
    }
    else{
        puts("Deleted!");
    }



    return 0;
}