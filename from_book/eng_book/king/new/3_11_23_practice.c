/*Отработка связанных списков и qsort*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 20
#define MAX_SCORES 5

struct user {
    char name[MAX_LEN + 1];
    int id;
    char mail[MAX_LEN];
    int scores[MAX_SCORES];
    struct user *next;
};

void add_user(struct user **data_base, char *new_name, int new_id, char *new_mail, int scores[]);
void show_data(struct user *data);
int cmp_int(const void *x, const void *y);


int main(void)
{   
    int scores_1[5] = {3,2,4,1,5};

    //lets declare our users database
    struct user *data = NULL;
    add_user(&data, "alex213", 123, "alex@gmail.com", scores_1);
    add_user(&data, "ginger__@", 413, "kddsjf@gmail.com", scores_1);
    add_user(&data, "nivk001", 78, "kfjf83jf@gmail.com", scores_1);
    add_user(&data, "A_aats", 88, "wefwk2342@gmail.com", scores_1);
    add_user(&data, "jj190", 1000, "23424fwef@gmail.com", scores_1);
    show_data(data);

    struct user *ptr;
    for(ptr = data; ptr != NULL; ptr = ptr->next){
        qsort(ptr->scores, MAX_SCORES, sizeof(int), cmp_int);
    }

    //checking result
    printf("scores\n===========\n");
    for(ptr = data; ptr != NULL; ptr = ptr->next){
        
        for(int i = 0; i < MAX_SCORES; ++i){
            printf("%d ", ptr->scores[i]);
        }
        putchar('\n');
    }


    

    return 0;
}

void add_user(struct user **data_base, char *new_name, int new_id, char *new_mail, int scores[])
{
    struct user *new_person = malloc(sizeof(struct user));

    if (new_person == NULL){
        fprintf(stderr, "Error: memory allocation error in add_user()\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_person->name, new_name);
    new_person->id = new_id;
    strcpy(new_person->mail, new_mail);

    new_person->next = *data_base;
    *data_base = new_person;
}

void show_data(struct user *data)
{
    struct user *ptr;

    printf("Name\t\t\tID  Mail\nScores\n");
    puts("-------------------------------------------------");
    for(ptr = data; ptr != NULL; ptr = ptr->next)
    {
        printf("%-15s\t%10d  %-25s\n", ptr->name, ptr->id, ptr->mail);
    }
}

int cmp_int(const void *x, const void *y)
{
    return ( *(int *)x - *(int *)y );
}