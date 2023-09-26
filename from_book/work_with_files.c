//Работа с файлами
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN_FILE_NAME   50
#define LEN_MODE_NAME   4
int main(void)
{   
    //открытие файла
    /*для каждого открываемого файла необходимо объявить указатель на структуру FILE*/
    //объявим указатель на структуру FILE
    FILE *f_ptr;

    //символ, имя файла и режим открытия
    char symbol, filename[LEN_FILE_NAME], mode[LEN_MODE_NAME];

    /*FILE *file_ptr;

    if ( (file_ptr = fopen("data.txt", "r")) != NULL ){
        puts("File is opened!");
        fclose(file_ptr);
    }
    else{
        puts("Error while opening!");
    }*/


    while(1){

        //ввод имени файла и режима открытия
        printf("Enter a filename: ");
        fgets(filename, LEN_FILE_NAME, stdin);
        filename[strlen(filename) - 1] = '\0';

        printf("Enter a mode (max3 characters) : ");
        fgets(mode, LEN_MODE_NAME, stdin);
        mode[strlen(mode) - 1] = '\0';

        //попытка открытия файла
        if ( (f_ptr = fopen(filename, mode)) != NULL ){
            printf("Successful opening %s in mode %s!\n", filename, mode);
            
            //далее закрываем поток
            fclose(f_ptr);

            puts("Enter 'x' to exit, any other to continue : ");
            if ((symbol = getc(stdin)) == 'x'){
                break;
            }
            else{
                continue;
            }
        }
        else{
            //говорим,что произошла ошибка при открытии файла
            fprintf(stderr, "Error opening file %s in mode %s!\n", filename, mode);
            printf("Enter 'x' to exit, any other to try again : ");
            if((symbol =  getc(stdin)) == 'x'){
                break;
            }
            else{
                continue;
            }
        }
    }

    return 0;
}