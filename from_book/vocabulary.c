//РАБОТА СО СТРУКТАРАМИ , СОРТИРОВКА И ПОИСК С ПОМОЩЬЮ БИБЛИОТЕЧНЫХ ФУНКЦИЙ
//ПРИМЕР СО СЛОВАРЕМ


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE    9
#define RESPOND_SIZE 50

//structure
struct vocabulary {
    char *eng;
    char *rus;
};

typedef struct vocabulary vocabulary;

//methods

//for printing
void showALL(vocabulary box[], size_t size);

//studying
void study(vocabulary box[], size_t size, char var);

//check doubbling
int dontRepeat(char *word, vocabulary box[], size_t size, char mode);

void printf_str(vocabulary box[], size_t size);

vocabulary* read_vocabulary(char *file_name, size_t size);

void fill_vocabulary(char *file_name, vocabulary data[]);

int main(void){

    //declearing and assigning structure
    vocabulary translator[SIZE] = {
        {"nerd", "ботаник"},
        {"to attest", "засвидетельствовать"},
        {"designated", "объявленный"},
        {"to taunt", "дразнить"},
        {"sophisticated", "ультрасовременный"},
        {"arrogant", "высокомерный"},
        {"to scoff", "издеваться"},
        {"locksmith", "слесарь"},
        {"sawmill","мельница"}
    };

    //let's print our vocabulary
    //showALL(translator, SIZE);

    //let's try to study
    //study(translator, SIZE, 'e');

    //printf_str(translator, SIZE);

    //vocabulary temp_box[SIZE];

    //int res = dontRepeat("sophisticated", temp_box, SIZE, 'e');

    //open_vocabulary("../../Studying/my_vocabulary3.dat");
    
    fill_vocabulary("vocabulary.txt", translator);
    vocabulary *my_dict = read_vocabulary("vocabulary.txt", SIZE);
    printf("\nMe dictionary:\n\n");
    for (int i = 0; i < SIZE; ++i){
        printf("[%s] --- [%s]\n", my_dict[i].rus, my_dict[i].eng);
    }

    printf("\n\n\n");
    study(my_dict, SIZE, 'e');


    return 0;
}

void showALL(vocabulary box[], size_t size)
{
    for (int i = 0; i < size; ++i){
        printf("%s ---> %s\n", box[i].rus, box[i].eng);
    }
}

void study(vocabulary box[], size_t size, char var)
{   
    char buffer[RESPOND_SIZE];
    int right_answers = 0;
    double rank;
    vocabulary showed[size];


    if ( var != 'e' && var != 'r' ){
        fprintf(stderr, "Incorrect variant.\n");
        exit(1);
    }

    puts("Welcome to our app!");
    puts("Press Enter to start!");
    fgetc(stdin);


    unsigned index_list[size];
    for (int i = 0; i < size; ++i){
        index_list[i] = i;
    }


    if ( var == 'e'){
        for (int i = 0; i < size; ++i){
            srand(time(NULL));
            int index = rand() % size;
            
            //проверка на то, что слово уже попадалось
            int res_check = dontRepeat(box[index].eng, showed, size, 'e');
            if ( res_check == 0 ){
                //puts("Dublicating!");
                //printf("i = %d\n", i);
                --i;
                continue;
            }
            else{
                printf("translate %s --> ", box[index].eng);
                fgets(buffer, sizeof(buffer), stdin);

                showed[i].eng = malloc(sizeof(char) * RESPOND_SIZE);
                strcpy(showed[i].eng, box[index].eng);

                buffer[strlen(buffer) -1] = '\0';

                if (strcmp(buffer, box[index].rus) == 0){
                puts("MAtch!");
                ++right_answers;
                }
                else{
                    puts("Error!");
                }
            } 
        }
    }
    else {
        for (int i = 0; i < size; ++i){
            srand(time(NULL));
            int index = rand() % size;
            
            printf("translate %s --> ", box[index].rus);
            fgets(buffer, sizeof(buffer), stdin);

            showed[i].rus = malloc(sizeof(char) * RESPOND_SIZE);
            strcpy(showed[i].rus, buffer);

            buffer[strlen(buffer) -1] = '\0';

            if (strcmp(buffer, box[index].eng) == 0){
                puts("MAtch!");
                ++right_answers;
            }
            else{
                puts("Error!");
            }
        }
    }

    printf("Right answers: %d\n", right_answers);

    rank = ( (float)right_answers/ (float)size ) * 100;
    printf("Success %.0f ", rank); 
    puts("%");

}

int dontRepeat(char *word, vocabulary box[], size_t size, char mode)
{   
    if ( mode != 'e' && mode != 'r' ){
        fprintf(stderr, "Incorrect type!\n");
        exit(1);
    }


    if ( mode == 'e' ){
        for (int i = 0; i < size; ++i){
            if (box[i].eng == NULL){
                //puts("Empty");
                return 1;
            }
            else {
                //puts("Filled");
                //printf("Start checking : %s --- %s\n", word, box[i].eng);
                if ( strcmp(word, box[i].eng) == 0 ){
                    //puts("We found word!");
                    return 0;
                }
            }
            //puts("in box :");
            //printf("%s\n", box[i].eng);
        }
        return 1;
    }  
}

void printf_str(vocabulary box[], size_t size)
{
    for (int i = 0; i < size; ++i){
        printf("%s\n", box[i].eng);
    }
}

vocabulary* read_vocabulary(char *file_name, size_t size)
{
    FILE *file_ptr;

    vocabulary *data = malloc(sizeof(vocabulary) * size);

    if ( (file_ptr = fopen(file_name, "rb")) == NULL ){
        fprintf(stderr, "Opening file error!\n");
        exit(1);
    }
    else{
        puts("file is opened.");
    }

    //reading data
    if ( fread(data, sizeof(vocabulary), size, file_ptr) != size ){
        fprintf(stderr, "Reading data error.\n");
        exit(1);
    }
    else {
        puts("Data has been read.");
    }

    fclose(file_ptr);

    //showing data
    for (int i = 0; i < SIZE; ++i){
        printf("%s --- %s\n", data[i].eng, data[i].rus);
    }

    return data;
}

void fill_vocabulary(char *file_name, vocabulary data[])
{
    FILE *file_ptr;

    //open file for writing data
    if ( (file_ptr = fopen(file_name, "wb")) == NULL ){
        fprintf(stderr, "Opening file error!\n");
        exit(1);
    }
    else {
        puts("File opened successfully.");
    }

    //start filling file
    if ( fwrite(data, sizeof(vocabulary), SIZE, file_ptr) != SIZE ){
        fprintf(stderr, "Writing data error!\n");
        exit(1);
    }
    else {
        puts("Data has been written.");
    }

    fclose(file_ptr);
}